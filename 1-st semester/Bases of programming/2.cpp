#include "stdafx.h" 
#include "math.h" 
#include <windows.h> 

int _tmain(int argc, _TCHAR* argv[]) 
{ 
double t1 = 0, t2 = 0; 
double a1 = 0, x1 = 0,b1 = 0, a2 = 0, x2 = 0; 

printf("Enter a1\n"); 
scanf_s("%lf", &a1); 
printf("Enter b1\n"); 
scanf_s("%lf", &b1); 
printf("Enter x1\n"); 
scanf_s("%lf", &x1); 

if ((a1 != 0) && (x1 >= 0)) 
{ 
t1 = (2 * (3 * a1*x1 - 2 * b1)*sqrt(pow(x1, 3))) / (15 * a1*a1); 
printf("Result: %f\n", t1); 
} 
else 
printf("Your parameters are invalid\n"); 

printf("Enter a2\n"); 
scanf_s("%lf", &a2); 
printf("Enter x2\n"); 
scanf_s("%lf", &x2); 

if (cos(a2*x2) != 0) 
{ 
t2 = cos(a2*x2) + pow(sin(a2*x2), 3) / pow(cos(a2*x2), 2); 
printf("Result: %f\n", t2); 
} 
else 
printf("Your parameters are invalid\n"); 

system("pause"); 
return 0; 
}