#include <iostream>
#include <iomanip>

using namespace std;

void init_arrays(int n, double k, double *a, double *b, double *c);
void Thomas_algorithm(int n, double *a, double *b, double *c, double *d, double *T);
void print_array(double *, int);

int main() {
	cout.precision(16);
	cout.setf(ios::fixed);
	
	int n = 10;

	double *a, *b, *c, *d, *T;
	a = new double[n];
	b = new double[n];
	c = new double[n];
	d = new double[n];
	T = new double[n];

	cout << "Task 1(c = 1.0):" << endl;
	double k = 1.0;
	init_arrays(n, k, a, b, c);
	d[0] = 2.60;
	d[1] = 3.33;
	d[2] = 4.14;
	d[3] = 5.03;
	d[4] = 6.00;
	d[5] = 7.05;
	d[6] = 8.18;
	d[7] = 9.39;
	d[8] = 10.68;
	d[9] = 9.20;
	Thomas_algorithm(n, a, b, c, d, T);

	cout << "Task 2(c = 0.1):" << endl;
	k = 0.1;
	init_arrays(n, k, a, b, c);
	d[0] = 0.800;
	d[1] = 1.116;
	d[2] = 1.494;
	d[3] = 1.934;
	d[4] = 2.436;
	d[5] = 3.000;
	d[6] = 3.626;
	d[7] = 4.314;
	d[8] = 5.064;
	d[9] = 3.026;
	Thomas_algorithm(n, a, b, c, d, T);

	cout << "Task 3(c = 0.001):" << endl;
	k = 0.001;
	init_arrays(n, k, a, b, c);
	d[0] = 0.60200;
	d[1] = 0.87246;
	d[2] = 1.20294;
	d[3] = 1.59344;
	d[4] = 2.04396;
	d[5] = 2.55450;
	d[6] = 3.12506;
	d[7] = 3.75564;
	d[8] = 4.44624;
	d[9] = 2.34686;
	Thomas_algorithm(n, a, b, c, d, T);

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	delete[] T;

	system("pause");
	return 0;
}

void print_array(double *arr, int size) {
	for (int i = 0; i < size; i++)
		cout << "X" << i + 1 << " = " << arr[i] << endl;
}

void init_arrays(int n, double k, double *a, double *b, double *c) {	
	for (int i = 0; i < n; i++) {
		if(i != n - 1)
			a[i + 1] = 0.2 + 0.2 * i;
		b[i] = 4.0 * k + (0.1 * k) * i;
	}
	a[0] = 0.0;

	for (int i = 0; i < n-1; i++)
		c[i] = 1.0 + 0.1 * i;
	c[n - 1] = 0;
}

void Thomas_algorithm(int n, double *a, double *b, double *c, double *d, double *T) {
	for (int i = 0; i < n; i++){
		b[i] -= (a[i] / b[i - 1]) * c[i - 1];
		d[i] -= (a[i] / b[i - 1]) * d[i - 1];
	}
	
	T[n - 1] = d[n - 1] / b[n - 1];
	for (int i = n - 2; i >= 0; i--)
		T[i] = (d[i] - c[i] * T[i + 1]) / b[i];

	print_array(T, n);
}