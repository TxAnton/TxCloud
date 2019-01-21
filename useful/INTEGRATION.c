#include <stdio.h>
#include <stdlib.h>

#define A 0.0
#define B 1.0
#define E 0.000001
//Nominal value	for A:0 B:2 is 2.(6)
//				for A:0 B:2 if 0.(3)
double square(double x){
	return x*x;
}

double integration(double a, double b, double e, double(*f)(double)){
	double s = 0.0;
	for(double x = a; x < b; x+=e){
		s+=f(x)*e;//Right-hand squares
	}
	return s;
}


int main(){
	printf("%lf",integration(A,B,E,square));
	return 0;
}
