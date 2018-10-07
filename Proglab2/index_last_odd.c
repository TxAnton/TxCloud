#include <stdio.h>
#include <stdlib.h>
#include "fe_lo.h"

void f1(int *arr,int n){//index_last_odd
	printf("%d",last_odd(arr,n)-1);
	return;
}
