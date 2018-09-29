// алгоритмы.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ctime"
#include "iostream"
#include "conio.h"

using namespace std;

class Complex {
private:
	int real;
	int imag;
public:
	Complex() {}
	Complex(int a, int b) {
		this->real = a;
		this->imag = b;
		cout << "(" << this->real << ", " << this->imag << ") ";
	}

	Complex(Complex **arr, int j) {
		cout << "(" << arr[j]->real << ", " << arr[j]->imag << ") ";
	}

	void Sqrt(double *arr1[], Complex **arr, int i) {
		*arr1[i] = sqrt(arr[i]->real * arr[i]->real + arr[i]->imag * arr[i]->imag);
	}
};

void Zap(Complex x, int n, Complex **arr, double **arr1) {
	int z, y;
	for (int i = 0; i < n; i++) {
		z = rand() % 10;
		y = rand() % 10;
		*arr[i] = Complex(z, y);
		x.Sqrt(arr1, arr, i);
	}
}

void Max(Complex x, Complex **arr, double **arr1, int n) {
	double *max = arr1[0];
	int j;
	for (int i = 1; i < n; i++) {
		if (arr1[i] > max) {
			max = arr1[i];
			j = i;
		}
	}
	cout << "\n\nMax = ";
	Complex(arr, j);
	cout << "\nMax(abs) = " << *max << endl;
}

void Delete(Complex **arr, double **arr1, int n) {
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
		delete arr1[i];
	}
}

int main()
{
	srand(time(NULL));
	Complex x;
	const int n = 10;
	int v = 0;
	do {
		printf("\n\n______________________%d_______________________\n\n", v);
		double **arr1 = new double*[n];
		for (int i = 0; i < n; i++) {
			arr1[i] = new double;
		}
		Complex **arr = new Complex*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Complex;
		}
		cout << "Array: ";
		Zap(x, n, arr, arr1);
		Max(x, arr, arr1, n);
		Delete(arr, arr1, n);
		printf("\n\n_____________________________________________\n\n");
		printf("\n\nPress \"Enter\"\n");
		v++;
		//_getch();
	} while (getchar() == '\n');
	return 0;
}