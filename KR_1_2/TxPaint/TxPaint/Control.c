#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define true 1
#define false 0
#include"BMPTools.h"

int main() {
	//BMPImage* image = (BMPImage*)BMPRead("./SmallPic.bmp");
	BMPImage* image = (BMPImage*)newImage(NULL, 1000, 1000);
	uint8_t* table = (uint8_t*)image;
	uint32_t size = BMPSize(image);

	//printf("%u\n", size);	
	//printt(table,8,16);
	//printf("\n");
	BMPPrintInfo(image);
	//BMPPrintInfo(image);
	//printf("R:%x\nG:%x\nB:%x\n", PX(table,0,0)->r,PX(table,0,0)->g,PX(table,0,0)->b);
	//PX(table, 8, 7)->r = PX(table, 8, 7)->g = PX(table, 8, 7)->b = 1;
	//radmad(table);
	//BMPSetPixel();
		//BMPSetPixel(image, 5, 5, toPixel(0, 0, 0));
	BMPFill(image, toPixel(0, 255, 255));
	BMPDrawCircle(image, 500, 500, 250, 100, true, toPixel(0, 0, 255), toPixel(255, 0, 255));
	//BMPDrawCircle(image, 50, 50, 50, 20, 1, toPixel(0, 0, 255), toPixel(0, 255, 0));
	//BMPDrawCircle(image, image->header.width_px / 2 - 1, image->header.height_px / 2 - 1, image->header.height_px / 2 - 5, 5, 1, toPixel(255, 0, 0), toPixel(0, 0, 255));
	//image->header.height_px =(int32_t) 27;
	//image->header.width_px = (int32_t)(image->header.width_px);
	//b
	//BMPPrintBytes(image, 16, 16);
	//BMPPrintInfo(image);
	
	BMPInvertCircle(image, BMPWidth(image)/2, BMPHeight(image) / 2, 200);
	//	getchar();
	//BMPImage* Cut = BMPCut(image, 100, 100, 1000, 1000);
	BMPDrawTriangle(image, 0, 0,500, 500,50, 800, 50, true, toPixel(200, 200, 200), toPixel(0, 0, 0));
	//BMPWrite("./new.bmp", image);
	BMPWrite("./new.bmp", image);
	return 0;
}
	
