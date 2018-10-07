#include <stdio.h>
#include <stdlib.h>
int first_even(int *arr,int n){
	int i;
	for(i=1;i<n;i++){
		if(arr[i]%2==0){
			return i;
		}
	}
	return -1;
}

int last_odd(int *arr,int n){
	int i;
	int x;
	for(i=1;i<n;i++){
		if(arr[i]%2!=0){
			x=i;
		}
	}
	return x;
}
