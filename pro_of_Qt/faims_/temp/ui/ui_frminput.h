/********************************************************************************
** Form generated from reading UI file 'frminput.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMINPUT_H
#define UI_FRMINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmInput
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title;
    QVBoxLayout *verticalLayout_3;
    QWidget *widgetTop;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lay1;
    QLabel *lab_Title;
    QLabel *labPY;
    QPushButton *btnPre;
    QPushButton *btnNext;
    QPushButton *btnClose;
    QHBoxLayout *lay2;
    QLabel *labCh0;
    QLabel *labCh1;
    QLabel *labCh2;
    QLabel *labCh3;
    QLabel *labCh4;
    QLabel *labCh5;
    QLabel *labCh6;
    QLabel *labCh7;
    QLabel *labCh8;
    QLabel *labCh9;
    QWidget *widgetMain;
    QGridLayout *gridLayout;
    QPushButton *btnOther1;
    QPushButton *btnOther2;
    QPushButton *btnOther3;
    QPushButton *btnOther4;
    QPushButton *btnOther5;
    QPushButton *btnOther6;
    QPushButton *btnOther7;
    QPushButton *btnOther8;
    QPushButton *btnOther19;
    QPushButton *btnOther20;
    QPushButton *btnOther9;
    QPushButton *btnOther11;
    QPushButton *btnDelete;
    QSpacerItem *spacer;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnq;
    QPushButton *btnw;
    QPushButton *btne;
    QPushButton *btnr;
    QPushButton *btnt;
    QPushButton *btny;
    QPushButton *btnu;
    QPushButton *btni;
    QPushButton *btno;
    QPushButton *btnp;
    QPushButton *btnOther10;
    QPushButton *btnOther12;
    QPushButton *btnOther13;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btna;
    QPushButton *btns;
    QPushButton *btnd;
    QPushButton *btnf;
    QPushButton *btng;
    QPushButton *btnh;
    QPushButton *btnj;
    QPushButton *btnk;
    QPushButton *btnl;
    QPushButton *btnOther14;
    QPushButton *btnOther21;
    QPushButton *btnOther15;
    QPushButton *btnOther16;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btnz;
    QPushButton *btnx;
    QPushButton *btnc;
    QPushButton *btnv;
    QPushButton *btnb;
    QPushButton *btnn;
    QPushButton *btnm;
    QPushButton *btnOther17;
    QPushButton *btnOther18;
    QPushButton *btn0;
    QPushButton *btn00;
    QPushButton *btnDot;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSpace;
    QPushButton *btnEnter;
    QPushButton *btnType;

    void setupUi(QWidget *frmInput)
    {
        if (frmInput->objectName().isEmpty())
            frmInput->setObjectName(QStringLiteral("frmInput"));
        frmInput->resize(600, 220);
        frmInput->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(frmInput);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(frmInput);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_title);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widgetTop = new QWidget(widget_title);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        widgetTop->setStyleSheet(QStringLiteral("border-width:0px;"));
        verticalLayout = new QVBoxLayout(widgetTop);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lay1 = new QHBoxLayout();
        lay1->setSpacing(2);
        lay1->setObjectName(QStringLiteral("lay1"));
        lab_Title = new QLabel(widgetTop);
        lab_Title->setObjectName(QStringLiteral("lab_Title"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy1);
        lab_Title->setMinimumSize(QSize(0, 25));

        lay1->addWidget(lab_Title);

        labPY = new QLabel(widgetTop);
        labPY->setObjectName(QStringLiteral("labPY"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labPY->sizePolicy().hasHeightForWidth());
        labPY->setSizePolicy(sizePolicy2);
        labPY->setAlignment(Qt::AlignCenter);

        lay1->addWidget(labPY);

        btnPre = new QPushButton(widgetTop);
        btnPre->setObjectName(QStringLiteral("btnPre"));
        btnPre->setFocusPolicy(Qt::NoFocus);
        btnPre->setStyleSheet(QStringLiteral(""));

        lay1->addWidget(btnPre);

        btnNext = new QPushButton(widgetTop);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setFocusPolicy(Qt::NoFocus);
        btnNext->setStyleSheet(QStringLiteral(""));

        lay1->addWidget(btnNext);

        btnClose = new QPushButton(widgetTop);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setFocusPolicy(Qt::NoFocus);
        btnClose->setStyleSheet(QStringLiteral(""));

        lay1->addWidget(btnClose);


        verticalLayout->addLayout(lay1);

        lay2 = new QHBoxLayout();
        lay2->setSpacing(0);
        lay2->setObjectName(QStringLiteral("lay2"));
        labCh0 = new QLabel(widgetTop);
        labCh0->setObjectName(QStringLiteral("labCh0"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labCh0->sizePolicy().hasHeightForWidth());
        labCh0->setSizePolicy(sizePolicy3);
        labCh0->setMinimumSize(QSize(0, 25));
        labCh0->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh0);

        labCh1 = new QLabel(widgetTop);
        labCh1->setObjectName(QStringLiteral("labCh1"));
        sizePolicy3.setHeightForWidth(labCh1->sizePolicy().hasHeightForWidth());
        labCh1->setSizePolicy(sizePolicy3);
        labCh1->setMinimumSize(QSize(0, 25));
        labCh1->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh1);

        labCh2 = new QLabel(widgetTop);
        labCh2->setObjectName(QStringLiteral("labCh2"));
        sizePolicy3.setHeightForWidth(labCh2->sizePolicy().hasHeightForWidth());
        labCh2->setSizePolicy(sizePolicy3);
        labCh2->setMinimumSize(QSize(0, 25));
        labCh2->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh2);

        labCh3 = new QLabel(widgetTop);
        labCh3->setObjectName(QStringLiteral("labCh3"));
        sizePolicy3.setHeightForWidth(labCh3->sizePolicy().hasHeightForWidth());
        labCh3->setSizePolicy(sizePolicy3);
        labCh3->setMinimumSize(QSize(0, 25));
        labCh3->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh3);

        labCh4 = new QLabel(widgetTop);
        labCh4->setObjectName(QStringLiteral("labCh4"));
        sizePolicy3.setHeightForWidth(labCh4->sizePolicy().hasHeightForWidth());
        labCh4->setSizePolicy(sizePolicy3);
        labCh4->setMinimumSize(QSize(0, 25));
        labCh4->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh4);

        labCh5 = new QLabel(widgetTop);
        labCh5->setObjectName(QStringLiteral("labCh5"));
        sizePolicy3.setHeightForWidth(labCh5->sizePolicy().hasHeightForWidth());
        labCh5->setSizePolicy(sizePolicy3);
        labCh5->setMinimumSize(QSize(0, 25));
        labCh5->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh5);

        labCh6 = new QLabel(widgetTop);
        labCh6->setObjectName(QStringLiteral("labCh6"));
        sizePolicy3.setHeightForWidth(labCh6->sizePolicy().hasHeightForWidth());
        labCh6->setSizePolicy(sizePolicy3);
        labCh6->setMinimumSize(QSize(0, 25));
        labCh6->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh6);

        labCh7 = new QLabel(widgetTop);
        labCh7->setObjectName(QStringLiteral("labCh7"));
        sizePolicy3.setHeightForWidth(labCh7->sizePolicy().hasHeightForWidth());
        labCh7->setSizePolicy(sizePolicy3);
        labCh7->setMinimumSize(QSize(0, 25));
        labCh7->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh7);

        labCh8 = new QLabel(widgetTop);
        labCh8->setObjectName(QStringLiteral("labCh8"));
        sizePolicy3.setHeightForWidth(labCh8->sizePolicy().hasHeightForWidth());
        labCh8->setSizePolicy(sizePolicy3);
        labCh8->setMinimumSize(QSize(0, 25));
        labCh8->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh8);

        labCh9 = new QLabel(widgetTop);
        labCh9->setObjectName(QStringLiteral("labCh9"));
        sizePolicy3.setHeightForWidth(labCh9->sizePolicy().hasHeightForWidth());
        labCh9->setSizePolicy(sizePolicy3);
        labCh9->setMinimumSize(QSize(0, 25));
        labCh9->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labCh9);


        verticalLayout->addLayout(lay2);


        verticalLayout_3->addWidget(widgetTop);

        widgetMain = new QWidget(widget_title);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        sizePolicy.setHeightForWidth(widgetMain->sizePolicy().hasHeightForWidth());
        widgetMain->setSizePolicy(sizePolicy);
        widgetMain->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(widgetMain);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 3, 0, 0);
        btnOther1 = new QPushButton(widgetMain);
        btnOther1->setObjectName(QStringLiteral("btnOther1"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnOther1->sizePolicy().hasHeightForWidth());
        btnOther1->setSizePolicy(sizePolicy4);
        btnOther1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther1, 0, 0, 1, 1);

        btnOther2 = new QPushButton(widgetMain);
        btnOther2->setObjectName(QStringLiteral("btnOther2"));
        sizePolicy4.setHeightForWidth(btnOther2->sizePolicy().hasHeightForWidth());
        btnOther2->setSizePolicy(sizePolicy4);
        btnOther2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther2, 0, 1, 1, 1);

        btnOther3 = new QPushButton(widgetMain);
        btnOther3->setObjectName(QStringLiteral("btnOther3"));
        sizePolicy4.setHeightForWidth(btnOther3->sizePolicy().hasHeightForWidth());
        btnOther3->setSizePolicy(sizePolicy4);
        btnOther3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther3, 0, 2, 1, 1);

        btnOther4 = new QPushButton(widgetMain);
        btnOther4->setObjectName(QStringLiteral("btnOther4"));
        sizePolicy4.setHeightForWidth(btnOther4->sizePolicy().hasHeightForWidth());
        btnOther4->setSizePolicy(sizePolicy4);
        btnOther4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther4, 0, 3, 1, 1);

        btnOther5 = new QPushButton(widgetMain);
        btnOther5->setObjectName(QStringLiteral("btnOther5"));
        sizePolicy4.setHeightForWidth(btnOther5->sizePolicy().hasHeightForWidth());
        btnOther5->setSizePolicy(sizePolicy4);
        btnOther5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther5, 0, 4, 1, 1);

        btnOther6 = new QPushButton(widgetMain);
        btnOther6->setObjectName(QStringLiteral("btnOther6"));
        sizePolicy4.setHeightForWidth(btnOther6->sizePolicy().hasHeightForWidth());
        btnOther6->setSizePolicy(sizePolicy4);
        btnOther6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther6, 0, 5, 1, 1);

        btnOther7 = new QPushButton(widgetMain);
        btnOther7->setObjectName(QStringLiteral("btnOther7"));
        sizePolicy4.setHeightForWidth(btnOther7->sizePolicy().hasHeightForWidth());
        btnOther7->setSizePolicy(sizePolicy4);
        btnOther7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther7, 0, 6, 1, 1);

        btnOther8 = new QPushButton(widgetMain);
        btnOther8->setObjectName(QStringLiteral("btnOther8"));
        sizePolicy4.setHeightForWidth(btnOther8->sizePolicy().hasHeightForWidth());
        btnOther8->setSizePolicy(sizePolicy4);
        btnOther8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther8, 0, 7, 1, 1);

        btnOther19 = new QPushButton(widgetMain);
        btnOther19->setObjectName(QStringLiteral("btnOther19"));
        sizePolicy4.setHeightForWidth(btnOther19->sizePolicy().hasHeightForWidth());
        btnOther19->setSizePolicy(sizePolicy4);
        btnOther19->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther19, 0, 8, 1, 1);

        btnOther20 = new QPushButton(widgetMain);
        btnOther20->setObjectName(QStringLiteral("btnOther20"));
        sizePolicy4.setHeightForWidth(btnOther20->sizePolicy().hasHeightForWidth());
        btnOther20->setSizePolicy(sizePolicy4);
        btnOther20->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther20, 0, 9, 1, 1);

        btnOther9 = new QPushButton(widgetMain);
        btnOther9->setObjectName(QStringLiteral("btnOther9"));
        sizePolicy4.setHeightForWidth(btnOther9->sizePolicy().hasHeightForWidth());
        btnOther9->setSizePolicy(sizePolicy4);
        btnOther9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther9, 0, 10, 1, 1);

        btnOther11 = new QPushButton(widgetMain);
        btnOther11->setObjectName(QStringLiteral("btnOther11"));
        sizePolicy4.setHeightForWidth(btnOther11->sizePolicy().hasHeightForWidth());
        btnOther11->setSizePolicy(sizePolicy4);
        btnOther11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther11, 0, 11, 1, 1);

        btnDelete = new QPushButton(widgetMain);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        sizePolicy4.setHeightForWidth(btnDelete->sizePolicy().hasHeightForWidth());
        btnDelete->setSizePolicy(sizePolicy4);
        btnDelete->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnDelete, 0, 12, 1, 1);

        spacer = new QSpacerItem(15, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(spacer, 0, 13, 1, 1);

        btn7 = new QPushButton(widgetMain);
        btn7->setObjectName(QStringLiteral("btn7"));
        sizePolicy4.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy4);
        btn7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn7, 0, 14, 1, 1);

        btn8 = new QPushButton(widgetMain);
        btn8->setObjectName(QStringLiteral("btn8"));
        sizePolicy4.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy4);
        btn8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn8, 0, 15, 1, 1);

        btn9 = new QPushButton(widgetMain);
        btn9->setObjectName(QStringLiteral("btn9"));
        sizePolicy4.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy4);
        btn9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn9, 0, 16, 1, 1);

        btnq = new QPushButton(widgetMain);
        btnq->setObjectName(QStringLiteral("btnq"));
        sizePolicy4.setHeightForWidth(btnq->sizePolicy().hasHeightForWidth());
        btnq->setSizePolicy(sizePolicy4);
        btnq->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnq, 1, 0, 1, 1);

        btnw = new QPushButton(widgetMain);
        btnw->setObjectName(QStringLiteral("btnw"));
        sizePolicy4.setHeightForWidth(btnw->sizePolicy().hasHeightForWidth());
        btnw->setSizePolicy(sizePolicy4);
        btnw->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnw, 1, 1, 1, 1);

        btne = new QPushButton(widgetMain);
        btne->setObjectName(QStringLiteral("btne"));
        sizePolicy4.setHeightForWidth(btne->sizePolicy().hasHeightForWidth());
        btne->setSizePolicy(sizePolicy4);
        btne->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btne, 1, 2, 1, 1);

        btnr = new QPushButton(widgetMain);
        btnr->setObjectName(QStringLiteral("btnr"));
        sizePolicy4.setHeightForWidth(btnr->sizePolicy().hasHeightForWidth());
        btnr->setSizePolicy(sizePolicy4);
        btnr->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnr, 1, 3, 1, 1);

        btnt = new QPushButton(widgetMain);
        btnt->setObjectName(QStringLiteral("btnt"));
        sizePolicy4.setHeightForWidth(btnt->sizePolicy().hasHeightForWidth());
        btnt->setSizePolicy(sizePolicy4);
        btnt->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnt, 1, 4, 1, 1);

        btny = new QPushButton(widgetMain);
        btny->setObjectName(QStringLiteral("btny"));
        sizePolicy4.setHeightForWidth(btny->sizePolicy().hasHeightForWidth());
        btny->setSizePolicy(sizePolicy4);
        btny->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btny, 1, 5, 1, 1);

        btnu = new QPushButton(widgetMain);
        btnu->setObjectName(QStringLiteral("btnu"));
        sizePolicy4.setHeightForWidth(btnu->sizePolicy().hasHeightForWidth());
        btnu->setSizePolicy(sizePolicy4);
        btnu->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnu, 1, 6, 1, 1);

        btni = new QPushButton(widgetMain);
        btni->setObjectName(QStringLiteral("btni"));
        sizePolicy4.setHeightForWidth(btni->sizePolicy().hasHeightForWidth());
        btni->setSizePolicy(sizePolicy4);
        btni->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btni, 1, 7, 1, 1);

        btno = new QPushButton(widgetMain);
        btno->setObjectName(QStringLiteral("btno"));
        sizePolicy4.setHeightForWidth(btno->sizePolicy().hasHeightForWidth());
        btno->setSizePolicy(sizePolicy4);
        btno->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btno, 1, 8, 1, 1);

        btnp = new QPushButton(widgetMain);
        btnp->setObjectName(QStringLiteral("btnp"));
        sizePolicy4.setHeightForWidth(btnp->sizePolicy().hasHeightForWidth());
        btnp->setSizePolicy(sizePolicy4);
        btnp->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnp, 1, 9, 1, 1);

        btnOther10 = new QPushButton(widgetMain);
        btnOther10->setObjectName(QStringLiteral("btnOther10"));
        sizePolicy4.setHeightForWidth(btnOther10->sizePolicy().hasHeightForWidth());
        btnOther10->setSizePolicy(sizePolicy4);
        btnOther10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther10, 1, 10, 1, 1);

        btnOther12 = new QPushButton(widgetMain);
        btnOther12->setObjectName(QStringLiteral("btnOther12"));
        sizePolicy4.setHeightForWidth(btnOther12->sizePolicy().hasHeightForWidth());
        btnOther12->setSizePolicy(sizePolicy4);
        btnOther12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther12, 1, 11, 1, 1);

        btnOther13 = new QPushButton(widgetMain);
        btnOther13->setObjectName(QStringLiteral("btnOther13"));
        sizePolicy4.setHeightForWidth(btnOther13->sizePolicy().hasHeightForWidth());
        btnOther13->setSizePolicy(sizePolicy4);
        btnOther13->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther13, 1, 12, 1, 1);

        btn4 = new QPushButton(widgetMain);
        btn4->setObjectName(QStringLiteral("btn4"));
        sizePolicy4.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy4);
        btn4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn4, 1, 14, 1, 1);

        btn5 = new QPushButton(widgetMain);
        btn5->setObjectName(QStringLiteral("btn5"));
        sizePolicy4.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy4);
        btn5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn5, 1, 15, 1, 1);

        btn6 = new QPushButton(widgetMain);
        btn6->setObjectName(QStringLiteral("btn6"));
        sizePolicy4.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy4);
        btn6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn6, 1, 16, 1, 1);

        btna = new QPushButton(widgetMain);
        btna->setObjectName(QStringLiteral("btna"));
        sizePolicy4.setHeightForWidth(btna->sizePolicy().hasHeightForWidth());
        btna->setSizePolicy(sizePolicy4);
        btna->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btna, 2, 0, 1, 1);

        btns = new QPushButton(widgetMain);
        btns->setObjectName(QStringLiteral("btns"));
        sizePolicy4.setHeightForWidth(btns->sizePolicy().hasHeightForWidth());
        btns->setSizePolicy(sizePolicy4);
        btns->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btns, 2, 1, 1, 1);

        btnd = new QPushButton(widgetMain);
        btnd->setObjectName(QStringLiteral("btnd"));
        sizePolicy4.setHeightForWidth(btnd->sizePolicy().hasHeightForWidth());
        btnd->setSizePolicy(sizePolicy4);
        btnd->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnd, 2, 2, 1, 1);

        btnf = new QPushButton(widgetMain);
        btnf->setObjectName(QStringLiteral("btnf"));
        sizePolicy4.setHeightForWidth(btnf->sizePolicy().hasHeightForWidth());
        btnf->setSizePolicy(sizePolicy4);
        btnf->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnf, 2, 3, 1, 1);

        btng = new QPushButton(widgetMain);
        btng->setObjectName(QStringLiteral("btng"));
        sizePolicy4.setHeightForWidth(btng->sizePolicy().hasHeightForWidth());
        btng->setSizePolicy(sizePolicy4);
        btng->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btng, 2, 4, 1, 1);

        btnh = new QPushButton(widgetMain);
        btnh->setObjectName(QStringLiteral("btnh"));
        sizePolicy4.setHeightForWidth(btnh->sizePolicy().hasHeightForWidth());
        btnh->setSizePolicy(sizePolicy4);
        btnh->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnh, 2, 5, 1, 1);

        btnj = new QPushButton(widgetMain);
        btnj->setObjectName(QStringLiteral("btnj"));
        sizePolicy4.setHeightForWidth(btnj->sizePolicy().hasHeightForWidth());
        btnj->setSizePolicy(sizePolicy4);
        btnj->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnj, 2, 6, 1, 1);

        btnk = new QPushButton(widgetMain);
        btnk->setObjectName(QStringLiteral("btnk"));
        sizePolicy4.setHeightForWidth(btnk->sizePolicy().hasHeightForWidth());
        btnk->setSizePolicy(sizePolicy4);
        btnk->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnk, 2, 7, 1, 1);

        btnl = new QPushButton(widgetMain);
        btnl->setObjectName(QStringLiteral("btnl"));
        sizePolicy4.setHeightForWidth(btnl->sizePolicy().hasHeightForWidth());
        btnl->setSizePolicy(sizePolicy4);
        btnl->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnl, 2, 8, 1, 1);

        btnOther14 = new QPushButton(widgetMain);
        btnOther14->setObjectName(QStringLiteral("btnOther14"));
        sizePolicy4.setHeightForWidth(btnOther14->sizePolicy().hasHeightForWidth());
        btnOther14->setSizePolicy(sizePolicy4);
        btnOther14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther14, 2, 9, 1, 1);

        btnOther21 = new QPushButton(widgetMain);
        btnOther21->setObjectName(QStringLiteral("btnOther21"));
        sizePolicy4.setHeightForWidth(btnOther21->sizePolicy().hasHeightForWidth());
        btnOther21->setSizePolicy(sizePolicy4);
        btnOther21->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther21, 2, 10, 1, 1);

        btnOther15 = new QPushButton(widgetMain);
        btnOther15->setObjectName(QStringLiteral("btnOther15"));
        sizePolicy4.setHeightForWidth(btnOther15->sizePolicy().hasHeightForWidth());
        btnOther15->setSizePolicy(sizePolicy4);
        btnOther15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther15, 2, 11, 1, 1);

        btnOther16 = new QPushButton(widgetMain);
        btnOther16->setObjectName(QStringLiteral("btnOther16"));
        sizePolicy4.setHeightForWidth(btnOther16->sizePolicy().hasHeightForWidth());
        btnOther16->setSizePolicy(sizePolicy4);
        btnOther16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther16, 2, 12, 1, 1);

        btn1 = new QPushButton(widgetMain);
        btn1->setObjectName(QStringLiteral("btn1"));
        sizePolicy4.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy4);
        btn1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn1, 2, 14, 1, 1);

        btn2 = new QPushButton(widgetMain);
        btn2->setObjectName(QStringLiteral("btn2"));
        sizePolicy4.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy4);
        btn2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn2, 2, 15, 1, 1);

        btn3 = new QPushButton(widgetMain);
        btn3->setObjectName(QStringLiteral("btn3"));
        sizePolicy4.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy4);
        btn3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn3, 2, 16, 1, 1);

        btnz = new QPushButton(widgetMain);
        btnz->setObjectName(QStringLiteral("btnz"));
        sizePolicy4.setHeightForWidth(btnz->sizePolicy().hasHeightForWidth());
        btnz->setSizePolicy(sizePolicy4);
        btnz->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnz, 3, 0, 1, 1);

        btnx = new QPushButton(widgetMain);
        btnx->setObjectName(QStringLiteral("btnx"));
        sizePolicy4.setHeightForWidth(btnx->sizePolicy().hasHeightForWidth());
        btnx->setSizePolicy(sizePolicy4);
        btnx->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnx, 3, 1, 1, 1);

        btnc = new QPushButton(widgetMain);
        btnc->setObjectName(QStringLiteral("btnc"));
        sizePolicy4.setHeightForWidth(btnc->sizePolicy().hasHeightForWidth());
        btnc->setSizePolicy(sizePolicy4);
        btnc->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnc, 3, 2, 1, 1);

        btnv = new QPushButton(widgetMain);
        btnv->setObjectName(QStringLiteral("btnv"));
        sizePolicy4.setHeightForWidth(btnv->sizePolicy().hasHeightForWidth());
        btnv->setSizePolicy(sizePolicy4);
        btnv->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnv, 3, 3, 1, 1);

        btnb = new QPushButton(widgetMain);
        btnb->setObjectName(QStringLiteral("btnb"));
        sizePolicy4.setHeightForWidth(btnb->sizePolicy().hasHeightForWidth());
        btnb->setSizePolicy(sizePolicy4);
        btnb->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnb, 3, 4, 1, 1);

        btnn = new QPushButton(widgetMain);
        btnn->setObjectName(QStringLiteral("btnn"));
        sizePolicy4.setHeightForWidth(btnn->sizePolicy().hasHeightForWidth());
        btnn->setSizePolicy(sizePolicy4);
        btnn->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnn, 3, 5, 1, 1);

        btnm = new QPushButton(widgetMain);
        btnm->setObjectName(QStringLiteral("btnm"));
        sizePolicy4.setHeightForWidth(btnm->sizePolicy().hasHeightForWidth());
        btnm->setSizePolicy(sizePolicy4);
        btnm->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnm, 3, 6, 1, 1);

        btnOther17 = new QPushButton(widgetMain);
        btnOther17->setObjectName(QStringLiteral("btnOther17"));
        sizePolicy4.setHeightForWidth(btnOther17->sizePolicy().hasHeightForWidth());
        btnOther17->setSizePolicy(sizePolicy4);
        btnOther17->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther17, 3, 7, 1, 1);

        btnOther18 = new QPushButton(widgetMain);
        btnOther18->setObjectName(QStringLiteral("btnOther18"));
        sizePolicy4.setHeightForWidth(btnOther18->sizePolicy().hasHeightForWidth());
        btnOther18->setSizePolicy(sizePolicy4);
        btnOther18->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther18, 3, 8, 1, 1);

        btn0 = new QPushButton(widgetMain);
        btn0->setObjectName(QStringLiteral("btn0"));
        sizePolicy4.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy4);
        btn0->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn0, 3, 14, 1, 1);

        btn00 = new QPushButton(widgetMain);
        btn00->setObjectName(QStringLiteral("btn00"));
        sizePolicy4.setHeightForWidth(btn00->sizePolicy().hasHeightForWidth());
        btn00->setSizePolicy(sizePolicy4);
        btn00->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn00, 3, 15, 1, 1);

        btnDot = new QPushButton(widgetMain);
        btnDot->setObjectName(QStringLiteral("btnDot"));
        sizePolicy4.setHeightForWidth(btnDot->sizePolicy().hasHeightForWidth());
        btnDot->setSizePolicy(sizePolicy4);
        btnDot->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnDot, 3, 16, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnSpace = new QPushButton(widgetMain);
        btnSpace->setObjectName(QStringLiteral("btnSpace"));
        sizePolicy4.setHeightForWidth(btnSpace->sizePolicy().hasHeightForWidth());
        btnSpace->setSizePolicy(sizePolicy4);
        btnSpace->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(btnSpace);

        btnEnter = new QPushButton(widgetMain);
        btnEnter->setObjectName(QStringLiteral("btnEnter"));
        sizePolicy4.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy4);
        btnEnter->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(btnEnter);

        btnType = new QPushButton(widgetMain);
        btnType->setObjectName(QStringLiteral("btnType"));
        sizePolicy4.setHeightForWidth(btnType->sizePolicy().hasHeightForWidth());
        btnType->setSizePolicy(sizePolicy4);
        btnType->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(btnType);


        gridLayout->addLayout(horizontalLayout, 3, 9, 1, 4);


        verticalLayout_3->addWidget(widgetMain);


        verticalLayout_2->addWidget(widget_title);


        retranslateUi(frmInput);

        QMetaObject::connectSlotsByName(frmInput);
    } // setupUi

    void retranslateUi(QWidget *frmInput)
    {
        frmInput->setWindowTitle(QApplication::translate("frmInput", "\344\270\255\346\226\207\350\276\223\345\205\245\346\263\225\351\235\242\346\235\277", Q_NULLPTR));
        lab_Title->setText(QApplication::translate("frmInput", "  \344\270\255\346\226\207\350\276\223\345\205\245\346\263\225--\345\260\217\345\206\231", Q_NULLPTR));
        labPY->setText(QString());
        btnPre->setText(QApplication::translate("frmInput", "<", Q_NULLPTR));
        btnNext->setText(QApplication::translate("frmInput", ">", Q_NULLPTR));
        btnClose->setText(QApplication::translate("frmInput", "\345\205\263\351\227\255", Q_NULLPTR));
        labCh0->setText(QString());
        labCh1->setText(QString());
        labCh2->setText(QString());
        labCh3->setText(QString());
        labCh4->setText(QString());
        labCh5->setText(QString());
        labCh6->setText(QString());
        labCh7->setText(QString());
        labCh8->setText(QString());
        labCh9->setText(QString());
        btnOther1->setText(QApplication::translate("frmInput", "!", Q_NULLPTR));
        btnOther2->setText(QApplication::translate("frmInput", "@", Q_NULLPTR));
        btnOther3->setText(QApplication::translate("frmInput", "#", Q_NULLPTR));
        btnOther4->setText(QApplication::translate("frmInput", "$", Q_NULLPTR));
        btnOther5->setText(QApplication::translate("frmInput", "%", Q_NULLPTR));
        btnOther6->setText(QApplication::translate("frmInput", "^", Q_NULLPTR));
        btnOther7->setText(QApplication::translate("frmInput", "&&", Q_NULLPTR));
        btnOther8->setText(QApplication::translate("frmInput", "*", Q_NULLPTR));
        btnOther19->setText(QApplication::translate("frmInput", "(", Q_NULLPTR));
        btnOther20->setText(QApplication::translate("frmInput", ")", Q_NULLPTR));
        btnOther9->setText(QApplication::translate("frmInput", "-", Q_NULLPTR));
        btnOther11->setText(QApplication::translate("frmInput", "+", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("frmInput", "\342\206\220", Q_NULLPTR));
        btn7->setText(QApplication::translate("frmInput", "7", Q_NULLPTR));
        btn8->setText(QApplication::translate("frmInput", "8", Q_NULLPTR));
        btn9->setText(QApplication::translate("frmInput", "9", Q_NULLPTR));
        btnq->setText(QApplication::translate("frmInput", "q", Q_NULLPTR));
        btnw->setText(QApplication::translate("frmInput", "w", Q_NULLPTR));
        btne->setText(QApplication::translate("frmInput", "e", Q_NULLPTR));
        btnr->setText(QApplication::translate("frmInput", "r", Q_NULLPTR));
        btnt->setText(QApplication::translate("frmInput", "t", Q_NULLPTR));
        btny->setText(QApplication::translate("frmInput", "y", Q_NULLPTR));
        btnu->setText(QApplication::translate("frmInput", "u", Q_NULLPTR));
        btni->setText(QApplication::translate("frmInput", "i", Q_NULLPTR));
        btno->setText(QApplication::translate("frmInput", "o", Q_NULLPTR));
        btnp->setText(QApplication::translate("frmInput", "p", Q_NULLPTR));
        btnOther10->setText(QApplication::translate("frmInput", "_", Q_NULLPTR));
        btnOther12->setText(QApplication::translate("frmInput", "/", Q_NULLPTR));
        btnOther13->setText(QApplication::translate("frmInput", "|", Q_NULLPTR));
        btn4->setText(QApplication::translate("frmInput", "4", Q_NULLPTR));
        btn5->setText(QApplication::translate("frmInput", "5", Q_NULLPTR));
        btn6->setText(QApplication::translate("frmInput", "6", Q_NULLPTR));
        btna->setText(QApplication::translate("frmInput", "a", Q_NULLPTR));
        btns->setText(QApplication::translate("frmInput", "s", Q_NULLPTR));
        btnd->setText(QApplication::translate("frmInput", "d", Q_NULLPTR));
        btnf->setText(QApplication::translate("frmInput", "f", Q_NULLPTR));
        btng->setText(QApplication::translate("frmInput", "g", Q_NULLPTR));
        btnh->setText(QApplication::translate("frmInput", "h", Q_NULLPTR));
        btnj->setText(QApplication::translate("frmInput", "j", Q_NULLPTR));
        btnk->setText(QApplication::translate("frmInput", "k", Q_NULLPTR));
        btnl->setText(QApplication::translate("frmInput", "l", Q_NULLPTR));
        btnOther14->setText(QApplication::translate("frmInput", ":", Q_NULLPTR));
        btnOther21->setText(QApplication::translate("frmInput", "\"", Q_NULLPTR));
        btnOther15->setText(QApplication::translate("frmInput", "?", Q_NULLPTR));
        btnOther16->setText(QApplication::translate("frmInput", "=", Q_NULLPTR));
        btn1->setText(QApplication::translate("frmInput", "1", Q_NULLPTR));
        btn2->setText(QApplication::translate("frmInput", "2", Q_NULLPTR));
        btn3->setText(QApplication::translate("frmInput", "3", Q_NULLPTR));
        btnz->setText(QApplication::translate("frmInput", "z", Q_NULLPTR));
        btnx->setText(QApplication::translate("frmInput", "x", Q_NULLPTR));
        btnc->setText(QApplication::translate("frmInput", "c", Q_NULLPTR));
        btnv->setText(QApplication::translate("frmInput", "v", Q_NULLPTR));
        btnb->setText(QApplication::translate("frmInput", "b", Q_NULLPTR));
        btnn->setText(QApplication::translate("frmInput", "n", Q_NULLPTR));
        btnm->setText(QApplication::translate("frmInput", "m", Q_NULLPTR));
        btnOther17->setText(QApplication::translate("frmInput", ",", Q_NULLPTR));
        btnOther18->setText(QApplication::translate("frmInput", "\\", Q_NULLPTR));
        btn0->setText(QApplication::translate("frmInput", "0", Q_NULLPTR));
        btn00->setText(QApplication::translate("frmInput", "00", Q_NULLPTR));
        btnDot->setText(QApplication::translate("frmInput", ".", Q_NULLPTR));
        btnSpace->setText(QApplication::translate("frmInput", "\347\251\272\346\240\274", Q_NULLPTR));
        btnEnter->setText(QApplication::translate("frmInput", "\345\233\236\350\275\246", Q_NULLPTR));
        btnType->setText(QApplication::translate("frmInput", "\345\260\217\345\206\231", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class frmInput: public Ui_frmInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMINPUT_H
