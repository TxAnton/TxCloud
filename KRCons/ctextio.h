#ifndef CTEXTIO_H
#define CTEXTIO_H
#include<wchar.h>
#include<wctype.h>
#include<stdlib.h>
#include<stdio.h>
#include"ctext.h"

void prints(struct Sentence* sentence);

void printt(struct Text* text);

void readText(struct Text* text);