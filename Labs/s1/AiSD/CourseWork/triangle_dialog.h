#ifndef TRIANGLE_DIALOG_H
#define TRIANGLE_DIALOG_H


#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QLayout>
#include <QColorDialog>


class triangleDialog : public QDialog {
    Q_OBJECT
public:
    triangleDialog(QDialog* parent = nullptr);
    ~triangleDialog();

private:
    QPushButton* button_ok;
    QPushButton* button_cancel;
    QCheckBox* fill;
    QLabel* text;
    QSpinBox* width;
    QColor* line_color;
    QPushButton* line_button;
    QColor* fill_color;
    QPushButton* fill_button;
    QHBoxLayout* horizontal_layout_0;
    QHBoxLayout* horizontal_layout_1;
    QHBoxLayout* horizontal_layout_2;
    QVBoxLayout* vertical_layout;
    bool isFill;
public slots:
    void set_line_color();
    void set_fill_color();
    void sl_triangle_ok();

signals:
    void sig_turn_tri(bool, QColor*, QColor*, int);
};


#endif // TRIANGLE_DIALOG_H
