#include "info_dialog.h"

infoDialog::infoDialog(QDialog* parent) : QDialog(parent) {
    size1 = new QLabel;
    size1->setText("Size: ");
    size2 = new QLabel;
    size3 = new QLabel;
    size3->setText("byte");
    resol1 = new QLabel;
    resol1->setText("Resolution: ");
    resol2 = new QLabel;
    resol3 = new QLabel;
    resol3->setText("X");
    resol4 = new QLabel;
    bit1 = new QLabel;
    bit1->setText("Bits per pixel: ");
    bit2 = new QLabel;
    h_l_1 = new QHBoxLayout;
    h_l_1->addWidget(size1);
    h_l_1->addWidget(size2);
    h_l_1->addWidget(size3);
    h_l_3 = new QHBoxLayout;
    h_l_3->addWidget(resol1);
    h_l_3->addWidget(resol2);
    h_l_3->addWidget(resol3);
    h_l_3->addWidget(resol4);
    h_l_4 = new QHBoxLayout;
    h_l_4->addWidget(bit1);
    h_l_4->addWidget(bit2);
    v_l = new QVBoxLayout;
    v_l->addLayout(h_l_1);
    //v_l->addLayout(h_l_2);
    v_l->addLayout(h_l_3);
    v_l->addLayout(h_l_4);
    setLayout(v_l);
}


void infoDialog:: set_info(unsigned int size, unsigned int bf, unsigned int width, unsigned int height, unsigned short bit_count) {
    size2->setText(QString::number(size));
    resol2->setText(QString::number(width));
    resol4->setText(QString::number(height));
    bit2->setText(QString::number(bit_count));
}
