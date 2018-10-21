#include <stdio.h>
#include <stdlib.h>
//#include "fe_lo.h"
#include "index_last_odd.h"
int f1(int *arr,int n){//index_last_odd
	int i;
	int x;
	for(i=1;i<n;i++){
		if(arr[i]%2!=0){
			x=i;
		}
	}
	return x;
}
