#include "triangle_dialog.h"

triangleDialog::triangleDialog(QDialog* parent) : QDialog(parent) {
    setFixedSize(200, 200);
    setWindowTitle("Triangle");

    button_ok = new QPushButton;
    button_ok->setText("Ok");
    button_cancel = new QPushButton;
    button_cancel->setText("Cancel");

    fill = new QCheckBox;
    fill->setText("Fill");
    isFill = false;
    width = new QSpinBox;
    width->setRange(0, 999);
    width->setValue(10);
    text = new QLabel;
    text->setText("Line width");

    line_color = new QColor;
    line_color->setRgb(0, 0, 0);
    line_button = new QPushButton;
    line_button->setText("Line color");
    fill_color = new QColor;
    fill_color->setRgb(0, 0, 0);
    fill_button = new QPushButton;
    fill_button->setText("Fill color");

    horizontal_layout_0 = new QHBoxLayout;
    horizontal_layout_1 = new QHBoxLayout;
    horizontal_layout_2 = new QHBoxLayout;
    vertical_layout = new QVBoxLayout;

    horizontal_layout_0->addWidget(text);
    horizontal_layout_0->addWidget(width);
    horizontal_layout_0->addWidget(fill);

    horizontal_layout_1->addWidget(line_button);
    horizontal_layout_1->addWidget(fill_button);

    horizontal_layout_2->addWidget(button_ok);
    horizontal_layout_2->addWidget(button_cancel);

    vertical_layout->addLayout(horizontal_layout_0);
    vertical_layout->addLayout(horizontal_layout_1);
    vertical_layout->addLayout(horizontal_layout_2);
    setLayout(vertical_layout);

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(line_button, SIGNAL(clicked()), this, SLOT(set_line_color()));
    connect(fill_button, SIGNAL(clicked()), this, SLOT(set_fill_color()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(sl_triangle_ok()));
}


triangleDialog::~triangleDialog() {
    delete fill;
    delete width;
    delete text;
    //delete line_color;
    delete line_button;
    //delete fill_color;
    delete fill_button;
    delete horizontal_layout_0;
    delete horizontal_layout_1;
    delete horizontal_layout_2;
    delete vertical_layout;
}

void triangleDialog::set_line_color() {
    *line_color = QColorDialog::getColor();
}


void triangleDialog::set_fill_color() {
    *fill_color = QColorDialog::getColor();
}


void triangleDialog::sl_triangle_ok() {
    if (fill->isChecked())
        isFill = true;
    else
        isFill = false;
    emit sig_turn_tri(isFill, line_color, fill_color, width->value());
}
