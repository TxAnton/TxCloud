#pragma once
#ifndef BMP_TOOLS
#define BMP_TOOLS


#ifdef _WIN32
#define WIN
#endif

#ifdef _MSC_VER
#define VS
#endif

//#ifdef VS

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
/*
#include<cstdio>
#include<cstdlib>
#include<cstdint>
#include<cmath>
using namespace std;
*/

#pragma pack(push,1)


/*
#ifdef WIN
typedef unsigned long long 	uint64_t;
typedef unsigned char 		uint8_t;
typedef unsigned short int 	uint16_t;
typedef unsigned int 		uint32_t;
typedef short int 			int16_t;
typedef int 				int32_t;
#endif
*/

//#define OFF 1
#define BMPHeight(p_img) ( ((BMPHeader*)(p_img))->height_px )										//Height of BMP picture in pixels <safe>
#define BMPWidth(p_img) ( ((BMPHeader*)(p_img))->width_px )											//Width of BMP picture in pixels <safe>
#define BMPSize(p_img) ( ((BMPHeader*)(p_img))->size )												//Size of BMP picture in bytes <safe>
#define TAB(p_img) ( (uint8_t*)(p_img) )															//BMPImage* -> uint8_t* <safe>
#define HEAD(p_img) ( (BMPHeader*)(p_img) )															//BMPImage* -> BMPHeader* <safe>
#define YY(table,y) ( BMPHeight(table)-(y)-1 )														//Inverted y(conted from the end) in order to use conventional coordinate system <safe>
//#define YOFF(table,y) ( YY(table,y) * BMPWidth(table) * 3 + YY(table,(y)) * (BMPWidth(table)%4) )	//Offset based on y(vertical) <safe>
#define YOFF(table,y) ( YY(table,y) *( BMPWidth(table) * 3 + (BMPWidth(table)%4) ) )                 //Offset based on y(vertical) <safe>
#define XOFF(table,x) ( (uint32_t)( (x) * 3 ) )														//Offset based on x(xorisontal) <safe>
#define OFFSET(t) ( ((uint8_t*)(t)) + ((BMPHeader*)(t))->offset )									//54 bytes of header <safe>
#define PX(table,x,y) ( (BMPPixel*)(OFFSET(table) + YOFF(table,(y)) + XOFF(table,(x))) )			//Alltogether gets beginning of 3-byte pixel <safe>
//(height-y-1)
//SAVE STUFFFF
//OFF WIDTH%4
//height 	(((BMPHeader*)table)->height_px)
//wigth 	(((BMPHeader*)table)->width_px)
//offset (table + ((BMPHeader*)table)->offset)
//coord ( (YY(y) * BMPWidth(table) + YY(y) * OFF)+ (x * 3) )
	//#define PX(table,x,y) ( (uint8_t*)((table + ((BMPHeader*)table)->offset) + ( (((((BMPHeader*)table)->height_px)-y-1) * (((BMPHeader*)table)->width_px) + y * OFF)+ (x * 3) )) )
//( (uint8_t*)((table + ((BMPHeader*)table)->offset) + ( (((((BMPHeader*)table)->height_px)-y-1) * (((BMPHeader*)table)->width_px) + y * OFF)+ (x * 3) )) )

#define _min(a,b) ( (a)<(b)?(a):(b) )                               //<safe>
#define _max(a,b) ( (a)>(b)?(a):(b) )                               //<safe>
#define _abs(x) ((x)<0?-(x):(x))                                    //<safe>
#define _sqr(x) ((x)*(x))                                           //<safe>
#define _mannDist(x1,y1,x2,y2) ( _abs((x2)-(x1))+_abs((y2)-(y1)) )  //<safe>
#define _sqDist(x1,y1,x2,y2) ( _sqr((x2)-(x1))+_sqr((y2)-(y1)) )    //Square distance bitween points (x1,y1) and (x2,y2) <safe>
#define _inBound(val,bound) ( (val)>=0&&(val)<(bound) )             //<safe>
#define _inBounds(val,b1,b2) ( (val)>=(b1)&&(val)<(b2) )            //<safe>
#define _toBounds(val,b1,b2) ( _min(_max(val,b1),(b2)) )            //<safe>

