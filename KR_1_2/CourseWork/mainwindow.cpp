#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);



    layout = new QHBoxLayout;
    central_widget = new QWidget;

    info_dialog = new infoDialog;

    _image = new My_Image();
    triangle_dialog = new triangleDialog;
    line_dialog = new lineDialog;
    create_dialog = new createDialog;
    rot_dialog = new rotDialog;
    graphicsView = new MyGraphicsView(_image->getPixMap());

    info_dialog->set_info(_image->getHeader().size, _image->getHeader().offset, _image->getHeader().width_px, _image->getHeader().height_px, _image->getHeader().bits_per_pixel);


    layout->addWidget(graphicsView);
    central_widget->setLayout(layout);
    setCentralWidget(central_widget);

    connect(this,SIGNAL(sig_turn(Mode)),graphicsView, SLOT(sl_turn(Mode)));
    connect(this,SIGNAL(sig_cre()),create_dialog, SLOT(exec()));
    connect(this,SIGNAL(sig_tri()),triangle_dialog, SLOT(exec()));
    connect(this,SIGNAL(sig_lin()),line_dialog, SLOT(exec()));
    connect(this,SIGNAL(sig_rot()),rot_dialog,SLOT(exec()));

    connect(this,SIGNAL(sig_inv()),graphicsView, SLOT(sl_turn_inv()));
    connect(this,SIGNAL(sig_cut()),graphicsView, SLOT(sl_turn_cut()));

    connect(triangle_dialog,SIGNAL(sig_turn_tri(bool, QColor*, QColor*, int)),graphicsView,SLOT(sl_turn_tri(bool, QColor*, QColor*, int)));
    connect(line_dialog,SIGNAL(sig_turn_lin(int ,QColor*)),graphicsView,SLOT(sl_turn_lin(int ,QColor*)));////void sig_turn_rot(double)
    connect(rot_dialog,SIGNAL(sig_turn_rot(int)),graphicsView,SLOT(sl_turn_rot(int)));
    connect(create_dialog,SIGNAL(sig_create(int, int, QColor)),_image,SLOT(createImage(int,int, QColor)));

    connect(graphicsView,SIGNAL(sig_draw_line(QPoint*,QPoint*,double, QColor)),_image,SLOT(DrawLine(QPoint*, QPoint*, double, QColor)));
    connect(graphicsView,SIGNAL(sig_draw_triangle(QPoint*,QPoint*,QPoint*,uint32_t, bool, QColor, QColor)),_image,SLOT(DrawTriangle(QPoint*, QPoint*,QPoint*, uint32_t, bool, QColor, QColor)));
    connect(graphicsView,SIGNAL(sig_draw_invert(QPoint*, uint32_t)),_image,SLOT(InvertCircle(QPoint*, uint32_t)));
    connect(graphicsView,SIGNAL(sig_cut(QPoint*,QPoint*)),_image,SLOT(Cut(QPoint*, QPoint*)));
    connect(graphicsView,SIGNAL(sig_rotate(QPoint*,QPoint*,int)),_image,SLOT(Rotate(QPoint*, QPoint*, int)));
    connect(_image, SIGNAL(info_signal(unsigned int, unsigned int, unsigned int, unsigned int, unsigned short)), info_dialog, SLOT(set_info(unsigned int, unsigned int, unsigned int, unsigned int, unsigned short)));
    connect(_image, SIGNAL(changed(QPixmap)),graphicsView,SLOT(updateImage(QPixmap)));
}


MainWindow::~MainWindow() {
    delete ui;
    //delete image;
    delete _image;
    delete graphicsView;
    delete layout;
    delete central_widget;
    delete info_dialog;
}


void MainWindow::on_actionopen_file_triggered() {
    int error;
    QString name = QFileDialog::getOpenFileName(nullptr, "Open file", "", "*.bmp");
    if (!name.isNull()) {
        error = _image->open_file(name.toUtf8());
        if (error == 0) {
            graphicsView->updateImage(_image->getPixMap());
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
