#include <iostream>
#include "METHODS.H"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

#define FF(x) ( (M_PI * pow(x, M_PI + 7) + 2 * M_PI*pow(x, M_PI + 3) + M_PI * pow(x, M_PI - 1) + 4 * pow(x, 3)) / (pow(x, 8) + 2 * pow(x, 4) + 1) )

double delta;
//#define DERIV
int main()
{

	int k_B,k_H;
	long int s;
	float a1, b1, eps1, delta1;
	double a, b, eps, x_B,x_H;

	a = 0.5;
	b = 1;
	printf("eps\t\tdelta\t\ta\t\tb\t\tx_B\t\tx_H\t\tn_m\t\tn\t\t\tk_B\tk_H\tk_t\tC\n");
	for (delta = 0.1; delta >= 0.000001; delta /= 10) 
	{
		for (eps = 0.1; eps >= 0.000001; eps /= 10) 
		{
			x_B = BISECT(a, b, eps, k_B);
			x_H = HORDA(a, b, eps, k_H);
			printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%d\t%d\t%d\t%d\n", eps, delta, a, b, x_B, x_H, eps / delta, 1 / (double)FF(x_H), k_B, k_H, (int)round(log2((b - a) / eps)), eps / delta> 1 / FF(x_H));
		}
	}
	return 0;
}