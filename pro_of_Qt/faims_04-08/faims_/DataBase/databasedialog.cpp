#include "databasedialog.h"
#include "ui_databasedialog.h"
#include <QDebug>
DataBaseDialog::DataBaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBaseDialog)
{
    ui->setupUi(this);

    showMaximized();

    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    ui->pushButton_out->setFocus();

    //布局优化
    ui->Layout_tabWidget->setMargin(0);
    ui->Layout_functionArea->setStretch(1,4);
    //初始化按钮菜单项
    initBtnMenu();
    //treeWidget
    ui->treeWidget->setHeaderHidden(true);
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    root->setText(0, "FAIMS");
    ui->treeWidget->setItemExpanded(root, true);

    QTreeWidgetItem *Spectrogram = new QTreeWidgetItem(root);
    Spectrogram->setText(0, "Spectrogram");

    //谱图管理表mode
    spectrogramRelationMode = new SpectrogramRelationMode(this);

    //treeView
    //列宽
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中模式为选中行
    //数据
    ui->tableView->setModel(spectrogramRelationMode);
}

DataBaseDialog::~DataBaseDialog()
{
    delete ui;
}

void DataBaseDialog::updateShow()
{
    //更新显示
    spectrogramRelationMode->updateShow();
}

void DataBaseDialog::initTreeWidget()
{
    //隐藏表头
    ui->treeWidget->setHeaderHidden(false);

    //根节点
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    root->setText(0, tr("FAIMS数据库"));
    ui->treeWidget->addTopLevelItem(root);
    ui->treeWidget->setItemExpanded(root, true); //根结点默认展开

    //管理表节点

}

//数据导出
void DataBaseDialog::on_pushButton_out_clicked()
{
    SpectrogramTable info;
    QList<QPointF> pointList;
    QVector<QList<QPointF>> datas;
    //获取信息
    getCurrentSelectSpectrogramInfo(info);
    if (!info.isSucess)
    {
        Utils::tipMessageBox("数据导出参数获取错误，请查看是否选中目标");
        return;
    }

    QSqlQuery query;
    bool isSucess = query.exec(QString("select * from %1").arg(info.value_dataTableName));

    if (!isSucess)
    {
        QSqlError error;
        Utils::tipMessageBox(QString("数据表检索错误%1").arg(error.text()));
        return;
    }

    DBDataTableFiled dataFiled;
    int i = 0;
    while (query.next())
    {
        QPointF point;
        double x = query.value(dataFiled.voltage).toDouble();
        double y = query.value(dataFiled.current).toDouble();
        point.setX(x);
        point.setY(y);
        pointList.append(point);

        if ((i++) >= info.value_dataLenth - 1)
        {
            datas.append(pointList);
            pointList.clear();          
            i = 0;
        }
    }

    emit isReadyToDraw(datas);
    qDebug()<<"lenth = "<<i;
}

void DataBaseDialog::initBtnMenu()
{
    //删除按钮
    clearMenu = new QMenu(this);
    clearAll = new QAction("删除全部", this);
    clearSelect = new QAction("删除选中", this);
    clearMenu->addAction(clearAll);
    clearMenu->addAction(clearSelect);
    ui->pushButton_clear->setMenu(clearMenu);
    connect(clearAll, &QAction::triggered, this, &DataBaseDialog::actionClearAllTrigger);
    connect(clearSelect, &QAction::triggered, this, &DataBaseDialog::actionClearSelectTrigger);

    //检索按钮
    searchMenu = new QMenu(this);
    searchAll = new QAction("检索全部", this);
    searchRelation = new QAction("条件检索", this);
    searchMenu->addAction(searchAll);
    searchMenu->addAction(searchRelation);
    ui->pushButton_search->setMenu(searchMenu);
    connect(searchAll, &QAction::triggered, [=](){
        spectrogramRelationMode->select();
    });
    connect(searchRelation, &QAction::triggered, this, &DataBaseDialog::spectrogramSearchFilter);
}

void DataBaseDialog::actionClearAllTrigger()
{

}

void DataBaseDialog::actionClearSelectTrigger()
{
    SpectrogramTable info;
    //获取信息
    getCurrentSelectSpectrogramInfo(info);
    if (!info.isSucess)
    {
        Utils::tipMessageBox("数据删除参数获取错误，请查看是否选中目标");
        return;
    }

    QSqlQuery query;
    //删除选中数据
    bool isSucess = query.exec(QString("delete from %1 where %2 = '%3'").arg(info.filed_tableName).arg(info.filed_dataTableName).arg(info.value_dataTableName));
    if (!isSucess)
    {
        QSqlError error = query.lastError();
        Utils::tipMessageBox(QString("管理表删除错误：%1").arg(error.text()));
        return;
    }
    //数据表删除
    isSucess = query.exec(QString("drop table %1").arg(info.value_dataTableName));
    if (!isSucess)
    {
        QSqlError error = query.lastError();
        Utils::tipMessageBox(QString("数据表删除错误：%1").arg(error.text()));
        return;
    }

    Utils::tipMessageBox("删除成功");
    updateShow();
}

void DataBaseDialog::getCurrentSelectSpectrogramInfo(SpectrogramTable &data)
{
    QItemSelectionModel *selectItem =  ui->tableView->selectionModel();
    QModelIndexList idList = selectItem->selectedRows();
    if (idList.isEmpty())
    {
        data.isSucess = false;
        qDebug()<<"没有选中";
        return;
    }

    int row = selectItem->currentIndex().row();

    QSqlRecord record = spectrogramRelationMode->record(row);
    data.value_dataTableName = record.value(data.filed_dataTableName).toString();
    data.value_dataLenth = record.value(data.filed_dataLength).toInt();
    data.isSucess = true;
}

void DataBaseDialog::spectrogramSearchFilter()
{
    if (spectrogramFilterDialog == nullptr)
    {
        spectrogramFilterDialog = new SpectrogramFilterDialog(this);
    }

    spectrogramFilterDialog->exec();
}
