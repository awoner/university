
#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

using namespace std;
const int N = 4;
const int M = 10;


void f(int a[N][M])
{
	srand(time(0));
for(int i=0; i<N ; i++)
	{
	    for(int j=0; j<M; j++)
	   {
	      a[i][j] = rand()%10;
	   cout << a[i][j] << " ";
		}
	cout << endl;
	}
}


void summa(int a[N][M], int mul, int sum)
{
	int k;
	cout << "Enter k: " << endl;
    cin >> k;
	if (0<k && k<11)
	{
		k--;
    sum = 0;
    mul = 1;
    for(int i=0;i!=N;i++)
    {
        sum += a[i][k];
        mul *= a[i][k];
	}
	cout << "Proizvidenie: " << mul << endl;
cout << "Summa: " << sum << endl;
   }else cout << "ERROR" << endl; 

}



int main()
{
int a[N][M];
int mul = 1, sum = 0;
f(a);
summa(a, mul, sum);
system("pause");
return 0;
}