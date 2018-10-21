#include <stdio.h>
#include <stdlib.h>
//#include "fe_lo.h"
#include "index_first_even.h"

int f0(int *arr,int n){//index_first_even
	int i;
	for(i=1;i<n;i++){
		if(arr[i]%2==0){
			return i;
		}
	}
	return -1;
}
