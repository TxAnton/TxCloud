#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //TODO add other functions, add//remove highlight, logg everything, list focus, clear list, more info on actions


    //graph_window = new GraphWindow;
    sideslayout = new QHBoxLayout;
    vertlayout  = new QVBoxLayout;
    buttonslayout = new QHBoxLayout;

    central_widget = new QWidget;

    //info_dialog = new infoDialog;

    //_image = new My_Image();
    //triangle_dialog = new triangleDialog;
    //line_dialog = new lineDialog;
    //create_dialog = new createDialog;
    //rot_dialog = new rotDialog;
    //graphicsView = new DrawGraphicsView(_image->getPixMap());
    graphicsView = new GraphGraphicView();
    listViewAL = new ListViewActionLogger();

    butAdd = new QPushButton("Add");
    butRem = new QPushButton("Rem");
    butNew = new QPushButton("New");
    //butFind = new QPushButton("Find");
    butSkip = new QPushButton("Clear");

    spinBox = new QSpinBox();
    spinBox->setFixedSize(85,26);
    //info_dialog->set_info(_image->getHeader().size, _image->getHeader().offset, _image->getHeader().width_px, _image->getHeader().height_px, _image->getHeader().bits_per_pixel);

    buttonslayout->addWidget(butNew);
    buttonslayout->addWidget(butAdd);
    buttonslayout->addWidget(butRem);
    buttonslayout->addWidget(spinBox);
    //buttonslayout->addWidget(butFind);
    buttonslayout->addWidget(butSkip);


    sideslayout->addWidget(graphicsView);
    vertlayout->addWidget(listViewAL);
    vertlayout->addLayout(buttonslayout);
    sideslayout->addLayout(vertlayout);

    //layout->addWidget(listViewAL);
    central_widget->setLayout(sideslayout);
    setCentralWidget(central_widget);

    avl = AVL::AVL<int>();
    avl.logger = listViewAL;

    //connect(this,SIGNAL(sig_turn(Mode)),graphicsView, SLOT(sl_turn(Mode)));
    //connect(this,SIGNAL(sig_cre()),create_dialog, SLOT(exec()));
    //connect(this,SIGNAL(sig_tri()),triangle_dialog, SLOT(exec()));
    //connect(this,SIGNAL(sig_lin()),line_dialog, SLOT(exec()));
    //connect(this,SIGNAL(sig_rot()),rot_dialog,SLOT(exec()));



    //connect(listViewAL->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this,SLOT(slot_listView_selectionChanged(QItemSelection,QItemSelection)));
    connect(listViewAL,SIGNAL(clicked(QModelIndex)),this,SLOT(slot_listView_clicked(QModelIndex)));

    connect(listViewAL,SIGNAL(reselect(int)),this,SLOT(slot_listView_select(int)));

    connect(butAdd,SIGNAL(clicked(bool)),this,SLOT(slot_butAdd_clicked(bool)));
    connect(butRem,SIGNAL(clicked(bool)),this,SLOT(slot_butRem_clicked(bool)));
    connect(butNew,SIGNAL(clicked(bool)),this,SLOT(slot_butNew_clicked(bool)));
    //connect(butFind,SIGNAL(clicked(bool)),this,SLOT(slot_butFind_clicked(bool)));
    connect(butSkip,SIGNAL(clicked(bool)),this,SLOT(slot_butSkip_clicked(bool)));

    //listViewAL->focusInEvent(QFocusEvent);
    //listViewAL->selectedIndexes().

    //connect(this,SIGNAL(sig_inv()),graphicsView, SLOT(sl_turn_inv()));
    //connect(this,SIGNAL(sig_cut()),graphicsView, SLOT(sl_turn_cut()));
