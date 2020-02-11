#include "rot_dialog.h"

rotDialog::rotDialog(QDialog* parent) : QDialog(parent) {
    setFixedSize(200, 200);
    setWindowTitle("Triangle");

    button_ok = new QPushButton;
    button_ok->setText("Ok");
    button_cancel = new QPushButton;
    button_cancel->setText("Cancel");

    angle = new QSpinBox;
    angle->setRange(0, 999);
    angle->setValue(10);
    text = new QLabel;
    text->setText("Line width");
/*
    line_color = new QColor;
    line_color->setRgb(0, 0, 0);
    line_button = new QPushButton;
    line_button->setText("Line color");
*/
    horizontal_layout_0 = new QHBoxLayout;
    horizontal_layout_1 = new QHBoxLayout;
    horizontal_layout_2 = new QHBoxLayout;
    vertical_layout = new QVBoxLayout;

    horizontal_layout_0->addWidget(text);
    horizontal_layout_0->addWidget(angle);

    //horizontal_layout_1->addWidget(line_button);

    horizontal_layout_2->addWidget(button_ok);
    horizontal_layout_2->addWidget(button_cancel);

    vertical_layout->addLayout(horizontal_layout_0);
    vertical_layout->addLayout(horizontal_layout_1);
    vertical_layout->addLayout(horizontal_layout_2);
    setLayout(vertical_layout);

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(close()));
    //connect(line_button, SIGNAL(clicked()), this, SLOT(set_line_color()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(sl_rot_ok()));
}


rotDialog::~rotDialog() {
    //delete fill;
    delete angle;
    delete text;
    //delete line_color;
    //delete line_button;
    delete horizontal_layout_0;
    delete horizontal_layout_1;
    delete horizontal_layout_2;
    delete vertical_layout;
}
/*
void rotDialog::set_line_color() {
    *line_color = QColorDialog::getColor();
}*/

void rotDialog::sl_rot_ok() {
    emit sig_turn_rot(angle->value());
}


