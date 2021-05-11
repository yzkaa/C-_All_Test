#ifndef DATABASEDIALOG_H
#define DATABASEDIALOG_H

#include <QDialog>
#include <QTimer>
#include <QSqlRecord>
#include <QMenu>

#include "utils.h"

#include "DataBase/databaseserver.h"
#include "DataBase/spectrogramrelationmode.h"
#include "DataBase/dbdatas.h"
#include "DataBase/spectrogramfilterdialog.h"
namespace Ui {
class DataBaseDialog;
}

class DataBaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataBaseDialog(QWidget *parent = 0);
    ~DataBaseDialog();
signals:
    void connectSucess();
    void connectFail(QString errorInfo);
    void isReadyToDraw(QVector<QList<QPointF>> &data);
public slots:
    void updateShow();
private slots:
    void initTreeWidget();
    void on_pushButton_out_clicked();
    void initBtnMenu();

    void actionClearAllTrigger();
    void actionClearSelectTrigger();
    void getCurrentSelectSpectrogramInfo(SpectrogramTable &data);
    void spectrogramSearchFilter();
private:
    Ui::DataBaseDialog *ui;

    //数据库连接
    DatabaseServer *dbServer = nullptr;
    //表
    SpectrogramRelationMode *spectrogramRelationMode = nullptr;
    //条件检索过滤界面
    SpectrogramFilterDialog *spectrogramFilterDialog = nullptr;
    //按钮菜单项
    QMenu *clearMenu;
    QAction *clearAll;
    QAction *clearSelect;

    QMenu *searchMenu;
    QAction *searchAll;
    QAction *searchRelation;

    //数据库连接状态
    bool dbConnectState = false;
};

#endif // DATABASEDIALOG_H
