#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<wchar.h>
#include<wctype.h>
#include<time.h>

#include"ctext.h"
#include"ctextio.h"
#include"ctextp.h"

int main()
{
	setlocale(LC_CTYPE, "");

	wchar_t t=L'0';
	struct Text text;
	int f = 1;
	wprintf(L"Enter text of cyrilic and latin symbols:\n");
	readText(&text);

	
	Tokenize(&text);
	
	RemTab(&text);
	
	remSim(&text);
	
	wprintf(L"\n");
	printt(&text);	
	
	
	if(f)wprintf(L"\n\nChoose one of the following:\n0:Exit\n1:Replace \"high noon\" -> \"полдень\"\n2:ParseDates\n3:Filter by first/last word equivaence\n4:Chronology\n");
	t = getwchar();
	switch(t){
		case L'0':{
			return 0;
			break;
		}
		case L'1':{
			Replace(&text,L"high noon", L"полдень");
			printt(&text);
			f=0;
			break;
		}	
		case L'2':{
			wprintf(L"Dates if text in DD/MM/YYYY  and YYYY-MM-DD format\n");
			ParseDates(&text);
			f=0;
			break;
		}	
		case L'3':{
			Filter(&text);
			printt(&text);
			f=0;
			break;
		}
		case L'4':{
			wprintf(L"Dates if text in <day> <month> <year> format\n");
			Chronology(&text);
			f=0;
			break;
		}
		case L'5':{
			putwchar(L'\n');
			printt(&text);
			f=0;
			break;
		}
		
		default:{
			f=1;
		}
	}
	return 0;
}