/*
    connect(triangle_dialog,SIGNAL(sig_turn_tri(bool, QColor*, QColor*, int)),graphicsView,SLOT(sl_turn_tri(bool, QColor*, QColor*, int)));
    connect(line_dialog,SIGNAL(sig_turn_lin(int ,QColor*)),graphicsView,SLOT(sl_turn_lin(int ,QColor*)));////void sig_turn_rot(double)
    connect(rot_dialog,SIGNAL(sig_turn_rot(int)),graphicsView,SLOT(sl_turn_rot(int)));
    connect(create_dialog,SIGNAL(sig_create(int, int, QColor)),_image,SLOT(createImage(int,int, QColor)));
*/
/*
    connect(graphicsView,SIGNAL(sig_draw_line(QPoint*,QPoint*,double, QColor)),_image,SLOT(DrawLine(QPoint*, QPoint*, double, QColor)));
    connect(graphicsView,SIGNAL(sig_draw_triangle(QPoint*,QPoint*,QPoint*,uint32_t, bool, QColor, QColor)),_image,SLOT(DrawTriangle(QPoint*, QPoint*,QPoint*, uint32_t, bool, QColor, QColor)));
    connect(graphicsView,SIGNAL(sig_draw_invert(QPoint*, uint32_t)),_image,SLOT(InvertCircle(QPoint*, uint32_t)));
    connect(graphicsView,SIGNAL(sig_cut(QPoint*,QPoint*)),_image,SLOT(Cut(QPoint*, QPoint*)));
    connect(graphicsView,SIGNAL(sig_rotate(QPoint*,QPoint*,int)),_image,SLOT(Rotate(QPoint*, QPoint*, int)));
    connect(_image, SIGNAL(info_signal(unsigned int, unsigned int, unsigned int, unsigned int, unsigned short)), info_dialog, SLOT(set_info(unsigned int, unsigned int, unsigned int, unsigned int, unsigned short)));
    connect(_image, SIGNAL(changed(QPixmap)),graphicsView,SLOT(updateImage(QPixmap)));
*/
}


MainWindow::~MainWindow() {
    delete ui;
    //delete image;
    //delete _image;
    delete graphicsView;
    delete sideslayout;
    delete central_widget;
    ///delete info_dialog;
}

/*
void MainWindow::on_actionopen_file_triggered() {
    int error;
    QString name = QFileDialog::getOpenFileName(nullptr, "Open file", "", "*.bmp");
    if (!name.isNull()) {
        error = _image->open_file(name.toUtf8());
        if (error == 0) {
            //graphicsView->updateImage(_image->getPixMap());
        }
        else {
            QMessageBox::critical(this, "ERROR", "Not available format");
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    int error;
    QString name = QFileDialog::getSaveFileName();
    if (!name.isNull()) {
        error = _image->save_file(name.toUtf8() + ".bmp");
        if (error != 0) {
            QMessageBox::critical(this, "ERROR", "Failed to save file");
        }
    }
}

void MainWindow::on_actionCreate_triggered()
{
    emit sig_cre();
}


void MainWindow::size_error_dialog() {
    QMessageBox::critical(this, "ERROR", "Inconsistency in size and width");
}

void MainWindow::on_actionProperties_triggered()
{
    info_dialog->exec();
}


void MainWindow::on_actionDraw_triangle_triggered()
{
    emit sig_tri();
    qDebug() << "emit triangle" << this;
}

void MainWindow::on_actionDraw_line_triggered()
{
    emit sig_lin();
    qDebug() << "emit line" << this;
}

void MainWindow::on_actionInvert_circle_triggered()
{
    emit sig_inv();
    qDebug() << "emit invert" << this;
}

void MainWindow::on_actionCut_image_triggered()
{
    emit sig_cut();
    qDebug() << "emit cut" << this;
}

void MainWindow::on_actionNew_tool_triggered()
{
    emit sig_rot();
    qDebug() << "emit new" << this;
}

void MainWindow::on_actionGraphWindow_triggered()
{
    graph_window->show();

}
*/
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
/*
void MainWindow::slot_butFind_clicked(bool)
{
    avl.find(spinBox->value());
}
*/
void MainWindow::slot_butSkip_clicked(bool)
{
    listViewAL->clear();
    graphicsView->slotDrawAvl(avl);
}


void MainWindow::slot_listView_clicked(QModelIndex index)
{
    //QString Result;//Итоговый результат
/*
    //выдергиваем текст
    int i = index.row();

    std::list<AVL::AVL<int> >::iterator it;
    it = listViewAL->treeList.begin();
    while(i--)it++;
    graphicsView->slotDrawAvl(*(it));
*/
    slot_listView_select(index.row());
    //Result=index.data(Qt::DisplayRole).toString();

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


