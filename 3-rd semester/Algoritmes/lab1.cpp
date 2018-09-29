#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h> 

typedef struct{
	int x1, x2, n;
	float x, dx, fx, eps, sum;
	void EnterVals();
	void Iter();
}Fun; 

float Summ(Fun & func, int n, float sum, float x, float fx);

void Fun::EnterVals(){
	printf("Enter diapasone\n\n");
	printf("x1: ");
	scanf_s("%d", &x1);
	printf("x2: ");
	scanf_s("%d", &x2);
	printf("\nEnter step\n\n");
	printf("dx: ");
	scanf_s("%f", &dx);
	printf("\nEnter precision\n\n");
	printf("eps: ");
	scanf_s("%f", &eps);
	printf("\n\n");
}

void Fun::Iter(){
	printf("ITERATION\n\n");
	sum = 0;
	fx = 1;
	for(x = x1; x <= x2; x += dx){
		printf("X = %.2lf  ", x);
		n = 1;
		sum=0;
		do{
			fx = (pow(-1, (float)n-1)*pow(x, 2*n-1))/(pow(2*(float)n-1, 2*(n-1)-1)); 
			sum += fx;
			n++;
		}while(abs(fx) > eps);
		printf("Y = %.2lf\n", sum);
	}
	printf("\n\n\n");
	sum = 0;
	fx,n = 1;
	x = x1;
}

float Rec(Fun & func, float x, int n, float y, float fx){
	if(x <= func.x2){
		printf("X = %.2lf  ", x);
		Summ(func, n, y, x, fx);
		return Rec(func, x += func.dx, 1, 0, 1);
	}
}

float Summ(Fun & func, int n, float y, float x, float fx){
	fx = (pow(-1, (float)n-1)*pow(x, 2*n-1))/(pow(2*(float)n-1, 2*(n-1)-1)); 
	y += fx;
	if(abs(fx) > func.eps){
		return Summ(func, n + 1, y, x, 1);
	}else{
		printf("Y = %.2lf\n", y);
		return y;
	}
}

int main()
{
	Fun fun;
	fun.EnterVals();
	fun.Iter();
	printf("RECURSION\n\n");
	Rec(fun, fun.x, fun.n, fun.sum, fun.fx);
	_getch();
	return 0;
}
