#include "stdafx.h"
#include <iostream>
#include <time.h>
 #include <cstring> 
using namespace std;


void zap(int **ptrarray, int n, int m)
{


for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			ptrarray[i][j] = rand() % 10;
			cout << ptrarray[i][j] << " ";
		}
		cout << endl;
    }
}

void funk_after( int **ptrarray, int n , int m)
{
cout << "Двумерный массив после: ";
cout << endl;
    for (int i = 0; i < n; i++)
{
	for(int j=0; j<m; j++)
		{
	cout << ptrarray[i][j] << " ";
		}
		cout << endl;
}
	for (int i = 0; i < n; i++)
         {
	  delete [] ptrarray[i];
}

}

int ** Slide(int ** ptrarray, int m, int n/*, int index*/)
{
int index;
cout << "Какую строку: ";
cin >> index;
	if (index != 0)
		index--;
	int ** tmp = new int *[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		tmp[i] = new int[n];
	}

	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = ptrarray[i][j];
		}
	}

	for (int j = 0; j < n; j++)
	{
		tmp[index][j] = 0;
	}


	for (int i = index; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i + 1][j] = ptrarray[i][j];
		}
	}
	return tmp;
 
         }





void vivod1(int k , int ptrarr1[], int ptrarr[])
{
cout << "Одномерный массив после: ";
    for (int i = 0; i < k; i++)

	cout << ptrarr1[i] << ' ';
    cout << endl;
   delete [] ptrarr1;
}




void delete_el (int k , int ptrarr1[], int ptrarr[])
{
	
for (int i = 0; i < k; i++)
        if (ptrarr[i] % 2 == 0)
            while (i < k)
            {
                ptrarr[i] = ptrarr[i+1];
               i++;
            }
    k -= 1;
    for (int i = 0; i < k; i++)
        ptrarr1[i] = ptrarr[i];
    delete[] ptrarr;
	vivod1(k, ptrarr1, ptrarr);

}


void zap1 (int k , int ptrarr[])
{

srand(time(0));

for( int i = 0; i < k; i++)
{
ptrarr[i] = rand () % 10;
cout << ptrarr [i] << " "; 


}
 
  cout << endl;

}

void vvod(/* int index*/){
int input;
cout<<"Меню"<<endl;
cout<<"1.Формирование массивов"<<endl;
cout<<"2.Печать массивов"<<endl;
cout<<"3.Удалить первый чётный элемент"<<endl;
cout<<"4.Добавить строку с заданным номером"<<endl;
cout<<"5.Выход"<<endl;
 cout << "Введите действие: " << endl;
int *ptrarr1=NULL ;
	int *ptrarr=NULL;
  int **ptrarray=NULL; 
 int k, m,  n;
do
{

cin>>input;
switch(input)
{
cout << "" << endl;
case 1:
		cout << "Одномерный массив- " << endl;
cout << "Введите размер одномерного массива: ";
cin >> k;
	
 	cout << "Двумерный массив- " << endl;
cout << "Введите количевство строк: ";
cin >> n;

cout << "Введите количевство столбцов: ";
cin >> m;
    
ptrarr1 = new int [k];
	ptrarr = new int [k];
    ptrarray = new int* [n]; 
      for (int i = 0; i < n; i++)
         {
		   ptrarray[i] = new int [m];
	     }
	  cout << endl;
	  cout << endl;
cout << "Введите действие: " << endl;
break;

case 2:
	cout << "Одномерный массив:" << endl;
zap1(k, ptrarr);
cout << "Двумерный массив:" << endl;
 zap(ptrarray, n, m);
 cout << endl;
 cout << endl;
cout << "Введите действие: " << endl;
break;
case 3:
  delete_el(k, ptrarr1, ptrarr);
  cout << endl;
	  cout << endl;
cout << "Введите действие: " << endl;
break;

case 4:
    ptrarray = Slide(ptrarray, n,m/*,index*/);
    funk_after(ptrarray, n+1, m);
	cout << endl;
	  cout << endl;
cout << "Введите действие: " << endl;

break;
case 5:
exit(0);
	break;
default:
cout<<"Error"<<endl;

}
}

while(input!=6);

} 

int main()
{
setlocale(LC_ALL, "Russian");
srand(time(0));
vvod();  
system("pause");
	return 0;
}



