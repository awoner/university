#include "iostream"
#include "stdio.h"
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

using namespace std;
const int N 4
const int M 10


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


void sum(int a[N][M], int k, int mul)
{
	cout << "¬ведите k: " << endl;
    cin >> k;
	if (0<k && k<11)
    k--;
    sum = 0;
    mul = 1;
    for(int i=0,i!=N,i++)
    {
        sum += a[i][k];
        mul *= a[i][k];
	}
	cout << "Proizvidenie: " << mul << endl;
cout << "Summa: " << sum << endl;
	else cout << "ERROR"; 

}



int main()
{
int a[N][M];

 f(a);
 sum(a, k, mul);
system("pause");
return 0;
}