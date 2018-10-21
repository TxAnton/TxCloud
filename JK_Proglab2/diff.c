#include "max.h"
#include "min.h"
int differenceBetweenMaxAndMin(int *a, int n) {
	int diff;
	diff = maxElement(a,n) - minElement(a,n);
	return diff;
}

