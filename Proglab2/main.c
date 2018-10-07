#include <stdio.h>
#include <stdlib.h>

#define EL_COUNT 100

int first_even(int *arr,int n);
int last_odd(int *arr,int n);
void f0(int *arr,int n);
void f1(int *arr,int n);
void f2(int *arr,int n);
void f3(int *arr,int n);

int main()
{
//input
	int index=-1;
	int arr[EL_COUNT];
	int i=0;//index in arr
	int k=0;//index in string
	char c;//input
	char str[5]="";//buffer
	while(1){
		c=getchar();//read from stdin
		if(c==' '){//space-end of int
			str[k]='\0';
			k=0;
			arr[i]=atoi(str);
			i++;
		}
		else if(c=='\n'){//enter- end of input
			str[k]='\0';
			k=0;
			arr[i]=atoi(str);
			i++;
			break;		
		}else{//wtv
			str[k]=c;
			k++;
		}
	}
	
	switch(arr[0]){
		case 0:
			f0(arr,i);
			break;
		case 1:
			f1(arr,i);
			break;
		case 2:
			f2(arr,i);
			break;
		case 3:
			f3(arr,i);
			break;
		default:{
			printf("Данные некорректны");			
			return 0;
		}
	}
	return 0;
}


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


void f0(int *arr,int n){//index_first_even
	printf("%d",first_even(arr,n)-1);
	return;
}
void f1(int *arr,int n){//index_last_odd
	printf("%d",last_odd(arr,n)-1);
	return;
}
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
 