typedef struct {              	// Total: 54 bytes
	uint16_t  type;             //00-02	// Magic identifier: 0x4d42
	uint32_t  size;             //02-06	// File size in bytes
	uint16_t  reserved1;        //06-08	// Not used
	uint16_t  reserved2;        //09-0a	// Not used	
	uint32_t  offset;           //0a-0e	// Offset to image data in bytes from beginning of file (54 bytes)
	uint32_t  dib_header_size;  //0e-12	// DIB Header size in bytes (40 bytes)
	int32_t   width_px;         //12-16	// Width of the image
	int32_t   height_px;        //16-1a	// Height of image
	uint16_t  num_planes;       //1a-1c	// Number of color planes
	uint16_t  bits_per_pixel;   //1c-1e	// Bits per pixel
	uint32_t  compression;      //1e-22	// Compression type
	uint32_t  image_size_bytes; //22-26	// Image size in bytes
	int32_t   x_resolution_ppm; //26-2a	// Pixels per meter
	int32_t   y_resolution_ppm; //2a-2e	// Pixels per meter
	uint32_t  num_colors;       //2e-32	// Number of colors  
	uint32_t  important_colors; //32-36	// Important colors 
} BMPHeader;

typedef struct {
	BMPHeader header;
    uint8_t* data;
} BMPImage;

typedef struct {
	uint8_t b;
	uint8_t g;
	uint8_t r;
} BMPPixel;


static BMPImage* BMPRead(const char *name);																//Read BMP(or whatever else) file
static int BMPWrite(const char *name, BMPImage* data);													//Write data into file
static void BMPPrintBytes(BMPImage* image, uint8_t clw, uint8_t cln);										//Print bytes in table form
static void BMPPrintInfo(BMPImage* image);																	//Print info of BMP picture
static BMPImage * newBMPImage(BMPHeader * header, uint32_t width, uint32_t height);
static BMPPixel BMPGetPixel(BMPImage* image, uint32_t x, uint32_t y);										//Get BMPPixel on (x,y) coordinates
static int BMPSetPixel(BMPImage* image, uint32_t x, uint32_t y, BMPPixel px);								//Set BMPPixel on (x,y) coordinates
static BMPPixel toPixel(uint8_t r, uint8_t g, uint8_t b);
static void BMPDrawCircle(BMPImage* image, uint32_t x, uint32_t y, uint32_t radius, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC);
static void BMPFill(BMPImage* image, BMPPixel colour);
static BMPImage* BMPCut(BMPImage* image, int32_t x1, int32_t y1, int32_t x2, int32_t y2);
static void BMPDrawTriangle(BMPImage* image, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC);
static void BMPDrawLine(BMPImage* image, int32_t x1, int32_t y1, int32_t x2, int32_t y2, double wd, BMPPixel color);
static void BMPInvertCircle(BMPImage* image, uint32_t x, uint32_t y, uint32_t radius);
//void radmad(uint8_t* table);







BMPImage* BMPRead(const char *name)
{
	
	FILE *fl;
#ifndef VS		
	fl = fopen(name, "rb");
#else
	fopen_s(&fl, name, "rb");
#endif
    if(fl)
    {
        fseek(fl, 0, SEEK_END);
        size_t len = ftell(fl);
        uint8_t *ret = (uint8_t*)malloc(len);
        fseek(fl, 0, SEEK_SET);
        fread(ret, 1, len, fl);
        fclose(fl);
        return (BMPImage*)ret;
    } else
    {
        fclose(fl);
        return nullptr;
    }

}

int BMPWrite(const char *name, BMPImage* data)
{
	FILE * ptrFile;
#ifndef VS
	ptrFile = fopen(name, "wb");
#else
	fopen_s(&ptrFile, name, "wb");
#endif
    if(!ptrFile)return -1;
	fwrite(data, 1, BMPSize(data), ptrFile);
	fclose(ptrFile);
    return 0;
}

