//x^2 + cos(2x)
//h = (b - a) / n

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <GL\glew.h>
#include <GL\freeglut.h>

using namespace std;

double *u, *x, *y;

double f(double x) {
	return pow(x, 2) + cos(2 * x);
}

double f_der(double x) {
	return 2.0 - 4.0 * cos(2 * x);
}

glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex2f(-WinWidth, 0);
glVertex2f(WinWidth, 0);
glEnd();

glBegin(GL_LINES);
glVertex2f(0, WinHeight);
glVertex2f(0, -WinHeight);
glEnd();


glLineWidth(1);
glBegin(GL_LINE_STRIP);
glColor3f(1, 0, 0);

for (int i = 0; i < n; i++)
glVertex2f(x[i], f(x[i]));
glEnd();

glLineWidth(1);
glBegin(GL_LINE_STRIP);
glColor3f(0, 1, 0);

for (int i = 0; i < n; i++)
glVertex2f(x[i], u[i]);
glEnd();

glLineWidth(1);
glBegin(GL_LINE_STRIP);
glColor3f(0, 1, 0);

for (int i = 0; i < n; i++)
glVertex2f(x[i], f_der(x[i]));
glEnd();

glutSwapBuffers();
}

int main()
{
    double a = 1.0;
	double b = 6.0;
	double n = 10.0;
	double h = (b - a) / n;
	u = new double[n + 1];
	x = new double[n + 1];
	y = new double[n + 1];
	cout << "------------------" << endl;
	cout << "|" << setw(6)<< "x|"<< setw(11) << "f(x)|" << endl;
	cout << "------------------" << endl;
	for (int i = 0; i <= n; i++){
		x[i] = a + i * h;
		y[i] = f(x[i]);
		cout << "|" << setw(5) << x[i] << "|" << setw(10) << y[i] << "|" << endl;
		cout << "------------------" << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
	cout << "|" << setw(15) << "D_approx|" << setw(15) << "D_an|" << setw(35) << "((D_an - D_approx) / D_an) * 100|" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 1; i < n; i++){
		u[i - 1] = (y[i - 1] - 2.0 * y[i] + y[i + 1]) / pow(h, 2);
		cout << "|" << setw(14) << u[i - 1] << "|" << setw(14) << f_der(x[i]) << "|" << setw(34) << ((f_der(x[i]) - u[i - 1]) / f_der(x[i])) * 100 << "|" << endl;
		cout << "------------------------------------------------------------------" << endl;
	}

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
    glutMainLoop();
    
    delete[] x;
	delete[] y;
	delete[] u;
 
	_getch();
    return 0;
}

