#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    sideslayout = new QHBoxLayout;
    vertlayout  = new QVBoxLayout;
    buttonslayout = new QHBoxLayout;

    central_widget = new QWidget;

    graphicsView = new GraphGraphicView();
    listViewAL = new ListViewActionLogger();

    butAdd = new QPushButton("Add");
    butRem = new QPushButton("Rem");
    butNew = new QPushButton("New");
    butSkip = new QPushButton("Clear");

    spinBox = new QSpinBox();
    spinBox->setFixedSize(85,26);

    buttonslayout->addWidget(butNew);
    buttonslayout->addWidget(butAdd);
    buttonslayout->addWidget(butRem);
    buttonslayout->addWidget(spinBox);
    buttonslayout->addWidget(butSkip);

    sideslayout->addWidget(graphicsView);
    vertlayout->addWidget(listViewAL);
    vertlayout->addLayout(buttonslayout);
    sideslayout->addLayout(vertlayout);

    central_widget->setLayout(sideslayout);
    setCentralWidget(central_widget);

    avl = AVL::AVL<int>();
    avl.logger = listViewAL;

    connect(listViewAL,SIGNAL(clicked(QModelIndex)),this,SLOT(slot_listView_clicked(QModelIndex)));

    connect(listViewAL,SIGNAL(reselect(int)),this,SLOT(slot_listView_select(int)));

    connect(butAdd,SIGNAL(clicked(bool)),this,SLOT(slot_butAdd_clicked(bool)));
    connect(butRem,SIGNAL(clicked(bool)),this,SLOT(slot_butRem_clicked(bool)));
    connect(butNew,SIGNAL(clicked(bool)),this,SLOT(slot_butNew_clicked(bool)));
    //connect(butFind,SIGNAL(clicked(bool)),this,SLOT(slot_butFind_clicked(bool)));
    connect(butSkip,SIGNAL(clicked(bool)),this,SLOT(slot_butSkip_clicked(bool)));

}


MainWindow::~MainWindow() {
    delete ui;
    delete graphicsView;
    delete sideslayout;
    delete central_widget;
    ///delete info_dialog;
}

void MainWindow::slot_butAdd_clicked(bool)
{
    avl.insert(spinBox->value());
    //spinBox->setValue(spinBox->value()+1);

}

void MainWindow::slot_butRem_clicked(bool)
{
    avl.remove(spinBox->value());
    //spinBox->setValue(spinBox->value()+1);
}

void MainWindow::slot_butNew_clicked(bool)
{
    avl.destroy();
    avl = AVL::AVL<int>();
    avl.logger = listViewAL;
    listViewAL->clear();
    graphicsView->slotDrawAvl(avl);
}

void MainWindow::slot_butSkip_clicked(bool)
{
    listViewAL->clear();
    graphicsView->slotDrawAvl(avl);
}

void MainWindow::slot_listView_clicked(QModelIndex index)
{
    slot_listView_select(index.row());

}

void MainWindow::slot_listView_selectionChanged(QItemSelection first, QItemSelection second)
{
    slot_listView_select( second.indexes().at(0).row() );
}

void MainWindow::slot_listView_select(int i)
{
    if(i<0)return;
    std::list<AVL::AVL<int> >::iterator it;
    it = listViewAL->treeList.begin();
    while(i--)it++;
    graphicsView->slotDrawAvl(*(it));
}


