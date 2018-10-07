
#include <stdio.h>
#include <stdlib.h>
#include "fe_lo.h"
void f3(int *arr,int n){//sum_before_even_and_after_odd
	int i;
	int sum=0;
	int fe=first_even(arr,n);
	int lo=last_odd(arr,n);
	for(i=1;i<fe;i++){
		sum+=abs(arr[i]);
	}
	for(i=lo;i<n;i++){
		sum+=abs(arr[i]);
	}
	printf("%d\n",sum);
	return;
}
