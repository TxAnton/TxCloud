#include <stdio.h>
#include <stdlib.h>
#include "fe_lo.h"
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after_odd.h"
//#include "fe_lo.h"
#define EL_COUNT 100

int main()
{
//input
	int index=-1;
	int arr[EL_COUNT];
	int i=0;//index in arr
	int k=0;//index in string
	char c;//input
	char str[5]="";//buffer
	while(1){
		c=getchar();//read from stdin
		if(c==' '){//space-end of int
			str[k]='\0';
			k=0;
			arr[i]=atoi(str);
			i++;
		}
		else if(c=='\n'){//enter- end of input
			str[k]='\0';
			k=0;
			arr[i]=atoi(str);
			i++;
			break;		
		}else{//wtv
			str[k]=c;
			k++;
		}
	}
	
	switch(arr[0]){
		case 0:
			f0(arr,i);
			break;
		case 1:
			f1(arr,i);
			break;
		case 2:
			f2(arr,i);
			break;
		case 3:
			f3(arr,i);
			break;
		default:{
			printf("Данные некорректны");			
			return 0;
		}
	}
	return 0;
}

