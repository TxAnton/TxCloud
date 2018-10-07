#include <stdio.h>
#include <stdlib.h>
#include "fe_lo.h"
void f2(int *arr,int n){//sum_between_even_odd
	int fe=first_even(arr,n);
	int lo=last_odd(arr,n);
	int i;
	int sum=0;
	for(i=fe;i<lo;i++){
		sum+=abs(arr[i]);
	}
	printf("%d\n",sum);
	return;
}
