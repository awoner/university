#include "stdafx.h"
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h> 
#include <time.h>
#include <iostream>

using namespace std;

//=========================1=========================

void Arr_Zap(int arr[10]){
	cout << "Original array: ";
	for(int i = 0; i < 10; i++){
		arr[i] = rand() % (100 + 100 + 1) - 100; 
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Bubble_Sort(int arr[10]){
	for(int i = 0; i < 10; i++){
		for(int j = 9; j > 0; j--){
			if(arr[j-1] >= arr[j]){
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void Vivod(int arr[10]){
	cout << "Sorted array: ";
	for(int i = 0; i < 10; i++){
		cout << arr[i] << " ";  
	}
}

//=========================2=========================

void Arr1_Zap(double arr1[10]){
	cout << "Original array: ";
	for(int i = 0; i < 10; i++){
		arr1[i] = rand() % (50 + 1); 
		cout << arr1[i] << " ";
	}
	cout << endl;
}

void Selection_Sort(double arr1[10]){
	for(int i = 0; i < 9; i++){
		int min = i;
		for(int j = i + 1; j < 10; j++){
			if(arr1[j] >= arr1[min]){
				min = j;
			}
		}
		int temp = arr1[i];
		arr1[i] = arr1[min];
		arr1[min] = temp;
	}
}

void Vivod1(double arr1[10]){
	cout << "Sorted array: ";
	for(int i = 0; i < 10; i++){
		cout << arr1[i] << " ";
	}
}

//=========================3=========================

void Arr2_Zap(int arr2[10]){
	cout << "Enter original array: \n";
	for(int i = 0; i < 10; i++){
		cin >> arr2[i];   
	}
	cout << endl;
}

void Insert_Sort(int arr2[10]){
	for (int i = 0; i < 10; i++) {
    int tmp = arr2[i];	//поиск места элемента
		int j = i;
		while((j > 0) && (arr2[j - 1] > tmp)){
			arr2[j] = arr2[j - 1];
			j--;
		}arr2[j] = tmp;
  }
}

void Vivod2(int arr2[10]){
	cout << "Sorted array: ";
	for(int i = 0; i < 10; i++){
		cout << arr2[i] << " "; 
	}
}

//=========================4=========================

void Arr3_Zap(int m, int arr3[]){
	for(int i = 0; i < 2 * m + 1; i++){
		arr3[i] = rand() % 10; 
	}
	cout << endl;
}

void Median(int m, int arr3[]){
	for(int i = 0; i < 2*m+1; i++){
		int min = i;
		for(int j = i + 1; j < 2*m+1; j++){
			if(arr3[j] > arr3[min]){
				min = j;
				
			}
		}
		int temp = arr3[i];
		arr3[i] = arr3[min];
		arr3[min] = temp;
	}
	cout << endl << endl << "\nArray: ";
	for(int i = 0; i < 2 * m + 1; i++){
		cout << arr3[i] << " ";
	}
	cout << "\nMedian:" << arr3[m] << endl;
}

////////void Vivod3(int m, int arr3[]){
////////	cout << "Sorted array:";
////////	for(int i = 0; i < 2 * m + 1; i++){
////////		cout << arr3[i] << " ";
////////	}
////////}

//=========================5=========================

void Arr4_Zap(int m, int arr4[]){
	cout << endl << endl << "Array: ";
	for(int i = 0; i < m; i++){
		arr4[i] = rand() % 10; 
		cout << arr4[i] << " ";
	}
}

void Mod(int m, int arr4[]){
		int ch = 0,
			ch_m = 0,
			mod = 0,
			max_mod = 0,
			flag = 0;
	 for (int i = 0; i < m; i++){
        ch = 0;
        for(int j = 0; j < m; j++){
            if(arr4[i] == arr4[j]){
                ch++;
            }
        }
        if(ch > max_mod){
            flag = 1;
            max_mod = ch;
            ch_m = arr4[i];
        }
        else if(ch == max_mod && arr4[i] != ch_m){
            flag = 0;
        }
        
        mod = ch_m;
    }
	cout << "\nModa: " << mod << "\n\n";
}
   


int main()
{
	srand(time(NULL));
	const int m = 12;
	//==================================================
	cout << "Bubble Sort:" << endl;
	int arr[10];// rand[-100; 100), pyzurek
	Arr_Zap(arr);
	Bubble_Sort(arr);
	Vivod(arr);
	//==================================================
	cout << "\n\nSelection Sort:" << endl;
	double arr1[10];//rand[0; 50), prostoy vibor
	Arr1_Zap(arr1);
	Selection_Sort(arr1);
	Vivod1(arr1);
	//==================================================
	cout << "\n\nInsert Sort:" << endl;
	int arr2[10];//klava, prosyoe vklyuchenie
	Arr2_Zap(arr2);
	Insert_Sort(arr2);
	Vivod2(arr2);
	//==================================================
	int arr3[2 * m + 1];//rand, <=|>=
	Arr3_Zap(m, arr3);
	Median(m, arr3);
	//Vivod3(m, arr3);
	//==================================================
	int arr4[m];//rand, nayti samiy chastiy el
	Arr4_Zap(m, arr3);
	Mod(m, arr3);
	//==================================================
	_getch();
	return 0;
}

