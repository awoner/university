// ConsoleApplication58.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include "iostream" 
#include "stdio.h" 
#include <stdlib.h> 
#include <ctime> 
#include <cstdlib> 

using namespace std;
void bub(int B[], int n)
{
 int temp;
 for (int i = 0; i < n; i+=2)
	{

		
      for (int j = i+2; j < n; j+=2)
      {
        if (B[i] < B[j]) 
        {
                temp = B[j];
                B[j] = B[i];
                B[i] = temp;
            }
       }

    }
 cout << "Bubble: " << endl;
	for (int i = 0; i < n; i++)
	{
        cout << B[i] << " ";
    }
	   cout << endl;
}

void vibr(int B[], int n)
{

 for (int i = 1; i < n; i+=2)
    {
        int temp = B[0]; 
        for (int j = i+2; j < n; j+=2)
        {
            if (B[j] < B[i])
            {
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    } 
cout << "Vibor: " << endl; 
 for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}

void vst(int B[], int n)
{

    for (int i = 1; i < n; i+=2)
    {
      
        int tmp = B[i];
     
      
      for(int j = i-1;j >= 0 && B[j] < tmp; j++)
        {
            B[j + 1] = B[j]; 
            B[j + 1] = tmp;
          
        }
    }
	cout << "Vstavka: " << endl;
	 for (int i = 0; i < n; i++)
    {
        cout << B[i] << " "; 
    }
    cout << endl;
}

int main()
{
const int n = 20;
	int B[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	for(int i = 0; i < n; i++)
	{
	 cout << B[i] << " ";
	}
	cout << endl;
   bub(B, n);
   vibr(B, n);
   vst(B, n);
	system("pause");
	return 0;
}


