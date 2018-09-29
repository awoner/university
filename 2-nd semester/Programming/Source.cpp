// ConsoleApplication51.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
 
using namespace std;

void zap(int **arr, int n, int m);
void funk(int **arr, int n, int m);
void funk4(int **arr1, int n, int m);
void rel(int **arr, int n);
void rel1(int **arr1, int n);
void funk2 (int n , int **arr, int **arr1, int m );
void funk3(int n , int **arr, int m);

void zap(int **arr, int n, int m)
{


for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl;
    }
}


void funk(int **arr, int n, int m)
{

arr = new int*[n];
for(int i=0; i<n; i++)
	 arr[i] = new int [m];

}

void funk4(int **arr1, int n, int m)
{

arr1 = new int*[n];
for(int i=0; i<n; i++)
	 arr1[i] = new int [m];

}

void rel(int **arr, int n)
{


for(int i=0; i<n; i++)
 delete [] arr[i]; 
delete [] arr;

}

void rel1(int **arr1, int n)
{


for(int i=0; i<n; i++)
 delete [] arr1[i]; 
delete [] arr1;

}

void funk2 (int n , int **arr, int **arr1, int m )
{
	
for (int i = 0; i < n; i++)

	for (int j=0; j<n; j++)

	if (arr[i] % 2 == 0 && arr[j] % 2 == 0)
    {
		while (i < n && j<m)
            {
                arr[i] = arr[i+1];
				arr[j] = arr[j+1];
               i++;
			   j++;
            }
    n -= 1;
	m -= 1;
	
    for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++ )
		{
			arr1[i] = arr[i];
	arr1[j] = arr[j];
		}
		}
		

   
	

}

void funk3(int n , int **arr, int m)
{
cout << "Array after: ";
    for (int i = 0; i < n; i++)
		for(int j=0; j<m; j++)
	cout << arr[i][j] << " ";
    cout << endl;
   
}

int main()
{
int **arr = NULL;
int **arr1 = NULL;
srand(time(0));
int n;
cout << "Enter size of array1: ";
cin >> n;

int m;
cout << "Enter size of array2: ";
cin >> m;

funk(arr, n, m);
funk4(arr, n, m);
 zap(arr, n, m);
funk3(n, arr, m);
funk2(n, arr, arr1, m);
rel(arr, n);
rel1(arr, n);
system("pause");
	return 0;
}
