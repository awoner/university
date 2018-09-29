/**************************************************/
/*           Лабораторная работа №3               */
/*       Арифметические выражения и функции       */
/*                Вариант №1.                     */
/**************************************************/
#include <stdio.h>
#include <math.h>
#include <windows.h>
int main(void) {
/* параметры, которые вводятся */
double x,y;
/* параметры, которые задаются в программе */
double a=12.5, b=1.3;
double c=14.1, d=2.7;
double t1, t2; /* результаты */
double ax; /* рабочая переменная */
printf("Введите x, y >");
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