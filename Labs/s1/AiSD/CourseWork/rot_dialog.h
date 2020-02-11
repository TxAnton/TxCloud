#ifndef ROT_DIALOG_H
#define ROT_DIALOG_H


#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QLayout>
#include <QColorDialog>


class rotDialog : public QDialog {
    Q_OBJECT
public:
    rotDialog(QDialog* parent = nullptr);
    ~rotDialog();

private:
    QPushButton* button_ok;
    QPushButton* button_cancel;
    QLabel* text;
    QSpinBox* angle;
    //QColor* line_color;
    //QPushButton* line_button;
    QHBoxLayout* horizontal_layout_0;
    QHBoxLayout* horizontal_layout_1;
    QHBoxLayout* horizontal_layout_2;
    QVBoxLayout* vertical_layout;
public slots:
    //void set_line_color();
    void sl_rot_ok();

signals:
    void sig_turn_rot(int);

};


#endif // ROT_DIALOG_H
