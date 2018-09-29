

#include "stdafx.h"
#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

using namespace std;
#define N 9



void f(int a[N][N])
{
	srand(time(NULL));
for(int i=0; i<N ; i++)
	{
	    for(int j=0; j<N; j++)
	   {
	      a[i][j] = rand()%100;
	   cout << a[i][j] << " ";
		}
	cout << endl;
	}
}


void sum(int a[N][N])
{
	int sum=0, ser=0;
for (int i=0; i<N; i++)
    for (int j=0; j<=i; j++)
     {
		 sum+=a[i][j];
 ser++;
 
	}
 cout << "Summa: " << sum << endl;
 sum = sum/ser;
cout << "Ser: " << sum << endl;


}



int main()
{
int a[N][N];

 f(a);
 sum(a);
system("pause");
return 0;
}