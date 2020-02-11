#ifndef LINE_DIALOG_H
#define LINE_DIALOG_H


#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QLayout>
#include <QColorDialog>


class lineDialog : public QDialog {
    Q_OBJECT
public:
    lineDialog(QDialog* parent = nullptr);
    ~lineDialog();

private:
    QPushButton* button_ok;
    QPushButton* button_cancel;
    QLabel* text;
    QSpinBox* width;
    QColor* line_color;
    QPushButton* line_button;
    QHBoxLayout* horizontal_layout_0;
    QHBoxLayout* horizontal_layout_1;
    QHBoxLayout* horizontal_layout_2;
    QVBoxLayout* vertical_layout;
public slots:
    void set_line_color();
    void sl_line_ok();

signals:
    void sig_turn_lin(int ,QColor*);

};


#endif // LINE_DIALOG_H
