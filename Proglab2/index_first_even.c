#include <stdio.h>
#include <stdlib.h>
#include "fe_lo.h"
#include "index_first_even.h"

void f0(int *arr,int n){//index_first_even
	printf("%d",first_even(arr,n)-1);
	return;
}
