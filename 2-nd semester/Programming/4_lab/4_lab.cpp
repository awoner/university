// ConsoleApplication58.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include "iostream" 
#include "stdio.h" 
#include <stdlib.h> 
#include <ctime> 
#include <cstdlib> 
#include <memory> 




using namespace std;


void shell(int B[], int n)
{
int step = n / 2;
    while (step > 0)
    {
      for (int i = 0; i < (n - step); i+=2)
                {
                    int j = i;

					
					while (j >= 0 && B[j] < B[j + step])
            
                    {
                     
                        int tmp = B[j];
                        B[j] = B[j + step];
                        B[j + step] = tmp;
                        j-=step; 
                    }
                }
                step -= 2;
            }    

	cout << "Shell Sort: " << endl;	
     for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
	cout << endl;

}



void hoor(int first, int last, int B[], int n)
{

int i = first, j = last;
int step = -1;
int condition = 1;
if(first >= last)
	return;
do
{
	if(condition==(B[j] > B[i]) && B[j] % 2 != 0 && B[i] % 2 != 0 )
	{
	swap(B[i],B[j]);
	swap(i,j);
	step = -step;
	condition = !condition;
	}
	j += step;
}
while(j != i);
hoor(first , i - 1, B, n);
hoor(i + 1, last, B, n);
}


void quickSort(int l, int r, int B[], int n)
{
    int x = B[l + (r - l) / 2];

    int i = l;
    int j = r;
 

    while(i <= j)
    {
		
        while(B[i] > x) i++;
		  if ((i)%2!=0)
			   i++;
        while(B[j] < x) j--;
          if ((j)%2!=0)
	           j--;
		   if(i <= j)
		   {       if (B[i] < B[j])
			            swap(B[i], B[j]);
            i++;
            j--;
        }
    }
    if (i<r){
                quickSort(i, r, B, n);
	}
    if (l<j)  {  
        quickSort(l, j, B, n);
	}
	 
}

void hoar(int B[], int n)
{

hoor(0, n-1, B, n);
cout << "Haor Sort: " << endl;	 
for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
	cout << endl;

}

void qs(int B[], int n)
{

quickSort(0, n-1, B, n);
cout << "Quick Sort: " << endl;	 
for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
	cout << endl;

}

void vivod(int B[], int n){
	int var;
    cout << "Выберите вариант сортировки - " << endl;
    cout << "1. Shell Sort" << endl;
    cout << "2. Haor Sort" << endl;
    cout << "3. Quick Sort" << endl;
	cout << "4. Выход" << endl;
	cout << endl;
		do
    { 
	cout << "----->  " ;
    cin >> var; 
    switch (var) {
	
        case 1:
           shell(B, n);
            break;

        case 2:
            hoar(B, n);
            break;
        case 3:
            qs(B, n);
            break;
        case 4:
            cout << "Выход из программы..." << endl;
            exit(0);
            break;
		default:
            cout<<"Error"<<endl;
                 }
    }
while(var!=5);
}

void zad(int B[], int n)
{


for(int i = 0; i < n; i++)
	{
	 cout << B[i] << " ";
	}
	cout << endl;


}

int main()
{
	setlocale(LC_ALL, "Russian");
const int n = 20;
	int B[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	cout << "Заданный массив: " << endl;
	
    zad(B, n);
	vivod(B, n);
 
	system("pause");
	return 0;
}

