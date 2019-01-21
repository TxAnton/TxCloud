#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>
#include<wctype.h>
#include<time.h>

#define SENT_DELIM L".?;!"
#define WORD_DELIM L" ,"
#define DIGITS L"0"L"1"L"2"L"3"L"4"L"5"L"6"L"7"L"8"L"9" 

int tmCmp(const void* a, const void* b){//Compares two (struct tm) values
	time_t x = mktime((struct tm*)a);
	time_t y = mktime((struct tm*)b);
	if(x>y)return 1;
	else if(x==y) return 0;
	else return -1;
}

void Tokenize(struct Text* text){
	wchar_t* delim=SENT_DELIM;//delimers	
	wchar_t* t=(text->rawStr);//begin of untokinized text
	wchar_t* end=(text->rawStr) + (text->textLen);//Very end of the text(\0)
	(text->sentences)=malloc(sizeof(struct Sentence) * (text->sentCnt));//malloc for arr of sentences
	int i = 0;//sentence conter
	wchar_t* pt=wcspbrk(t, delim);//end of current sentence(token)
	while(pt && pt<end){
		(text->sentences)[i].len=(int)(pt-t)+1;//setting text len
		(text->sentences)[i].str=malloc(sizeof(wchar_t) * (text->sentences)[i].len+1);//malloc for individual sentence
		wcsncpy((text->sentences)[i].str,t,(text->sentences)[i].len);//copying sentence from text to it's place in array
		t=pt+1;//setting new begin of untokenized text
		pt=wcspbrk(t, delim);//new end of next token
		i++;
	
	}
}

void RemTab(struct Text* text){//(struct Sentence* sentences, int cnt){
	for(int i=0;i<text->sentCnt;i++){
		int slide=0;
		int j=0;
		wchar_t b=0;
		while(j+slide<(text->sentences)[i].len){
			if(iswspace((text->sentences)[i].str[j+slide])  && !b){
				slide++;
			} else {
				b=1;
				(text->sentences)[i].str[j]=(text->sentences)[i].str[j+slide];
				j++;
			}
		}
		(text->sentences)[i].len-=slide;
		(text->sentences)[i].str =(wchar_t*) realloc((wchar_t*)((text->sentences)[i].str), (size_t)(((text->sentences)[i].len+2) * sizeof(wchar_t)));
		(text->sentences)[i].str[(text->sentences)[i].len]=L'\0';
	}
}

void remSim(struct Text* text){//CASE-SENSIBLE!!!
	for(int i=0; i<text->sentCnt; i++){
		for(int j=i+1; j<text->sentCnt; j++){
			if(	(((text->sentences)[i]).len) && ( (((text->sentences)[i]).len) == (((text->sentences)[j]).len)  )	){
				char flag=1;
				for(int k = 0; k<(((text->sentences)[i]).len); k++){
					if( towlower( ((text->sentences)[i]).str[k] ) != towlower( ((text->sentences)[j]).str[k] ) ){
						flag=0;
						break;
					}
				}
				if(flag){
					freeSent(&(text->sentences)[j]);
				}
			}
		}
	}
	//SLIDE
	SlideDeleted(text);
	return;
}


void Replace(struct Text* text,const wchar_t* from,const wchar_t* with){
	int p_len=wcslen(from);//Prev len
	int n_len=wcslen(with);//New len
	int d_sl=n_len-p_len;//Delta len
	int i=0;//Prev str iterator
	int j=0;//New str iterator
	//free((text->sentences)[0].str);
	for(int l=0; l< (text->sentCnt); l++){
		wchar_t* str = (text->sentences)[l].str;//string to work with;
		size_t d_size = d_sl>0?((((text->sentences)[l].len)*sizeof(wchar_t)/p_len)+2)*d_sl:0;
		//d_size = d_size>0?d_size:0;
		wchar_t* n_str= malloc(((text->sentences)[l].len+2)*sizeof(wchar_t) + d_size);//New string
		wchar_t* repPtr=0;//Substring to be replaced
		repPtr = wcsstr((text->sentences)[l].str,from);
		
		while(i<(text->sentences)[l].len){
			if(repPtr && (str+i)==repPtr){//replacing substr
				for(int k=0;k<n_len; k++){
					n_str[k+j]=with[k];			
				}
				j+=n_len;
				i+=p_len;
				repPtr = wcsstr((text->sentences)[l].str+i,from);
			}
			else{//simply pasting another symbol
				n_str[j]=str[i];
				j+=1;
				i+=1;
			}
		}
		n_str[j]=(L'\0');
		(text->sentences)[l].len=j;
		free((text->sentences)[l].str);
		(text->sentences)[l].str=n_str;
		(text->sentences)[l].str=(wchar_t*)realloc((text->sentences)[l].str,(j+1)*sizeof(wchar_t));
		i=0;
		j=0;
	}
}

void Filter(struct Text* text){
	wchar_t* first = NULL;
	wchar_t* last = NULL;
	wchar_t* tmp = NULL;
	
	wchar_t* w_delim=WORD_DELIM;//L".?;!";
	wchar_t* s_delim=SENT_DELIM;
	//DELETE
	for(int i = 0; i < text->sentCnt; i++){
		first = (text->sentences[i].str);
		last = first;
		tmp = wcspbrk(last+1,w_delim);//last always follows tmp, thus (tmp - last) is last word len 
		while(tmp){
			last = tmp+1;
			tmp = wcspbrk(last,w_delim);
		}
		tmp = wcspbrk(last,s_delim);//end of the last word - end of the sentence
		if(!tmp)tmp = first + text->sentences[i].len;//If no punct at the end(?), set end to (start + len)
		if(wcsncmp(first,last,tmp - last-1) == 0){
			freeSent(&text->sentences[i]);
		}
	}
	//SLIDE
	SlideDeleted(text);
}



