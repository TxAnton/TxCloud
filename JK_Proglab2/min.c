int minElement(int *a, int n) {
	int j;
	int s;
	s=a[1];
	for (j=0; j<n; j=j+1) {
		if (a[j]<s) {
			s=a[j];
		}
	}
	return s;
}

