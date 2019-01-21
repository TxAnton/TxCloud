#ifndef CTEXTP_H
#define CTEXTP_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>
#include<wctype.h>
#include<time.h>

#include"ctext.h"
#include"ctextio.h"

int tmCmp(const void* a, const void* b);//Compares two (struct tm) values


void Tokenize(struct Text* text);


void RemTab(struct Text* text);


void remSim(struct Text* text);


void Replace(struct Text* text,const wchar_t* from,const wchar_t* with);


void* ParseDates(struct Text* text);


void* Chronology(struct Text* text);