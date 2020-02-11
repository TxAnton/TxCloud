#include<stdio.h>

#define N 20

void _print(char *string)
{
	__asm__ volatile ("mov   $0x09, %%ah\n"
                  "int   $0x21\n"
                  : /* no output */
                  : "d"(string)
                  : "ah");
}

int main(){
	char str[N];
	gets(str);
	_print(str);
	
	printf("%s",str);
	
}