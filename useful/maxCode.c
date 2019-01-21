#include<stdio.h>
#include<stdlib.h>

#define BLOCK 5

struct symbol{
	char ch;
	int id;
};

int cmpCode(struct symbol* a, struct symbol* b){
	if(a->id > b->id)return 1;
	else if(a->id == b->id) return 0;	
	else return -1;
}

int main(){
	struct symbol* symbols = NULL;
	char c;
	int len = 0;
	char a = 0;
	int b = 0;
	int max = 0;
	while(1){
		getchar();
		c=getchar();
		if(c=='\''){
			scanf("%c",&a);
			getchar();getchar();
			scanf("%d",&b);
			getchar();
		}else break;
		
		if(len%BLOCK==0)symbols = realloc(symbols, (len+BLOCK)*sizeof(struct symbol));
		symbols[len].ch = a;
		symbols[len++].id = b;
	}
	
	for(int i = 1; i<len; i++){
		if(cmpCode(&symbols[i],&symbols[max])==1)max = i;
	}
	printf("%c",symbols[max].ch);
	
}
