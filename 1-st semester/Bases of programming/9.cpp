
#include <iostream> 

using namespace std;
void ms (const int s, int a[], int &ot)
{

	for(int i=0;i<s;i++)
		if(a[i]<0) { 
			ot=i;
			break;
		}
			
	
}

void sdvg (const int s, int a[], int &ot)
{
  int temp, ind = -1; 
for(int i=s-1; i>=ot; i--){ 
if (a[i] % 2 == 0) 
{
if (ind == -1)
{
temp = a[i];
ind = i;
}
else
{
a[ind]=a[i]; 
ind=i;
}
} 
} 
a[ind]=temp;

for (int i=0; i<s; i++) 
cout << a[i] << " "; 
cout << endl; 


}


int main() 
{ 
int j=0, ot;
const int s=10; 
int a[s]={1, 3, 4, 7, -1, 8, 2, 5, 6, 9}; 
ms(s, a, ot);
 sdvg(s, a, ot);
 cout << ot;
 system("pause"); 
return 0; 
}   