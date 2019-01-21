#include<stdio.h>
#include<time.h>

//#define PRINT

#define bmCtr 2000000

#define type unsigned long

#define sizeof(x) 4

int G;

void toBin(unsigned long x){
  if (x >= 2){
    toBin(x/2);
  }
#ifdef PRINT
  printf("%lu", x%2);
#endif
#ifndef PRINT
  G=x%2;
#endif
}

void toBin2(type x){
	int i = (sizeof(type) << 3) - 1;
	while((x&(1<<(i--)-1))==0);
	while(i+1){
#ifdef PRINT
		printf("%d",x&(1<<i--)?1:0);
#endif
#ifndef PRINT
		i--;
#endif
	}
}

void toBin1(type x){
	type m;
	size_t ul = sizeof(type);ul<<=3;
	m=(1<<(ul-1))-1 | (type)1<<((type)ul-(type)1);
	while(!(1&&x&((type)1<<((type)ul-(type)1)))){x<<=1;m<<=1;}
	while(x|m){
#ifdef PRINT
	printf("%d",(1&&x&((type)1<<((type)ul-(type)1))));
#endif
	x<<=1;m<<=1;}
}

int main(){
	type x;
	scanf("%lu",&x);
	//-----------------------------------------	
	clock_t c_clock1 = clock();
	for(int i = 0;i<bmCtr;i++){
	toBin1(x);
	}
	c_clock1 = clock() - c_clock1;
#ifdef PRINT
	printf("\n");
#endif
	//-----------------------------------------
	clock_t c_clock2 = clock();
	for(int i = 0;i<bmCtr;i++){
	toBin2(x);
	}
	c_clock2 = clock() - c_clock2;
#ifdef PRINT
	printf("\n");
#endif
	//-----------------------------------------
	clock_t c_clock3 = clock();
	for(int i = 0;i<bmCtr;i++){
	toBin(x);
	}
	c_clock3 = clock() - c_clock3;
#ifdef PRINT
	printf("\n");
#endif
	//-----------------------------------------
	printf("\nFirst: %d\n",c_clock1);
	printf("\nSecond: %d\n",c_clock2);
	printf("\nVitya: %d\n",c_clock3);
	//-----------------------------------------
	return 0;
}
