
#include <iostream> 
#include <cstdlib> 

using namespace std; 

void zap(int a[][300], int s) 
{ 
for (int i = 0; i < s; i++) 
for (int j = 0; j < s; j++) 
a[i][j] = rand() % 10; 
} 

void Sort(int a[][300], int s, int q) 
{ 
int z; 
for (int i = 0; i < s - 1; i++) 
for (int j = 0; j < s - 1; j++) 
if (a[j][q] > a[j + 1][q]) 
{ 
z = a[j][q]; 
a[j][q] = a[j + 1][q]; 
a[j + 1][q] = z; 
} 
} 

int GetSum(int a[][300], int s, int j) 
{ 
int sum = 0; 
for (int i = 0; i < s; i++) 
sum += a[i][j]; 
return (sum); 
} 

int GetIndexOfMin(int a[][300], int s) 
{ 
int min = GetSum(a, s, 0), curr = 0, index = 0; 
for (int j = 1; j < s; j++) 
{ 
curr = GetSum(a, s, j); 
if (curr < min) 
{ 
min = curr; 
index = j; 
} 
} 
return (index); 
} 

int GetIndexOfMax(int a[][300], int s) 
{ 
int max = GetSum(a, s, 0), curr = 0, index = 0; 
for (int j = 1; j < s; j++) 
{ 
curr = GetSum(a, s, j); 
if (curr > max) 
{ 
max = curr; 
index = j; 
} 
} 
return (index); 
} 

void Replace(int a[][300], int s) 
{ 
int min = GetIndexOfMin(a, s); 
int max = GetIndexOfMax(a, s); 
for (int i = 0; i < s; i++) 
{ 
int t = a[i][max]; 
a[i][max] = a[i][min]; 
a[i][min] = t; 
} 
Sort(a, s, min); 
Sort(a, s, max); 
} 

void vivod1(int a[][300], int s) 
{ 
for (int i = 0; i < s; i++) 
{ 
for (int j = 0; j < s; j++) 
cout << a[i][j] << " "; 
cout << endl; 
} 
cout << endl; 
} 

void vivod2(int a[][300], int s) 
{ 
cout << "Zminena: " << endl; 
for (int i = 0; i < s; i++) 
{ 
for (int j = 0; j < s; j++) 
cout << a[i][j] << " "; 
cout << endl; 
} 
} 

int main() 
{ 
int s; 
cout << "s = "; 
cin >> s; 
int a[300][300]; 
int c = 0, b = 0, num = 1, sum = 0, min = 0; 
zap(a, s); 
vivod1(a, s); 
Replace(a, s); 
vivod2(a, s); 
return 0; 
}