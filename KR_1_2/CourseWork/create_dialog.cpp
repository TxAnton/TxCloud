#include "create_dialog.h"

createDialog::createDialog(QDialog* parent) : QDialog(parent) {
    setFixedSize(200, 200);
    setWindowTitle("Create");

    button_ok = new QPushButton;
    button_ok->setText("Create");
    button_cancel = new QPushButton;
    button_cancel->setText("Cancel");

    width = new QSpinBox;
    width->setRange(1, 9999);
    width->setValue(1280);

    height = new QSpinBox;
    height->setRange(1, 9999);
    height->setValue(1024);

    text = new QLabel;
    text->setMargin(0);
    text->setText("X");

    fill_color = new QColor;
    fill_color->setRgb(0, 0, 0);
    fill_button = new QPushButton;
    fill_button->setText("Fill color");

    horizontal_layout_0 = new QHBoxLayout;
    horizontal_layout_1 = new QHBoxLayout;
    horizontal_layout_2 = new QHBoxLayout;
    vertical_layout = new QVBoxLayout;

    horizontal_layout_0->addWidget(width);
    horizontal_layout_0->addWidget(text);
    horizontal_layout_0->addWidget(height);

    horizontal_layout_1->addWidget(fill_button);

    horizontal_layout_2->addWidget(button_ok);
    horizontal_layout_2->addWidget(button_cancel);

    vertical_layout->addLayout(horizontal_layout_0);
    vertical_layout->addLayout(horizontal_layout_1);
    vertical_layout->addLayout(horizontal_layout_2);
    setLayout(vertical_layout);

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(fill_button, SIGNAL(clicked()), this, SLOT(set_fill_color()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(sl_create_ok()));
}


createDialog::~createDialog() {
    //delete fill;
    delete width;
    delete height;
    delete text;
    delete fill_color;
    delete fill_button;
    delete horizontal_layout_0;
    delete horizontal_layout_1;
    delete horizontal_layout_2;
    delete vertical_layout;
}


void createDialog::set_fill_color() {
    *fill_color = QColorDialog::getColor();
}


void createDialog::sl_create_ok() {
    emit sig_create(width->value(),height->value(),*fill_color);
}
