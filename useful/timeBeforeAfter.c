#include<stdio.h>
#include<stdlib.h>

#define BLOCK 5

#define Square(n) (n*n)

#define DistSquared(pt) (Square(pt->x) + Square(pt->y))  

struct s_time{
	int h;
	int m;
};

int cmpTime	(struct s_time* a, int* b){
	if(a->h * 60 + a->m > *b)return 1;
	else if(a->h * 60 + a->m == *b) return 0;	
	else return -1;
}

int main(){
	struct s_time* times = NULL;
	char c;
	int len = 0;
	int a = 0;
	int b = 0;
	int ctrl;
	int c_after = 0;
	
	scanf("%d\n",&ctrl);
	while(1){
		getchar();
		c=scanf("%d",&a);
		getchar();
		if(c)scanf("%d",&b);
		else break;
		
		if(len%BLOCK==0) times = realloc(times, (len+BLOCK)*sizeof(struct s_time));
		
		times[len].h = a;
		times[len++].m = b;
		getchar();
	}
	
	for(int i = 0; i<len; i++){
		if(cmpTime(&times[i],&ctrl)==1)c_after++;
	}
	printf("%d",c_after);
	
}
