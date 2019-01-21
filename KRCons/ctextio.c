#include<wchar.h>
#include<wctype.h>
#include<stdlib.h>
#include<stdio.h>
#include"ctext.h"

#define BLOCK_LEN 500

void prints(struct Sentence* sentence){
	for(int i=0; i<sentence->len;i++){
		putwc((sentence->str)[i],stdout);
	}
}

void printt(struct Text* text){
	for(int i=0;i<(text->sentCnt);i++){
		if((text->sentences)[i].len)prints(&(text->sentences)[i]);
		putwc(L'\n',stdout);
	}
}

void readText(struct Text* text){
	
	size_t size=0;
	size_t i=0;
	wchar_t c=1;
	(text->sentCnt)=0;
	(text->rawStr)=NULL;
	//size+=BLOCK_LEN;
	
	//(text->rawStr)=(wchar_t*)malloc((size)*sizeof(wchar_t));
	wchar_t* sentEnd=SENT_DELIM;
	while(c!='\n' && c!=-1){
		if(i % BLOCK_LEN == 0){
			//size+=BLOCK_LEN;
			(text->rawStr)=(wchar_t*)realloc((text->rawStr), (i + BLOCK_LEN)*sizeof(wchar_t));
		}
		c=getwchar();
		if(wcschr(sentEnd,c)){
			(text->sentCnt)++;
		}
		(text->rawStr)[i++]=c;
	}
	(text->rawStr)[i]='\0';
	(text->textLen)=i;
}