void BMPPrintBytes(BMPImage* image, uint8_t clw, uint8_t cln) {
	uint8_t* x = (uint8_t*)image;
	uint32_t size = *((uint32_t*)(x + 2));
	printf("        ");//0| 1| 2| 3| 4| 5| 6| 7| 8| 9| a| b| c| d| e| f|\n");
	for (int i = 0; i < cln; i++) {
		printf(i % (clw >> 3) ? "%2.1x" : "|%2.1x", i);
	}
	printf("\n");
	for (uint8_t* it = x; it != x + size; it++) {
		if (!((it - x) % cln))
			printf("\n%8.8x ", (it - x));
		printf("%2.2hhx", *it);
		if (!((it - x + 1) % (clw >> 3)))printf(" ");
	}
	return;
}

void BMPPrintInfo(BMPImage* image) {
	BMPHeader* header = (BMPHeader*)image;
	printf("\ntype %u\n", header->type);
	printf("size %u\n", header->size);
	printf("reserved1 %u\n", header->reserved1);
	printf("reserved2 %u\n", header->reserved2);
	printf("offset %u\n", header->offset);
	printf("dib_header_size %u\n", header->dib_header_size);
	printf("width_px %u\n", header->width_px);
	printf("height_px %u\n", header->height_px);
	printf("num_planes %u\n", header->num_planes);
	printf("bits_per_pixel %u\n", header->bits_per_pixel);
	printf("compression %u\n", header->compression);
	printf("image_size_bytes %u\n", header->image_size_bytes);
	printf("x_resolution_ppm %u\n", header->x_resolution_ppm);
	printf("y_resolution_ppm %u\n", header->y_resolution_ppm);
	printf("num_colors %u\n", header->num_colors);
	printf("important_colors %u\n", header->important_colors);
	//printf("Dim %uX%u\n", header->width_px, header->height_px);
	//printf("BPP %hu\n", header->bits_per_pixel);
}

BMPImage* newBMPImage(BMPHeader* header, uint32_t width, uint32_t height) {
	size_t size = 54 + height * (width * 3 + width % 4);
    BMPImage* image = (BMPImage*)calloc(size,1);
	if (header) {
		image->header = *header;
		image->header.size = size;
		image->header.width_px = width;
		image->header.height_px = height;
		image->header.image_size_bytes = size;
	}
	else {
		image->header.type = 19778;
		image->header.size = size;
		image->header.reserved1 = 0;
		image->header.reserved2 = 0;
		image->header.offset = 54;
		image->header.dib_header_size = 40;
		image->header.width_px = width;
		image->header.height_px = height;
		image->header.num_planes = 1;
		image->header.bits_per_pixel = 24;
		image->header.compression = 0;
		image->header.image_size_bytes = size;
		image->header.x_resolution_ppm = 0;
		image->header.y_resolution_ppm = 0;
		image->header.num_colors = 0;
		image->header.important_colors = 0;
	}
	
	return image;
}

BMPPixel BMPGetPixel(BMPImage* image, uint32_t x, uint32_t y) {
	//VALIDATE
    //x = _toBounds(x,0,image->header.width_px-1);
    //y = _toBounds(y,0,image->header.height_px-1);

	return *PX(TAB(image), x, y);
}

int BMPSetPixel(BMPImage* image, uint32_t x, uint32_t y, BMPPixel px) {
    //x = _toBounds(x,0,image->header.width_px-1);
    //y = _toBounds(y,0,image->header.height_px-1);
	*PX(TAB(image), x, y) = px;
	return 0;
}

BMPPixel toPixel(uint8_t r, uint8_t g, uint8_t b) {
	BMPPixel px = {b,g,r};
	return px;
}

void BMPDrawCircle(BMPImage* image, uint32_t x, uint32_t y, uint32_t radius, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC) {
	int wid = BMPWidth(TAB(image));
	uint32_t  hei = BMPHeight(TAB(image));
	for (uint32_t i = 0; i < wid; i++) {
		for (uint32_t j = 0; j < hei; j++) {
			if (_sqDist(i, j, x, y) < _sqr(radius)) {//Within outer circle
				if (_sqDist(i, j, x, y) < _sqr(radius - width)) {//Within inner circle
					if (filled) {
						BMPSetPixel(image, i, j, InnerC);
					}
				}	
				else {//Border
					BMPSetPixel(image, i, j, BorderC);
				}
			}
		}
	}
}

