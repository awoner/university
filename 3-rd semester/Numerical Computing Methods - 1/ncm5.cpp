//2x^4 - 8x^3 + 8x^2 - 1 = 0; x[-10; 10]
//После отделения корней следует уточнить корни одним из следующих методов
//с точностью ε = 0,001; 
//1) половинного деления
//1) |f(xk)| < ε   
//1) Построить столбчатую диаграмму для первого корня N=N(ε), 
//где N – требуемое число итераций; εk+1=εk/10; ε0=0.1; k=0,1,2,3,4.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <GL\glew.h>
#include <GL\freeglut.h>
#define H 0.5
#define eps 0.001

using namespace std;

int WinWidth = 600, WinHeight = WinWidth, *k;
double *x, *y, *X, *Y, *e;

double f(double x) {
	return 2.0 * pow(x, 4) - 8.0 * pow(x, 3) + 8.0 * pow(x, 2) - 1.0;
}

double f_p(double x) {
	return 8.0 * pow(x, 3) - 24.0 * pow(x, 2) + 16.0 * x;
}

void Graphic() {
	glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-WinWidth, 0);
	glVertex2f(WinWidth, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0, WinHeight);
	glVertex2f(0, -WinHeight);
	glEnd();


	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);

	for (int i = 0; i<200; i++)
		glVertex2f(X[i], Y[i]);  
	glEnd();

	glutSwapBuffers();
}

void Diagram() {
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(1);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(0.0, WinHeight);//-----------у
	glVertex2f(0.0, -WinHeight);
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-WinWidth, 0.0);
	glVertex2f(WinWidth, 0.0);//--------------х
	glEnd();


	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(50);
	for (int i = 0; i <= 5; i++){
		glBegin(GL_LINES);
		glVertex2f(k[i], 0.0001);
		glVertex2f(k[i], e[i]);	
		glEnd();
	}

	glutSwapBuffers();
}

void Init_Arrays(int m) {
	x = new double[m];
	y = new double[m];
	X = new double[200];
	Y = new double[200];
	e = new double[4];
	k = new int[50];
}

void Method(double a, double b) {
	int i = 1;
	double xc = (a + b) / 2.0, yc = 0;
	cout << "--------------------------------" << endl;
	cout << "|" << setw(5) << "K|" << setw(14) << "Yc|" << setw(12) << "Xc|" << endl;
	cout << "--------------------------------" << endl;
	while (abs(f(xc)) > eps) {
		xc = (a + b) / 2.0;
		yc = f(xc);
		k[i - 1] = i;
		cout << "|" << setw(4) << k[i - 1] << "|" << setw(13) << yc << "|" << setw(11) << xc << "|" << endl;
		cout << "--------------------------------" << endl;
		i++;
		if ((f(a) * yc) > 0)
			a = xc;
		else
			b = xc;
	}
}

void Func() {
	double a = -10.0;
	double b = 10.0;
	int m = (b - a) / H + 1;

	Init_Arrays(m);

	for (int j = 0; j < 200; j++)
	{
		X[j] = a + j*0.1;
		Y[j] = f(X[j]);
	}
	cout << "xЄ[" << a << "; " << b << "]" << endl;
	cout << "-----------------------" << endl;
	cout << "|" << setw(11) << "x|" << setw(11) << "f(x)|" << endl;
	cout << "-----------------------" << endl;
	for (int i = 0; i < m; i++){
		x[i] = a + i*H;
		y[i] = f(x[i]);
		cout << "|" << setw(10) << x[i] << "|";
		cout << setw(10) << y[i] << "|" << endl;
		cout << "-----------------------" << endl;
	}

	Method(a, b);

	e[0] = 0.1;
	for (int i = 1; i < 5; i++)
		e[i] = e[i-1] / 10;

	/*for (int i = 0; i < m; i++){
		if (f_p(x[i]) == 0) {
			b = i;
			break;
		}
	}

	cout << "\na = " << a << endl << "b = " << b << endl;

	Method(a, b);

	for (int i = 0; i < m; i++) {
		if (f_p(x[i]) == 0 && i == b)
			a = i;
		if (f_p(x[i]) == 0 && i != b)
			b = i;
	}

	cout << "\na = "<< a << endl << "b = " << b << endl;

	Method(a, b);

	for (int i = 0; i < m; i++) {
		if (f_p(x[i]) == 0 && i == b)
			a = i;
		if (f_p(x[i]) == 0 && i != b)
			b = i;
	}

	cout << "\na = " << a << endl << "b = " << b << endl;*/

	delete[] x;
	delete[] y;
	
}

int main(int argc, char *argv[]) {
	Func();
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WinWidth, WinHeight);
	glutInitWindowPosition(20, 400);
	glutCreateWindow("Graphic");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 3, -6, 6, -1, 1);
	glutDisplayFunc(Graphic);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WinWidth, WinHeight);
	glutInitWindowPosition(200, 400);
	glutCreateWindow("Diagram");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 10, -0.0017, 0.15, -1, 1);
	glutDisplayFunc(Diagram);
	
	glutMainLoop();

	delete[] X;
	delete[] Y;
	delete[] e;
	delete[] k;
	
	_getch();
    return 0;
}
