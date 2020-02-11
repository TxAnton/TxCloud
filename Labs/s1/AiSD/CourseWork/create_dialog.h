#ifndef CREATE_DIALOG_H
#define CREATE_DIALOG_H


#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QLayout>
#include <QColorDialog>


class createDialog : public QDialog {
    Q_OBJECT
public:
    createDialog(QDialog* parent = nullptr);
    ~createDialog();

private:
    QPushButton* button_ok;
    QPushButton* button_cancel;
    QLabel* text;
    QSpinBox* width;
    QSpinBox* height;
    QColor* fill_color;
    QPushButton* fill_button;
    QHBoxLayout* horizontal_layout_0;
    QHBoxLayout* horizontal_layout_1;
    QHBoxLayout* horizontal_layout_2;
    QVBoxLayout* vertical_layout;
public slots:
    void set_fill_color();
    void sl_create_ok();

signals:
    void sig_create(int, int, QColor);
};


#endif // CREATE_DIALOG_H
