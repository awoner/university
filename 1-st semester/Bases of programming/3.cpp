/**************************************************/
/*           ������������ ������ �3               */
/*       �������������� ��������� � �������       */
/*                ������� �1.                     */
/**************************************************/
#include <stdio.h>
#include <math.h>
#include <windows.h>
int main(void) {
/* ���������, ������� �������� */
double x,y;
/* ���������, ������� �������� � ��������� */
double a=12.5, b=1.3;
double c=14.1, d=2.7;
double t1, t2; /* ���������� */
double ax; /* ������� ���������� */
printf("������� x, y >");
scanf_s("%lf %lf",&x,&y);
ax=a*x;
t1=ax/y+b/y*y*log(y*x+c);
ax=sqrt((c-b)*(c+b))*tan(ax);
t2=log((ax+b)/(ax-b))/2/a/b;
printf("t1 = %lg\n",t1);
printf("t2 = %lg\n",t2);
system("pause"); 
return 0; 
}