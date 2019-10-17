#include <iostream>

#ifndef __NEWTON
#define __NEWTON
#endif 

#include "METHODS.H"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

#define PI2 (M_PI*M_PI)

#ifndef FF(x)
#define FF(x) ( (M_PI * pow(x, M_PI + 7) + 2 * M_PI*pow(x, M_PI + 3) + M_PI * pow(x, M_PI - 1) + 4 * pow(x, 3)) / (pow(x, 8) + 2 * pow(x, 4) + 1) )
#define FFF(x) ( (PI2*pow(x, M_PI + 10) - M_PI * pow(x, M_PI + 10) + 3 * PI2*pow(x, M_PI + 6) - 3 * M_PI*pow(x, M_PI + 6) + 3 * PI2*pow(x, M_PI + 2) - 3 * M_PI*pow(x, M_PI + 2) - 20 * pow(x, 6) + PI2 * pow(x, M_PI - 2) - M_PI*pow(x,M_PI-2) + 12 * pow(x, 2)) / (pow(x, 12) + 3 * pow(x, 8) + 3 * pow(x, 4) + 1) )
#endif
double delta;
//#define DERIV
int main()
{
	
	int k_B,k_H,k_N;
	long int s;
	float a1, b1, eps1, delta1;
	double a, b, eps, x_B, x_H, x_N;

	a = 0.5;
	b = 1.25;

	double x = 0.867086;
	printf("eps\t\tdelta\t\ta\t\tb\t\tx_B\t\tx_H\t\tx_N\t\t\tk_B\tk_H\tk_N\tDx\t\tc\n");
	for (delta = 0.1; delta >= 0.000001; delta /= 10) 
	{
		for (eps = 0.1; eps >= 0.000001; eps /= 10) 
		{
			x_B = BISECT(a, b, eps, k_B);
			x_H = HORDA(a, b, eps, k_H);
			x_N = NEWTON(b, eps, k_N);
			printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%d\t%d\t%d\t%lf\t%d\n", eps, delta, a, b, x_B, x_H, x_N, k_B, k_H, k_N, abs(x-x_N), eps>=abs(x - x_N));
		}
	}
	
	return 0;
}