#ifndef INFO_DIALOG_H
#define INFO_DIALOG_H


#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <string>


class infoDialog : public QDialog{
    Q_OBJECT
public:
    infoDialog(QDialog* parent = nullptr);
private:
    QLabel* size1;
    QLabel* size2;
    QLabel* size3;
    //QLabel* version1;
    //QLabel* version2;
    QLabel* resol1;
    QLabel* resol2;
    QLabel* resol3;
    QLabel* resol4;
    QLabel* bit1;
    QLabel* bit2;
    QHBoxLayout* h_l_1;
    QHBoxLayout* h_l_2;
    QHBoxLayout* h_l_3;
    QHBoxLayout* h_l_4;
    QVBoxLayout* v_l;
public slots:
    void set_info(unsigned int size, unsigned int bf, unsigned int width, unsigned int height, unsigned short bpp);
};

#endif // INFO_DIALOG_H
