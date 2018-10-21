int minElement(int *a, int n) {
	int j;
	int min;
	min=a[0];
	for (j=1; j<n; j++) {
		if (a[j]<min) {
			min=a[j];
		}
	}
	return min;
}

