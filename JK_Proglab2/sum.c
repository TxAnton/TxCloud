#include "min.h"
int sumElementsBeforeFirstMin(int *a, int n) {
	int s;
	int j;
	j=0;
	s=0;
	while (a[j]> minElement(a,n)) {
		s=s+a[j];
		j=j+1;
	}
	return s;
}

