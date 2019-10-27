#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QTextBrowser>
#include <QMessageBox>
#include <QListView>
#include <QtDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QButtonGroup>
#include <QPushButton>

#include "qbmptools.h"

//#include"graph_window.h"

#include "graph_window.h"
#include "info_dialog.h"
//#include "drawgraphicsview.h"
#include "graphgraphicview.h"
#include "triangle_dialog.h"
#include "line_dialog.h"
#include "rot_dialog.h"
#include "create_dialog.h"
#include "listviewactionlogger.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    //void sig_turn(Mode);
    void sig_cut();
    void sig_tri();
    void sig_lin();
    void sig_inv();
    void sig_cre();
    void sig_rot();

private slots:
    void on_actionopen_file_triggered();

    void on_actionSave_triggered();

    void on_actionCreate_triggered();

    void size_error_dialog();

    void on_actionProperties_triggered();

    void on_actionDraw_triangle_triggered();

    void on_actionDraw_line_triggered();

    void on_actionInvert_circle_triggered();

    void on_actionCut_image_triggered();

    void on_actionNew_tool_triggered();

    void on_actionGraphWindow_triggered();

    void slot_butAdd_clicked(bool);

    void slot_listView_clicked(QModelIndex);


private:
    Ui::MainWindow *ui;
    //DrawGraphicsView *graphicsView;
    GraphGraphicView *graphicsView;
    My_Image *_image;
    QHBoxLayout *sideslayout;
    QVBoxLayout *vertlayout;
    QHBoxLayout *buttonslayout;

    QWidget *central_widget;

    QPixmap stdPixmap;
    QListView *lstVw;
    GraphWindow* graph_window;
    ListViewActionLogger* listViewAL;
    QPushButton* butNew;
    QPushButton* butAdd;
    QPushButton* butRem;
    QPushButton* butFind;
    QPushButton* butStep;

    QSpinBox* spinBox;

    infoDialog* info_dialog;
    triangleDialog* triangle_dialog;
    lineDialog* line_dialog;
    createDialog* create_dialog;
    rotDialog* rot_dialog;

    AVL::AVL<int> avl;


};

#endif // MAINWINDOW_H
