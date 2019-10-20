#ifndef QBMPTOOLS_H
#define QBMPTOOLS_H

#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QPoint>
#include <QtDebug>

#include "BMPTools.h"

class My_Image : public QObject {
    Q_OBJECT
public:
    explicit My_Image(QObject *parent = nullptr);
    My_Image(const char* filename, QObject *parrent = nullptr);
    ~My_Image();
    BMPImage* image;
    BMPHeader getHeader();

signals:
    void changed(QPixmap);
    void size_error();
    void info_signal(unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
public slots:
    int open_file(const char* file);
    int save_file(const char* file);
    void createImage(int resX,int rexY, QColor color = QColor(255,255,255));
    QPixmap getPixMap();

    BMPPixel newPixel(uint8_t r, uint8_t g, uint8_t b);
    BMPPixel newPixel(QColor);
    //void DrawCircle(uint32_t x, uint32_t y, uint32_t radius, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC);
    void DrawCircle(QPoint* p, uint32_t radius, uint32_t width, bool filled, QColor BorderC, QColor InnerC);
    //void Fill(BMPPixel colour);
    void Fill(QColor colour);
    //void Cut( int32_t x1, int32_t y1, int32_t x2, int32_t y2);
    void Cut( QPoint* p1, QPoint* p2);
    //void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC);
    void DrawTriangle(QPoint* p1, QPoint* p2,QPoint* p3, uint32_t width, bool filled, QColor BorderC, QColor InnerC);
    //void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, double wd, BMPPixel color);
    void DrawLine(QPoint* p1, QPoint* p2, double wd, QColor color);
    //void InvertCircle(uint32_t x, uint32_t y, uint32_t radius);
    void InvertCircle(QPoint* p, uint32_t radius);

    void Rotate( QPoint* p1, QPoint* p2, int angle);
};



#endif // QBMPTOOLS_H
