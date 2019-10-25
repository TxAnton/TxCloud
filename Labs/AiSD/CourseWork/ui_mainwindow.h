/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen_file;
    QAction *actionCreate;
    QAction *actionSave;
    QAction *actionFile_info;
    QAction *actionAuhor_info;
    QAction *actionReference;
    QAction *actionDraw_triangle;
    QAction *actionDraw_line;
    QAction *actionInvert_circle;
    QAction *actionCut_image;
    QAction *actionNew_tool;
    QAction *actionProperties;
    QAction *actionGraphWindow;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuUtil;
    QMenu *menuTools;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 700);
        actionopen_file = new QAction(MainWindow);
        actionopen_file->setObjectName(QString::fromUtf8("actionopen_file"));
        actionCreate = new QAction(MainWindow);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionFile_info = new QAction(MainWindow);
        actionFile_info->setObjectName(QString::fromUtf8("actionFile_info"));
        actionAuhor_info = new QAction(MainWindow);
        actionAuhor_info->setObjectName(QString::fromUtf8("actionAuhor_info"));
        actionReference = new QAction(MainWindow);
        actionReference->setObjectName(QString::fromUtf8("actionReference"));
        actionDraw_triangle = new QAction(MainWindow);
        actionDraw_triangle->setObjectName(QString::fromUtf8("actionDraw_triangle"));
        actionDraw_line = new QAction(MainWindow);
        actionDraw_line->setObjectName(QString::fromUtf8("actionDraw_line"));
        actionInvert_circle = new QAction(MainWindow);
        actionInvert_circle->setObjectName(QString::fromUtf8("actionInvert_circle"));
        actionCut_image = new QAction(MainWindow);
        actionCut_image->setObjectName(QString::fromUtf8("actionCut_image"));
        actionNew_tool = new QAction(MainWindow);
        actionNew_tool->setObjectName(QString::fromUtf8("actionNew_tool"));
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName(QString::fromUtf8("actionProperties"));
        actionGraphWindow = new QAction(MainWindow);
        actionGraphWindow->setObjectName(QString::fromUtf8("actionGraphWindow"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 25));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuUtil = new QMenu(menuBar);
        menuUtil->setObjectName(QString::fromUtf8("menuUtil"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuUtil->menuAction());
        menufile->addAction(actionopen_file);
        menufile->addAction(actionCreate);
        menufile->addAction(actionSave);
        menufile->addSeparator();
        menufile->addAction(actionProperties);
        menuUtil->addAction(actionGraphWindow);
        menuUtil->addSeparator();
        menuTools->addAction(actionDraw_triangle);
        menuTools->addAction(actionDraw_line);
        menuTools->addAction(actionInvert_circle);
        menuTools->addAction(actionCut_image);
        menuTools->addAction(actionNew_tool);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen_file->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionCreate->setText(QApplication::translate("MainWindow", "Create", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionFile_info->setText(QApplication::translate("MainWindow", "Information about file", nullptr));
        actionAuhor_info->setText(QApplication::translate("MainWindow", "Author", nullptr));
        actionReference->setText(QApplication::translate("MainWindow", "Reference", nullptr));
        actionDraw_triangle->setText(QApplication::translate("MainWindow", "Draw triangle", nullptr));
        actionDraw_line->setText(QApplication::translate("MainWindow", "Draw line", nullptr));
        actionInvert_circle->setText(QApplication::translate("MainWindow", "Invert circle", nullptr));
        actionCut_image->setText(QApplication::translate("MainWindow", "Cut image", nullptr));
        actionNew_tool->setText(QApplication::translate("MainWindow", "New tool", nullptr));
        actionProperties->setText(QApplication::translate("MainWindow", "Properties", nullptr));
        actionGraphWindow->setText(QApplication::translate("MainWindow", "GraphWindow", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuUtil->setTitle(QApplication::translate("MainWindow", "Util", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
