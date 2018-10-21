int maxElement(int *a, int n) {
	int j;
	int max;
	max=a[0];
	for (j=1; j<n; j++) {
		if (a[j]>max) {
			max=a[j];
		}
	}
	return max;
}