static void BMPFill(BMPImage* image, BMPPixel colour) {
	int wid = BMPWidth(TAB(image));
	uint32_t  hei = BMPHeight(TAB(image));
	for (uint32_t i = 0; i < wid; i++) {
		for (uint32_t j = 0; j < hei; j++) {
			*PX(TAB(image), i, j) = colour;
		}
	}
}

void BMPInvertCircle(BMPImage* image, uint32_t x, uint32_t y, uint32_t radius) {
	int wid =  BMPWidth(TAB(image));
	uint32_t  hei = BMPHeight(TAB(image));
	for (uint32_t i = 0; i < wid; i++) {
		for (uint32_t j = 0; j < hei; j++) {
			if (_sqDist(i, j, x, y) < _sqr(radius)) {//Within outer circle
				BMPPixel* px = PX(TAB(image), i, j);
				*px = toPixel(px->r ^255, px->g ^255, px->b ^255);
				//*px = toPixel(255-px->r, 255-px->g, 255-px->b);
			}
		}
	}
}

BMPImage* BMPCut(BMPImage* image, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    BMPImage* cutImg = newBMPImage((BMPHeader*)image,_abs(x2 - x1), _abs(y2 - y1));
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			*PX(TAB(cutImg), i - x1, j - y1) = *PX(TAB(image), i, j);
		}
	}
	return cutImg;
}

#define _tg(x1,y1,x2,y2) ( (double)(((double)(y2)-(double)(y1)) / ((double)(x2)-(double)(x1))) )	//tangent of line through (x1,y1) , (x2,y2)		<safe>
#define _y0(x1,y1,x2,y2) ( (y1) - ((x1) * _tg(x1,y1,x2,y2)) )										//y0 of line through (x1,y1) , (x2,y2)			<safe>
static uint8_t _above(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x, int32_t y)                //if (x2,y2) above line (x * tg + y0)
{
	double k = _tg(x1, y1, x2, y2);
	double b = ((y1)-((x1)* k));
	return (((x) * (k)) + (b)) < (y);
}
#define _coSided(x1,y1,x2,y2,x3,y3,x4,y4) ( _above(x1, y1, x2, y2, x3, y3) == _above(x1, y1, x2, y2, x4, y4) ) //if points (x3,y3),(x4,y4) on one side of line through (x1,y1) , (x2,y2)
#define _allCoSided(x1,y1,x2,y2,x3,y3,x,y) ( _coSided(x1,y1,x2,y2,x3,y3,x,y) && _coSided(x1,y1,x3,y3,x2,y2,x,y) && _coSided(x2,y2,x3,y3,x1,y1,x,y) )
//#define _rightHaPlane(x1,y1,x2,y2) ( (_tg(x1,y1,x2,y2)>0)^((y2)<(y1)) )								//if (x2,y2) is to the right from (x1,y1)		<safe>

static double _sqDistToLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x, int32_t y)	//Square distance from point (x,y) to line through (x1,y1) , (x2,y2)
{ 
	double sq_k = _tg(x1, y1, x2, y2); double sq_y0 = ((y1)-((x1)* sq_k));
	return _sqr(sq_k*x - y + sq_y0) / (sq_k*sq_k + 1);
}
#define _inDist(x1,y1,x2,y2,x,y,d) ( _sqDistToLine(x1,y1,x2,y2,x,y) <= _sqr(d) ) //If point (x,y) no farther from line through (x1,y1), (x2,y2) than d
#define _anyInDist(x1,y1,x2,y2,x3,y3,x,y,d) ( _inDist(x1,y1,x2,y2,x,y,d) || _inDist(x1,y1,x3,y3,x,y,d) || _inDist(x2,y2,x3,y3,x,y,d) )

//double tg(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {return _tg(x1, y1, x2, y2);}
//int32_t y0(int32_t x1, int32_t y1, int32_t x2, int32_t y2) { return _y0(x1, y1, x2, y2); }
//int32_t above(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x, int32_t y) { return _above(x1, y1, x2, y2, x, y); }
//int32_t rightHaPlane(int32_t x1, int32_t y1, int32_t x2, int32_t y2) { return _rightHaPlane(x1, y1, x2, y2); }

