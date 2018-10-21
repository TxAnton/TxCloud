#include<stdio.h>
#define LENGHT 100
#include<stdlib.h>
#include "min.h"
#include "max.h"
#include "sum.h"
#include "diff.h"
int main(){
	int k;
	int i=0;
	int a[LENGHT];
	int c;
	scanf("%d",&k);
	while(1){
		c=scanf("%d",a+i);
		if(c==-1){
			break;
		}
		i++;
}
	switch(k) {
		case 0:
			printf("%d", maxElement(a,i));
			break;
		case 1:
			printf("%d", minElement(a,i));
			break;
		case 2:
			printf("%d", differenceBetweenMaxAndMin(a,i));
			break;
		case 3:
			printf("%d", sumElementsBeforeFirstMin(a,i));
			break;
		}
	return 0;
}
