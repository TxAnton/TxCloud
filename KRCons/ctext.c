#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<wctype.h>
#include<wchar.h>
#include"ctext.h"

void freeSent(struct Sentence* sent){
	free(sent->str);
	sent->str=0;
	sent->len=0;
}


void freeText(struct Text* text){
	for(int i=0;i<text->sentCnt;i++){
		freeSent(&(text->sentences)[i]);
	}
	free(text->sentences);
	text->sentences=0;
	free(text->rawStr);
	text->rawStr=0;
	text->textLen=text->sentCnt=0;
}


void cpySent(struct Sentence* dest, struct Sentence* src){
	dest->len = src->len;
	dest->str = realloc(dest->str,(dest->len+2)*sizeof(wchar_t));
	//memcpy(dest->str,src->str,sizeof(struct Sentence)*dest->len);
	memmove(dest->str,src->str,sizeof(wchar_t)*(dest->len+2));
}


void SlideDeleted(struct Text* text){
	int i=0;
	int sl=0;
	while(i+sl<text->sentCnt){
		if((text->sentences)[i+sl].len){
			if(sl){
				cpySent(&((text->sentences)[i]),&((text->sentences)[i+sl]));
			}			
			i++;
		}
		else{
			sl++;
		}
	}
	struct Sentence* tmp = realloc((text->sentences),i*sizeof(struct Sentence));
	if(tmp){
		text->sentences=tmp;
	}
	text->sentCnt=i;
}