void BMPDrawTriangle(BMPImage* image, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC) {
	int32_t x_min = _min(_min(x1, x2), x3);
	int32_t x_max = _max(_max(x1, x2), x3);
	int32_t y_min = _min(_min(y1, y2), y3);
	int32_t y_max = _max(_max(y1, y2), y3);

    int32_t lb = _max(x_min,0);//l_border
    int32_t rb = _min(x_max,BMPWidth(image));//r_border
    int32_t ub = _max(y_min,0);//u_border
    int32_t db = _min(y_max,BMPHeight(image));//d_border
    for (int i = lb; i < rb; i++) {
        for (int j = ub; j < db; j++) {
			if (_allCoSided(x1, y1, x2, y2, x3, y3, i, j)) {
				if (!_anyInDist(x1, y1, x2, y2, x3, y3, i, j, width)) {//inside
					if(filled)BMPSetPixel(image, i, j, InnerC);
				}
				else {//border
					BMPSetPixel(image, i, j, BorderC);
				}
			}
		}
	}
}

void BMPDrawLine(BMPImage* image, int32_t x1, int32_t y1, int32_t x2, int32_t y2, double wd, BMPPixel color) {
	int32_t x_min = _min(x1, x2) -wd;
	int32_t x_max = _max(x1, x2) +wd;
	int32_t y_min = _min(y1, y2) -wd;
	int32_t y_max = _max(y1, y2) +wd;
	
    int32_t lb = _max(x_min,0);//l_border
    int32_t rb = _min(x_max,BMPWidth(image));//r_border
    int32_t ub = _max(y_min,0);//u_border
    int32_t db = _min(y_max,BMPHeight(image));//d_border

    for (int i = lb; i < rb; i++) {
        for (int j = ub; j < db; j++) {
			if (_inDist(x1, y1, x2, y2, i, j, wd)) {
				BMPSetPixel(image, i, j, color);
			}
		}
	}

}

static void BMPReflect(BMPImage* image, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint8_t vertical) {
	int32_t x_min = _min(x1, x2);
	int32_t x_max = _max(x1, x2);
	int32_t y_min = _min(y1, y2);
	int32_t y_max = _max(y1, y2);
	BMPPixel tpx;
	for (int i = x_min; i < x_max; i++) {
		for (int j = y_min; j < y_max; j++) {
			//if (_inBounds(i, x_min, x_min+(x_max-x_min)/2) && _inBounds(j, y_min, y_max)) {
				tpx = *PX(TAB(image), i, j);
				*PX(TAB(image), i, j) = *PX(TAB(image), x_max - 1 - (i - x_min), j);
				*PX(TAB(image), x_max - 1 - (i - x_min), j) = tpx;
			//}
		}
	}
}