void* ParseDates(struct Text* text){//Returns struct tm*
	struct tm* dates = NULL;
	int j = 0;
	wchar_t  outBuf[15];
	outBuf[15] = L'\0';
	for(int i = 0; i < text->sentCnt; i++){
		wchar_t dateDelim[] = L"/-";
		wchar_t* p_date = wcspbrk(text->sentences[i].str,dateDelim);
		while(p_date){
			struct tm _time;
			wchar_t buf[5];
			switch (*p_date){
				case '-':{
					if(p_date - text->sentences[i].str >= 4/*YYYY before q't '-'*/ && *p_date == *(p_date+3)/* -mm- */ && wcsspn(p_date-4,DIGITS) == 4  && wcsspn(p_date+1,DIGITS) == 2 && wcsspn(p_date+4,DIGITS) == 2){
						
						//_wtoi
						time_t t = 0;
						struct tm* t_time = localtime(&t);
						_time = *t_time;
						
						wcsncpy(buf, p_date-4, 4);
						buf[4]='\0';
						_time.tm_year = _wtoi(buf) - 1900;//???
						
						wcsncpy(buf, p_date+1, 2);
						buf[2]='\0';
						_time.tm_mon = _wtoi(buf) - 1;
						
						wcsncpy(buf, p_date+4, 2);
						//buf[2]='\0';
						_time.tm_mday = _wtoi(buf);
						
						dates = realloc(dates, (j+1)*sizeof(struct tm));
						dates[j] = _time;
						j += 1;
						
					}
					break;
				}
				case '/':{
					if(p_date - text->sentences[i].str >= 2/*DD before q't '-'*/ && *p_date == *(p_date+3)/* /mm/ */ && wcsspn(p_date-2,DIGITS) == 2  && wcsspn(p_date+1,DIGITS) == 2 && wcsspn(p_date+4,DIGITS) == 4){
						//_wtoi
						time_t t = 0;
						struct tm* t_time = localtime(&t);
						_time = *t_time;						
						
						wcsncpy(buf, p_date-2, 2);
						buf[2]='\0';
						_time.tm_mday = _wtoi(buf);//???
						
						wcsncpy(buf, p_date+1, 2);
						buf[2]='\0';
						_time.tm_mon = _wtoi(buf) - 1;
						
						wcsncpy(buf, p_date+4, 4);
						buf[4]='\0';
						_time.tm_year = _wtoi(buf) - 1900;
						
						dates = realloc(dates, (j+1)*sizeof(struct tm));
						dates[j] = _time;
						j += 1;
						
					}
					break;
				}			
			}
			p_date = wcspbrk(p_date+4,dateDelim);
		}	
	}
	qsort(dates, j, sizeof(struct tm), tmCmp);
	for(int k = 0; k < j; k++){
		wcsftime(outBuf, 15, L" %d/%m/%Y ", &dates[k]);
		wprintf(L"%s\n", outBuf);
	}
	return dates;
}

void* Chronology(struct Text* text){
	int yet = 1;//is there any more dates
	int m_num = -1;
	int j = 0;//dates iterator
	struct tm rep;// 4 month text representation
	struct tm* dates = NULL;
	wchar_t m_name[4];//Month name
	wchar_t* p_date = NULL;//Temp. found date
	wchar_t* p_cdate = NULL;//Closest date(by position in sentence)
	wchar_t buf[5];
	wchar_t  outBuf[15];
	outBuf[15] = L'\0';
	
	for(int i = 0; i < text->sentCnt; i++){
		p_cdate = text->sentences[i].str;
		m_num = -1;
		yet = 1;
		while(yet){
			yet = 0;
			for(int month = 0; month < 12; month++){// Looking 4 a date by month
				rep.tm_mon = month;
				wcsftime(m_name, 4, L"%b", &rep);
				p_date = wcsstr(p_cdate+1, m_name);
				if(p_date){
					if(!(p_cdate - text->sentences[i].str) || p_date < p_cdate){
						p_cdate = p_date;
						m_num = month;
					}
					yet = 1;
				}
			}
			if(yet){//Found yet another date(probably)
				if( p_cdate - text->sentences[i].str >= 3 && wcsspn(p_cdate-3, DIGITS) == 2 && wcsspn(p_cdate+4, DIGITS) == 4 ){
					struct tm _time;
					
					_time.tm_hour = 0; _time.tm_min = 0; _time.tm_sec = 0;
  					_time.tm_mon = 0;  _time.tm_mday = 0; _time.tm_yday = 0; _time.tm_year = 0;
					
					wcsncpy(buf, p_cdate-3, 2);
					buf[2] = L'\0';
					_time.tm_mday = _wtoi(buf);
					
					_time.tm_mon=m_num;
					
					wcsncpy(buf, p_cdate+4, 4);
					buf[4] = L'\0';
					_time.tm_year = _wtoi(buf) - 1900;
					
					dates = realloc(dates, j+1);
					dates[j] = _time;
					j += 1;
				} 
			}
		}
	}
	qsort(dates, j, sizeof(struct tm), tmCmp);
	for(int k = 0; k < j; k++){
		wcsftime(outBuf, 15, L" %d.%m.%Y ", &dates[k]);
		time_t now;
		time(&now);
		struct tm _time;
		_time = *localtime(&now);
		if(tmCmp( &dates[k], &_time ) != 1){
			wprintf(L"%s %s\n", outBuf, L"Happened ");	
		}
		else{
			wprintf(L"%s %s\n", outBuf, L"Not Happened ");	
		}
		
	}
	return dates;
}
