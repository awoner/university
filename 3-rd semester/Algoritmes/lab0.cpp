// Alg_laba_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"
#include "locale.h"
#include <iostream>
#include <ctime>

using namespace std;

int Factorial1(int n)
{
	int res;
	if (n == 1)
	{
		res = 1;
	}
	else
	{
		res = n*Factorial1(n - 1);
	}
	return res;
}
int Factorial2(int n)
{
	int fac = 1;
	for (int i = 1; i <= n; i++)
	{
		fac = fac*i;
	}
	return fac;
}
void Vvod(int N, int arr[])
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 41 - 20;
	}
	printf("array: \n");
	for (int i = 0; i < N; i++)
	{
		printf("%4d", arr[i]);
	}
	printf("\n");
}
void Vivod(int n, int arr[])
{
	if (n < 0 )
	{
		return;
	}
	if (arr[n] >= 0)
	{
		printf("%4d", arr[n]);
	}
	Vivod(n - 1, arr);
	if (arr[n] < 0)
	{
		printf("%4d", arr[n]);
	}
}
int Fibonachi(int n)
{
	int fib;
	if (n <= 2)
	{
		fib = 1;
	}
	else
	{
		fib = Fibonachi(n - 1) + Fibonachi(n - 2);
	}
	return fib;
}
int StepIn(int x, int s)
{
	int res;
	if (s == 1)
	{
		res = x;
	}
	else
	{
		res = StepIn(x, s - 1)*x;
	}
	return res;
}
void Towers(int num, int from, int to, int free)
{
	if (num != 0)
	{
		Towers(num - 1, from, free, to);
		cout << "\nRemove " << num << " disc from " << from << " rod and up it to " << to << " rod";
		Towers(num - 1, free, to, from);
	}
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	//---------------------------про факторіал
	int a;
	printf("Enter num for factorial:  ");
	scanf_s("%d", &a);
	printf("First - %d\n", Factorial1(a));
	printf("Second - %d\n", Factorial2(a));
	//-----------------------------про масив
	srand(time(NULL));
	int N;
	printf("Enter size of array: ");
	scanf_s("%d", &N);
	int *arr = new int[N];
	Vvod(N, arr);
	Vivod(N - 1, arr);
	delete[] arr;
	// 3 - ряд Фібоначчі
	int b;
	printf("\nEnter num of nums of Fibonachi: ");
	scanf_s("%d", &b);
	printf("El equal - %d\n", Fibonachi(b));
	// 4 - cтепінь числа
	int x, s;
	printf("What the num of enter under the degree&? ");
	scanf_s("%d", &x);
	printf("What degree&? ");
	scanf_s("%d", &s);
	printf("Your num on degree - %d\n", StepIn(x, s));
	// 5 - Ханойська вежа
	int c;
	printf("Enter num of rod: ");
	scanf_s("%d", &c);
	Towers(c, 1, 3, 2);
	cout << "\n  ";
	system("pause");
    return 0;
}

