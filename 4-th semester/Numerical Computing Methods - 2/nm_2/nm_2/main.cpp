#include <iostream>
#include <iomanip>

using namespace std;

double a = 0.0;
double b = 1.0;
double h = 0.2;
int n = static_cast<int>((b - a) / h);
int n1 = static_cast<int>((b - a) / (h / 5));
int n2 = static_cast<int>((b - a) / (h / 25));
double eps = 0.03;

double *x, *x1, *x2;
double *y, *yp;
double *e, *e1, *e2;

void init_arrays();
void delete_arrays();
double f(double);
double fp(double, double, double, double);
void method(double*, double*, double, int);

int main() {
	init_arrays();

	method(x, e, h, n);
	method(x1, e1, h / 5, n1);
	method(x2, e2, h / 25, n2);

	delete_arrays();
	system("pause");
	return 0;
}

void init_arrays() {
	x = new double[n + 1];
	x1 = new double[n1 + 1];
	x2 = new double[n2 + 1];

	y = new double[n2 + 1];
	yp = new double[n2 + 1];

	e = new double[n + 1];
	e1 = new double[n1 + 1];
	e2 = new double[n2 + 1];
}

void delete_arrays() {
	delete[] x;
	delete[] x1;
	delete[] x2;

	delete[] y;
	delete[] yp;

	delete[] e;
	delete[] e1;
	delete[] e2;
}

double f(double x) {
	return (2.5 - 3.5 * exp((-1.0 / 0.03) * ((x * x / 2.0) + x)));
}

double fp(double xk, double xk1, double y, double h) {
	return ((2.0 * eps * y) + h * ((5.0 / 2.0) * ((1.0 + xk1) + (1.0 + xk)) - y * (1 + xk))) / (2 * eps + h * (1 + xk1));
}

void method(double *x, double *e, double h, int n) {
	cout << setw(40) << "Table " << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << "|    xk    |     y(xk)     |       yk      |    y(xk)-yk    |       %      |" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	for (int i = 0; i <= n; i++){
		x[i] = a + h*i;
		y[i] = f(x[i]);
	}
	yp[0] = -1.0;

	for (int i = 0; i < n; i++) {
		yp[i + 1] = fp(x[i], x[i + 1], yp[i], h);
	}

	for (int i = 0; i <= n; i++){
		e[i] = y[i] - yp[i];
		cout << "|" << setw(10) << setprecision(3) << x[i]
			<< "|" << setw(15) << setprecision(6) << y[i]
			<< "|" << setw(15) << setprecision(6) << yp[i]
			<< "|" << fixed << setw(15) << setprecision(9) << abs(y[i] - yp[i])
			<< "|" << setw(15) << abs(((y[i] - yp[i]) / yp[i]) * 100.0) << "|" << endl;
	}
	cout << "----------------------------------------------------------------------------" << endl;
}