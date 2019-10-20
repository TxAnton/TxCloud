#include "qbmptools.h"

#include <QImage>
#include <QColor>



My_Image::My_Image(QObject *parent) : QObject(parent) {
    image = 0;
    this->createImage(1280,1024);
}


My_Image::~My_Image() {

}

int My_Image::open_file(const char* file) {

    if(image) free(image);
    image = BMPRead(file);
    qDebug() << "img ok";
    if(!image)return -1;

    if (image->header.reserved1 != 0 ||
            image->header.reserved2 != 0 ||
            //(image->header.dib_header_size != 40) ||
            //image->header.offset != 54 ||
            image->header.width_px < 1 || image->header.width_px > 10000 ||
            image->header.height_px < 1 || image->header.height_px > 10000 ||
            image->header.compression != 0 ||
            image->header.bits_per_pixel != 24) {
        return -1;
    }

    emit info_signal(image->header.size,image->header.offset, image->header.width_px, image->header.height_px, image->header.bits_per_pixel);
    return 0;
}


int My_Image::save_file(const char* file) {

    return BMPWrite(file,image);

}

BMPHeader My_Image::getHeader(){
    return image->header;
}

QPixmap My_Image::getPixMap() {
    QColor pixColor;
    QImage *img = new QImage(image->header.width_px, image->header.height_px, QImage::Format_RGB32);
    for (int i = 0; i < image->header.height_px; i++) {
        for (int j = 0; j < image->header.width_px; j++) {
            BMPPixel px = BMPGetPixel(image, j,i);
            pixColor.setRed(px.r);
            pixColor.setGreen(px.g);
            pixColor.setBlue(px.b);
            img->setPixel(j, i, pixColor.rgb());
        }
    }
    QPixmap tmp;
    tmp.convertFromImage(*img);
    delete img;
    return tmp;
}


void My_Image::createImage(int resX,int rexY,QColor color) {
    if(image)free(image);
    image = newBMPImage(0,resX,rexY);
    Fill(color);
    emit info_signal(image->header.size,image->header.offset, image->header.width_px, image->header.height_px, image->header.bits_per_pixel);
    emit changed(getPixMap());

}

My_Image::My_Image(const char* filename, QObject *parrent) : QObject(parrent){
    this->open_file(filename);
}

BMPPixel My_Image::newPixel(uint8_t r, uint8_t g, uint8_t b){
    return toPixel(r,g,b);
}
BMPPixel My_Image::newPixel(QColor c){
    return toPixel(c.red(),c.green(),c.blue());
}
//void DrawCircle(uint32_t x, uint32_t y, uint32_t radius, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC);
void My_Image::DrawCircle(QPoint* p, uint32_t radius, uint32_t width, bool filled, QColor BorderC, QColor InnerC){
    BMPDrawCircle(image,p->x(),p->y(),radius,width,filled,newPixel(BorderC), newPixel(InnerC));
    emit changed(this->getPixMap());
}
//void Fill(BMPPixel colour);
void My_Image::Fill(QColor colour){
    BMPFill(image,newPixel(colour));
    emit changed(this->getPixMap());
}
//void Cut( int32_t x1, int32_t y1, int32_t x2, int32_t y2);
void My_Image::Cut( QPoint* p1, QPoint* p2){
    BMPImage* cutImg = BMPCut(image,p1->x(),p1->y(),p2->x(),p2->y());
    free(image);
    image = cutImg;
    emit changed(this->getPixMap());
}
//void DrawTriangle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC);
void My_Image::DrawTriangle(QPoint* p1, QPoint* p2,QPoint* p3, uint32_t width, bool filled, QColor BorderC, QColor InnerC){
    BMPDrawTriangle(image,p1->x(),p1->y(),p2->x(),p2->y(),p3->x(),p3->y(),width,filled,newPixel(BorderC),newPixel(InnerC));
    emit changed(this->getPixMap());
}
//void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, double wd, BMPPixel color);
void My_Image::DrawLine(QPoint* p1, QPoint* p2, double wd, QColor color){
    BMPDrawLine(image,p1->x(),p1->y(),p2->x(),p2->y(),wd,newPixel(color));
    emit changed(this->getPixMap());
}
//void InvertCircle(uint32_t x, uint32_t y, uint32_t radius);
void My_Image::InvertCircle(QPoint* p, uint32_t radius){
    BMPInvertCircle(image,p->x(),p->y(),radius);
    emit changed(this->getPixMap());
}

void My_Image::Rotate( QPoint* p1, QPoint* p2, int angle){
    qDebug()<<"ROTATE";
    BMPImage* _img = BMPRotate(image,p1->x(),p1->y(),p2->x(),p2->y(),angle);
    free(image);
    image = _img;
    //BMPRotate(image,p1->x(),p1->y(),p2->x(),p2->y(),angle);
    emit changed(this->getPixMap());
    //BOOOOOOOOOOOO
}
