#include <stdio.h>
#include <math.h>
int main(){
float a,bx,xn,xk,b,y,i,ax,sum=0;
do{
printf("Enter a: ");
scanf_s("%f",&a);
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
printf("| X Y | \n");
printf("___________________\n");
while(xn<=xk)
{
sum=0;
ax=a*b;
if(ax==0)
printf("|%-7.4f | neverno|\n",xn);
else
{
for(double k = 1;k<=6;k++)
sum = sum + xn/exp(n+1); sum = sum + (sin(kx)/x*x);
y=(bx/a+x)+sum;
printf("|%-8.4f|%-8.4f|\n",xn,y);
}
xn=xn+i;
}return 0;
}