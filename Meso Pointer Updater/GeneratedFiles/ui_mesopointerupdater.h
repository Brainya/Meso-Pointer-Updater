/********************************************************************************
** Form generated from reading UI file 'mesopointerupdater.ui'
**
** Created: Thu May 9 13:29:29 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESOPOINTERUPDATER_H
#define UI_MESOPOINTERUPDATER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MesoPointerUpdaterClass
{
public:
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionUpdate;
    QAction *actionCopy;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTreeWidget *Tree_Widget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MesoPointerUpdaterClass)
    {
        if (MesoPointerUpdaterClass->objectName().isEmpty())
            MesoPointerUpdaterClass->setObjectName(QString::fromUtf8("MesoPointerUpdaterClass"));
        MesoPointerUpdaterClass->resize(286, 463);
        MesoPointerUpdaterClass->setWindowOpacity(0.9);
        actionSave = new QAction(MesoPointerUpdaterClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MesoPointerUpdaterClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MesoPointerUpdaterClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionUpdate = new QAction(MesoPointerUpdaterClass);
        actionUpdate->setObjectName(QString::fromUtf8("actionUpdate"));
        actionCopy = new QAction(MesoPointerUpdaterClass);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        centralWidget = new QWidget(MesoPointerUpdaterClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Tree_Widget = new QTreeWidget(centralWidget);
        Tree_Widget->setObjectName(QString::fromUtf8("Tree_Widget"));
        Tree_Widget->setContextMenuPolicy(Qt::ActionsContextMenu);
        Tree_Widget->setIndentation(0);
        Tree_Widget->setUniformRowHeights(true);

        gridLayout->addWidget(Tree_Widget, 1, 0, 1, 1);

        MesoPointerUpdaterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MesoPointerUpdaterClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 286, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MesoPointerUpdaterClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionUpdate);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MesoPointerUpdaterClass);
        QObject::connect(actionExit, SIGNAL(triggered()), MesoPointerUpdaterClass, SLOT(close()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MesoPointerUpdaterClass, SLOT(ActionTriggered()));
        QObject::connect(actionUpdate, SIGNAL(triggered()), MesoPointerUpdaterClass, SLOT(ActionTriggered()));
        QObject::connect(actionCopy, SIGNAL(triggered()), MesoPointerUpdaterClass, SLOT(ActionTriggered()));
        QObject::connect(actionSave, SIGNAL(triggered()), MesoPointerUpdaterClass, SLOT(ActionTriggered()));

        QMetaObject::connectSlotsByName(MesoPointerUpdaterClass);
    } // setupUi

    void retranslateUi(QMainWindow *MesoPointerUpdaterClass)
    {
        MesoPointerUpdaterClass->setWindowTitle(QApplication::translate("MesoPointerUpdaterClass", "Meso Pointer Updater", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MesoPointerUpdaterClass", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MesoPointerUpdaterClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MesoPointerUpdaterClass", "About", 0, QApplication::UnicodeUTF8));
        actionUpdate->setText(QApplication::translate("MesoPointerUpdaterClass", "Update", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MesoPointerUpdaterClass", "Copy", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = Tree_Widget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MesoPointerUpdaterClass", "Address", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MesoPointerUpdaterClass", "Name", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MesoPointerUpdaterClass", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MesoPointerUpdaterClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MesoPointerUpdaterClass: public Ui_MesoPointerUpdaterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESOPOINTERUPDATER_H
