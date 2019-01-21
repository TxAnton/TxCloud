#ifndef CTEXT_H
#define CTEXT_H

#include<wchar.h>

struct Text{
	struct Sentence* sentences;
	wchar_t* rawStr;
	size_t textLen;
	size_t sentCnt;
};

struct Sentence{
	//char* strptr;
	wchar_t* str;
	size_t len;
};


void freeSent(struct Sentence* sent);


void freeText(struct Text* text);


void cpySent(struct Sentence* dest, struct Sentence* src);


void SlideDeleted(struct Text* text);