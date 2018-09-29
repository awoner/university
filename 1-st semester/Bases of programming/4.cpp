#include "stdafx.h"
#include <stdio.h>
#include <math.h>
int main(){
float a,c,xn,xk,b,y,i,ax;
do{
printf("Enter a: ");
scanf_s("%f",&a);
printf("Enter b: ");
scanf_s("%f",&b);
printf("Enter c: ");
scanf_s("%f",&c);
printf("Enter x nachalo: ");
scanf_s("%f",&xn);
printf("Enter x konec: ");
scanf_s("%f",&xk);
printf("Enter shag: ");
scanf_s("%f",&i);
if(xn>xk||i<=0)
printf("EROR\n");
}
while(xn>xk||i<=0);
printf("|   X         Y  | \n");
printf("___________________\n");
while(xn<=xk)
{
ax=a*xn+b;
if(ax<=0)
printf("|%-7.4f | neverno|\n",xn);
else
{
y=(b*c+sin(xn))/(ax+log(xn))-exp(ax);
printf("|%-8.4f|%-8.4f|\n",xn,y);
}
xn=xn+i;}
printf("___________________\n");
getchar();
getchar();
return 0;
}
