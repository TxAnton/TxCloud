#include<stdlib.h>
#include<stdio.h>

#define X 0.5
#define DEGREE 100

double* U(double x, int deg){//Returns array of length deg+1 with counted values
	static double* vals = NULL;//Array of counted values for sake of optimisation
	static int _cnt = -1;//Last counted degree	
	static int _size = 0;//Size of vals array
	if(deg - _cnt != 1){//All values till this degree should be counted before we can count current one
		if(_size < deg+1){
			vals = realloc(vals, (deg+1) * sizeof(double));
			_size = deg+1;
		}
		U(x,deg-1);//Count all previous values
	}
	//fprintf(stderr,"%d\n",(deg - _cnt)==1?1:0);//Debug: Must be 1 only!
	switch (deg){//Count current value
	case 2:{
		vals[deg]=(-1) * x;
		break;
	}
	case 1:{
		vals[deg]= 2 * x;
		break;
	}
	case 0:{
		vals[deg] = 1;
		break;
	}
	default:{
		vals[deg] = x * vals[deg-1] - vals[deg-2] + vals[deg-3];
	}
	}
	_cnt++;
	return vals;
}

int main(){
	double* vals = U(X, DEGREE);
	for( int i = 0; i <= DEGREE; i++){
		printf("U%d(%lf) = %lf\n", i, X, vals[i]);
	}
}
