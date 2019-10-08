#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

double delta, c, d;
double BISECT(double, double, double, int&);
double F(double);
double Round(double, double);

int main() {
	int k;
	long int s;
	float a1, b1, c1, d1, eps1, delta1;
	double a, b, eps, x;
	printf("Введите eps: ");
	scanf_s("%f", &eps1);
	eps = eps1;
	printf("Введите c: ");
	scanf_s("%f", &c1);
	c = c1;
	printf("Введите d: ");
	scanf_s("%f", &d1);
	d = d1;
	printf("Введите a: ");
	scanf_s("%f", &a1);
	a = a1;
	printf("Введите b: ");
	scanf_s("%f", &b1);
	b = b1;
	printf("Введите delta: ");
	scanf_s("%f", &delta1);
	delta = delta1;
	x = BISECT(a, b, eps, k);
	printf("x = %lf  k = %d\n", x, k);
	printf("eps=%lf c=%lf d=%lf a=%lf b=%lf delta=%lf\n", eps, c, d, a, b, delta);
	return 0;
}

double BISECT(double Left, double Right, double Eps, int &N) {
	double E = fabs(Eps) * 2.0;
	double FLeft = F(Left);
	double FRight = F(Right);
	double X = 0.5 * (Left + Right);
	double Y;

	if (FLeft * FRight > 0.0) {
		puts("Неверное задание интервала\n");
		exit(1);
	}

	if (Eps <= 0.0) {
		puts("Неверное задание точности\n");
		exit(1);
	}

	if (FLeft == 0.0) {
		return Left;
	}

	if (FRight == 0.0) {
		return Right;
	}

	for (N = 0; Right - Left >= E; N++) {
		X = 0.5 * (Right + Left);	// вычисление середины отрезка
		Y = F(X);

		if (Y == 0.0) {
			return (X);
		}

		if (Y * FLeft < 0.0) {
			Right = X;
		}
		else {
			Left = X;
			FLeft = Y;
		}
	}
	return X;
}

double F(double x) {
	extern double c, d, delta;
	double s;
	long S;
	s = c * (x - d);

	if (s / delta < 0) {
		S = s / delta - 0.5;
	}
	else {
		S = s / delta + 0.5;
	}

	s = S * delta;
	s = Round(s, delta);
	return s;
}

double Round(double X, double Delta) {
	if (Delta <= 1E-9) {
		puts("Неверное задание точности округления\n");
		exit(1);
	}

	if (X > 0.0) {
		return Delta * long(X / Delta + 0.5);
	}
	else {
		return Delta * long(X / Delta - 0.5);
	}
}

