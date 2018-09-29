#pragma once
void Thomas_algorithm(int n, double *a, double *b, double *c, double *d, double *T) {
	for (int i = 1; i < n; i++) {
		b[i] -= a[i - 1] * c[i] / b[i - 1];
		d[i] -= c[i] * d[i - 1] / b[i - 1];
	}

	T[n - 1] = d[n - 1] / b[n - 1];

	for (int i = n - 2; i >= 0; i--)
		T[i] = (d[i] - a[i] * T[i + 1]) / b[i];
}