static void plotLineWidth(BMPImage* image, int32_t x0, int32_t y0, int32_t x1, int32_t y1, double wd ,BMPPixel color)
{
	int32_t dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int32_t dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int32_t err = dx - dy, e2, x2, y2;                          /* error value e_xy */
	double ed = dx + dy == 0 ? 1 : sqrt((double)dx*dx + (double)dy*dy);
	double mul = 0;
	for (wd = (wd + 1) / 2; ; ) {                                   /* pixel loop */
		mul = (abs(err - dx + dy) / ed - wd + 1);
		BMPSetPixel(image, x0, y0, toPixel(color.r * mul, color.g * mul, color.b * mul) );
		//setPixelColor(x0, y0, _max(0, 255 * (abs(err - dx + dy) / ed - wd + 1)));
		e2 = err; x2 = x0;
		if (2 * e2 >= -dx) {                                           /* x step */
			for (e2 += dy, y2 = y0; e2 < ed*wd && (y1 != y2 || dx > dy); e2 += dx) {
				mul = _max(0, (abs(e2) / ed - wd + 1));
				BMPSetPixel(image, x0, y2 += sy, toPixel(color.r * mul, color.g * mul, color.b * mul));
				//setPixelColor(x0, y2 += sy, _max(0, 255 * (abs(e2) / ed - wd + 1)));
			}
				
			if (x0 == x1) break;
			e2 = err; err -= dy; x0 += sx;
		}
		if (2 * e2 <= dy) {                                            /* y step */
			for (e2 = dx - e2; e2 < ed*wd && (x1 != x2 || dx < dy); e2 += dy) {
				mul = _max(0, (abs(e2) / ed - wd + 1));
				BMPSetPixel(image, x2 += sx, y0, toPixel(color.r * mul, color.g * mul, color.b * mul));
				//setPixelColor(x2 += sx, y0, _max(0, 255 * (abs(e2) / ed - wd + 1)));
			}
				
			if (y0 == y1) break;
			err += dx; y0 += sy;
		}
	}
}
/*
#define C45 0.7071067811865475
#define S45 C45 
#define S0 0
#define C90 S0
#define C0 1
#define S90 C0

#define R3B2 0.86602540378
#define T60 0.32004038938
*/
/*
void BMPDrawHexagon(BMPImage* image, int32_t x, int32_t y, uint32_t r, uint32_t width, uint8_t filled, BMPPixel BorderC, BMPPixel InnerC) {
	int wid = BMPWidth(TAB(image)) ;
	uint32_t  hei = BMPHeight(TAB(image));

	int32_t x1 = x + r * .5,	 y1 = y + r * R3B2;	//tr
	int32_t x2 = x + r * 1,	 y2 = y + r * 0;	//r
	int32_t x3 = x + r * .5,	 y3 = y + r * -R3B2;//br
	int32_t x4 = x + r * -.5,   y4 = y + r * -R3B2;//bl
	int32_t x5 = x + r * -1,    y5 = y + r * 0;	//l
	int32_t x6 = x + r * -.5,   y6 = y + r * R3B2;	//tl

		


	for (uint32_t i = 0; i < wid; i++) {
		for (uint32_t j = 0; j < hei; j++) {
			if ((x - x1)*(-T60) > (y - y2) && (x - x2)*(T60) < (y - y3) && 0 < (y - y4) && (x - x4)*(-T60) < (y - y5) && (x - x5)*(T60) > (y - y6) && 0 > (y - y1)) {

			}



		}
	}
}*/

//void radmad(uint8_t* table) {
//	int wid = BMPWidth(table);
//	int  hei = BMPHeight(table);
//	for (int i = 0; i<wid; i++) {
//		for (int j = 0; j<hei; j++) {
//			/*
//			if(( sqrt_c(sqDist(i,j,500,450)) - sqrt_c(sqDist(i,j,500,550))) > sqrt_c(820)+50){
//			PX(table,i,j)->r = PX(table,i,j)->g = PX(table,i,j)->b = 0;
//			} else{
//			PX(table,i,j)->r = PX(table,i,j)->g = PX(table,i,j)->b = 255;
//			}
//			*/
//			/*
//			PX(table, i, j)->r = mannDist(i, j, 0, hei - 1) ? 255 * (wid + hei) / mannDist(i, j, 0, hei - 1) : 0;
//			PX(table, i, j)->g = mannDist(i, j, wid >> 1, hei - 1) ? 255 * ((wid + hei) / mannDist(i, j, wid >> 1, hei - 1)) : 0;
//			PX(table, i, j)->b = mannDist(i, j, wid - 1, hei - 1) ? 255 * (wid + hei) / mannDist(i, j, wid - 1, hei - 1) : 0;
//			*/
//
//			//PX(table,i,j)->r = PX(table,i,j)->g = PX(table,i,j)->b = ((i+j)>>3)&1?255:0;
//			//PX(table,i,j)->r = PX(table,i,j)->g = PX(table,i,j)->b = ((i>wid>>1)^(j>wid>>1))?255:0;
//			PX(table,i,j)->r = PX(table,i,j)->g = PX(table,i,j)->b = (i+j)%256*200;//VertGrad
//		}
//	}
//	return;
//}
//

#pragma pack(pop)

#endif// BMP_TOOLS
