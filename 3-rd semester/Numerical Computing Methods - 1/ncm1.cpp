// 4m.cpp: определяет точку входа для консольного приложения.
//Жордана с выбором главного элемента. Сравнить результаты с простым методом Жордана

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#define N 4

using namespace std;

void Print(double arr[][N], double vect[N]);
void Jordan(double arr[][N], double vect[N]);
void Nvect(double vect[N]);

int main()
{
	cout.precision(4);     
	cout.setf(ios::fixed);
	double arr[][N] = { {  4, 1000,  2,  3},
						{  3,   -1,  1, -3}, 
						{100,   -3, -2,  0},
						{  2,    2,  0, -1} };
	double vect[N] = {5, -1, -3, -1};
	cout << "Matrix:\n";
	Print(arr, vect);
	Jordan(arr, vect);
	_getch();
    return 0;
}

void Print(double arr[][N], double vect[N]) {
	for (int i = 0; i < N; i++) {
		cout << "|";
		for (int j = 0; j < N; j++) {
			cout << /*setprecision(5) <<*/setw(12) << arr[i][j] ;
		}
		cout << "| = |" << setw(10) << vect[i]<<"|\n";
	}
}

/*for k:=1 to N-1 do
begin
	Amax:=A[k, k]; H:=k;
	for i:=k+1 to N do
	if ABS(A[i,k])>AMAX then
	begin
		AMAX:=ABS(A[i,k]);
H:=i
	end;
	if H<>k then
	begin
		for j:=k to N do
		begin
			C:=A[k,j]; 
A[k,j]:=A[H,j];
A[H,j]:=C
end;
		C:=B[k]; B[k]:=B[H]; B[H]:=C
	end;
	for i:=k+1 to N do
	begin
		R:=A[i,k]/A[k,k];
		for j:=k to N do
		A[і,j]:=A[і,j] - A[k,j]*R;
		B[i]:=B[i] - B[k]*R;
	end;
end;
*/

void Jordan(double arr[][N], double vect[N]) {
	double r;
	for (int k = 0; k < N; k++)
		for (int i = 0 ; i < N; i++) {
			if (i == k)
				continue;
			r = arr[i][k] / arr[k][k];
			if (i != k)
				for (int j = k; j < N; j++)
				{
					arr[i][j] -= arr[k][j] * r;
					/*Print(arr, vect);
					cout << endl;*/
				}
				vect[i] -= vect[k] * r;
		}
	//int i, j, k;
	//for (k = 0; k<N; k++)
	//{
	//	for (i = 0; i<N; i++)
	//		for (j = 0; j<N ; j++)
	//			if ((i != k) && (j != k))
	//				arr[i][j] = arr[i][j] - arr[i][k] * arr[k][j] / arr[k][k];
	//	for (i = 0; i<N + 1; i++)
	//		if (i != k) arr[k][i] = arr[k][i] / arr[k][k];
	//	for (i = 0; i<N; i++)
	//		if (i == k) arr[i][k] = 1;
	//		else arr[i][k] = 0;
	//};
	cout << "\n";
	cout << "transformation matrix: \n";
	Print(arr, vect);
	cout << "\n";
	cout << "Vector of unknows: {";
	double x[N];
	for (int i = 0; i < N; i++) {
		x[i] = vect[i] / arr[i][i];
		cout << x[i] << ", ";
	}
	cout << "}\n";
	cout << "\n";
	Nvect(vect);
}

void Nvect(double x[N]) {
	double arr[][N] = { { 4, 1000, 2, 3 },{ 3, -1, 1, -3 },{ 100, -3, -2, 0 },{ 2, 2, 0, -1 } };
	double vect[N] = { 5, -1, -3, -1 };
	cout << "vector of discrepancies: {";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			arr[i][j] *= x[i];
			vect[i] -= arr[i][j];
		}
		cout << vect[i] << ", ";
	}
	cout << "}\n";
}