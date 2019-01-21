#include<stdio.h>
#include<stdlib.h>

#define BLOCK 20

int main(){
	
	char* str=NULL;

	char c=1;										
	int i=0;										
	while(c!='\n'){									
		if(i%BLOCK==0)str=realloc(str, i+BLOCK);	
		c=getchar();								
		str[i++]=c;									
	}												
	str[i]='\0';									

	for(int j = 0;j<i>>1;j++){
		//str[j]=str[j*2];
		str[j]=str[(j+1)*2-1];
	}
	str[i>>1]='\0';
	str = realloc(str, i<<1+1);
	printf(str);
}

