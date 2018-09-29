#include "stdafx.h"
#include "math.h"
#include <iostream>


using namespace std;

void input(double &a, double &b, double &xn, double &xk, double &sh)
{
	cout << "enter a		";
	cin >> a;
	cout << "enter b		";
	cin >> b;
	cout << "enter xn		";
	cin >> x1;
	cout << "enter xk		";
	cin >> x2;
	cout << "enter sh		";
	cin >> sh;
	cout << endl;
}

double summa(double x)
{
	double y = 0;
	for (int k = 0; k <= 6; k++)
	{
		if (pow(x, 2)!=0)
			y += sin(k*x)/pow(x, 2);
	}
	return y;
}

void output(double a, double b, double xn, double xk, double sh)
{
	double rez, x = 0;
	if ((a+x)!=0 && xk > xn && sh > 0)
	{
	for (x = 0; x <= xk; x+=sh)
	{
		rez = (b*x/(a+x))+summe(x);
		cout << "a = " << a << " | b = " << b << " | x = " << x << " | y = " << rez << endl;
	}
	}
	else
	{
		cout << "a = " << a << " | b = " << b << " | y indefenite " << endl;
	}
}



int main()
{
	double xn, xk, a, b, sh;
	input(a, b, xn, xk, sh);
	output(a, b, xn, xk, sh);
	system("pause");
	return 0;
}