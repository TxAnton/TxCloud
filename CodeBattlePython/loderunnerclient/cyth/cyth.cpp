//
// Created by anton on 11/29/19.
//

#include <string>
#include <cwchar>

#include <iostream>
#include "BMPTools.h"
using namespace std;


BMPImage* img = newBMPImage(0,58,58);;
int i=0;

extern "C" {
    int foo(wchar_t* a){
        //string s = new string(a);
        //wprintf(a);
        //cout<<endl;
        //return 1*(a[0]==L'a');

        for(int i=0;i<58;i++){
            for(int j=0;j<58;j++){
                BMPSetPixel(img,j,i,toPixel(a[i*58+j]*5%256,a[i*58+j]*5%256,a[i*58+j]*5%256));
            }

        }
        BMPWrite("img.bmp",img);
        //delete img;
        cout<<"Boo"<<endl;

        return 42;
	}		
}

/*
i+=100;
        img = newBMPImage(0,10,10);
        BMPFill(img,toPixel(255,i%256,0));
        BMPWrite("img.bmp",img);
        delete img;
		cout<<"Boo"<<endl;
		return 42;
    	//return "Hello, Cython!";
 */
