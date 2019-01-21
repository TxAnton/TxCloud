#include<stdio.h>
#include<stdlib.h>

#define BLOCK 5

#define Square(n) (n*n)

#define DistSquared(pt) (Square(pt->x) + Square(pt->y))  

struct point{
	float x,y;
};

int cmpDist(struct point* a, struct point* b){
	double da = DistSquared(a);
	double db = DistSquared(b);
	if(da>db)return 1;
	else if(da == db){if(a->x > b->x)return 1; else return -1;}
	else return -1;
}

int main(){
	struct point* pts = NULL;
	char c;
	int len = 0;
	float a = 0;
	float b = 0;
	int min = 0;
	while(1){
		getchar();
		c=scanf("%f",&a);
		getchar();
		if(c)scanf("%f",&b);
		else break;
		
		if(len%BLOCK==0) pts = realloc(pts, (len+BLOCK)*sizeof(struct point));
		
		pts[len].x = a;
		pts[len++].y = b;
		getchar();
	}
	
	for(int i = 1; i<len; i++){
		if(cmpDist(&pts[i],&pts[min])==-1)min = i;
	}
	printf("%d",min);
	
}
