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
#include <QSpinBox>

#include "graphgraphicview.h"
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

private slots:
    void slot_butAdd_clicked(bool);
    void slot_butRem_clicked(bool);
    void slot_butNew_clicked(bool);
    //void slot_butFind_clicked(bool);
    void slot_butSkip_clicked(bool);

    void slot_listView_clicked(QModelIndex);
    void slot_listView_selectionChanged(QItemSelection,QItemSelection);
    void slot_listView_select(int);


private:
    Ui::MainWindow *ui;
    GraphGraphicView *graphicsView;
    QHBoxLayout *sideslayout;
    QVBoxLayout *vertlayout;
    QHBoxLayout *buttonslayout;

    QWidget *central_widget;

    QPixmap stdPixmap;
    QListView *lstVw;
    ListViewActionLogger* listViewAL;
    QPushButton* butNew;
    QPushButton* butAdd;
    QPushButton* butRem;
    QPushButton* butSkip;

    QSpinBox* spinBox;

    AVL::AVL<int> avl;
};

#endif // MAINWINDOW_H
