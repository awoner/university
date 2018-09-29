// lab4m3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <GL/glut.h>

#define N 6
#define N1 4
#define N2 5

using namespace std;

int WinHeight, WinWidth = WinHeight = 600;
int WinFar = 10;
double *x, *y, **a, **c, *f, *v1, *v2;

//double f(double x);
////double f_d(double x);
//void Func();

void Init_Matrix() {
	x = new double[N + 1];
	y = new double[N + 1];
	a = new double*[2];
	for (int i = 0; i < 2; i++)
		a[i] = new double[4];
	c = new double*[4];
	for (int i = 0; i < 4; i++)
		c[i] = new double[5];
	f = new double[N + 1];
	v1 = new double[N + 1];
	v2 = new double[50];
}

void Delete_Matrix() {
	delete[] x;
	delete[] y;
	for (int i = 0; i < 2; i++)
		delete[] a[i];
	for (int i = 0; i < 4; i++)
		delete[] c[i];
	delete[] f;
	delete[] v1;
	delete[] v2;
}

double fu(double x) {
	return x*x + sin(x);
}

void Draw_Graphic() {
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-WinWidth, 0);
	glVertex2f(WinWidth, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0, WinHeight);
	glVertex2f(0, -WinHeight);
	glEnd();

	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 0.0);

	for (int i = 0; i < N; i++)
		glVertex2d(x[i], y[i]);

	glEnd();

}
//1,2,3 ,4 //4321

void Draw_Graphic1(double xxx, double x1, double x2, double H1, double o1, double o2) {

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
		glColor3f(1.0, 0.0, 0.0);
		for (xxx = x1 - H1; xxx < x2 + H1; xxx += 0.01) {
			o1 = fu(xxx);
			glVertex2d(xxx, o1);
		}
		glEnd();

		glLineWidth(0.1);
		glBegin(GL_LINE_STRIP);
		int s;
		glColor3f(0.0, 1.0, 0.0);
		for (xxx = x1 - H1; xxx < x2 + H1; xxx += 0.01) {
			if (xxx < x[3]) {
				s = 0;
			}
			else {
				s = 1;
			}
			o2 = a[s][0] + a[s][1] * xxx + a[s][2] * pow(xxx, 2) + a[s][3] * pow(xxx, 3);
			glVertex2d(xxx, o2);
		}
		glEnd();
	

}

void SLAU(double **Q, int l){

	double matrix[4][5];
	double tmp, max, xx[4], aa;
	short int n1, n2, n3, m, done[4], u;

	for (int i = 0; i < N1; i++)
		done[i] = 3;

	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < N2; j++)
			matrix[i][j] = Q[i][j];
	}

	for (int i = 0; i < N1 - 1; i++){
		max = -100; n1 = 0; n2 = i;
		for (int j = 0; j < N1; j++)
			if ((matrix[j][i]>max) && (done[j] == 3)) { 
				max = matrix[j][i];
				n1 = j;
				n2 = i;
			}//выбираю главный элемент по каждом столбике #i
		tmp = max;
		done[n1] = n2;

		for (int j = i; j < N2; j++)
			matrix[n1][j] /= tmp; //делим рядок н1 на первый, главный элемент

		for (u = 0; u < N1; u++){
			if (done[u] == 3){
				tmp = matrix[u][i];
				for (int k = i; k < N2; k++)
					matrix[u][k] = matrix[u][k] - tmp*matrix[n1][k];
			}
		}
	}

	for (int i = N1 - 1; i >= 0; i--){
		for (int j = 0; j < N1; j++)
			if (done[j] == i){
				n1 = j;
				xx[i] = 0;
				aa = matrix[n1][N1];
				for (int k = N1 - 1; k > i; k--)
					aa = aa - matrix[n1][k] * xx[k];
				xx[i] = aa / matrix[n1][i];
			}
	}

	for (int i = 0; i<N1; i++){
		a[l][i] = xx[i];
	}

}

void Func() {
	
	
	double x1 = -2, x2 = 3;
	cout << "x1:\t";
	cin >> x1;
	cout << "x2:\t";
	cin >> x2;
	Init_Matrix();
	double H = (x2 - x1) / N;
	
	cout << endl;
	for (int i = 0; i <= N; i++) {
		x[i] = x1 + i * H;
		y[i] = fu(x[i]);
		cout << "f(" << x[i] << ") = " << setw(10) << y[i] << ";" << endl;
	}
	//Draw_Graphic();	

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			c[i][j] = pow(x[i], j);
		c[i][4] = y[i];
	}

	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int j = 0; j < 5; j++) {
			cout  << setw(10) << c[i][j] << "|";
		}
		cout << endl;
	}

	SLAU(c, 0);

	cout << "\na[i] = " << endl;
	for (int i = 0; i < N1; i++)
		cout << a[0][i] << "   ";
	cout << endl;

	int k = 6;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
			c[i][j] = pow(x[k], j);
		c[i][4] = y[k];
		k--;
	}

	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int j = 0; j < 5; j++) {
			cout << setw(10) << c[i][j] << "|";
		}
		cout << endl;
	}

	SLAU(c, 1);

	cout << "\na[i] = " << endl;
	for (int i = 0; i < N1; i++)
		cout << a[1][i] << "   ";
	cout << endl;
	
	int s = 0;
	//мы нашли 2 набора коэфициентов, 
	//что хранятся в двумерном массиве а. 
	//теперь мы просто находим значения через 
	//этy функцию для всех хі. а потом мы построим график,
	//а еще найдем разцицу 
	for (int i = 0; i <= N; i++){
		if (i < 4)
			s = 0;
		else
			s = 1;
		f[i] = a[s][0] + a[s][1] * x[i] + a[s][2] * pow(x[i], 2) + a[s][3] * pow(x[i], 3);
	}
	
	cout << endl << setw(10) << "X" << setw(10) << "F(x)" << endl;
	for (int i = 0; i <= N; i++)
		cout << "\n" << setw(10) << x[i] << "\t" << setw(10) << f[i] << endl;
	cout << "\n" << endl;

	int i;
	cout << endl << setw(10) << "X" << setw(5) << "\tF(x)" << setw(5) << "\t\tY(x)-F(x)" << endl;
	for (i = 0; i <= N; i++){
		v1[i] = y[i] - f[i];
		cout << "\n" << setw(10) << y[i] << "\t" << setw(10) << f[i] << "\t" << setw(10) << v1[i] << endl;
	}
	cout << endl;

	double H1, xxx, o, o1, o2, o3;
	H1 = (x2 - x1) / (4 * N);
	xxx = x1 - H1;
	int j = 0;
	cout << "(Y(x)-F(x))*100/Y(x)" << endl;
	while (xxx < (x2 + H1))
	{
		if (xxx < x[3])
			s = 0;
		else
			s = 1;
		o1 = fu(xxx);
		o2 = a[s][0] + a[s][1] * xxx + a[s][2] * pow(xxx, 2) + a[s][3] * pow(xxx, 3);
		v2[i] = ((o1)-(o2)) * 100 / (o1);
		j++;
		xxx = xxx + H1;
		cout << setw(10) << o1 << "\t" << setw(10) << o2 << "\t" << setw(10) << v2[i] << endl;
	}
	j = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	Draw_Graphic1(xxx, x1, x2, H1, o1, o2);
	glFlush();

}

void Init_Grafc() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WinWidth / 60, WinWidth / 60, -WinHeight / 60, WinHeight / 60, -WinFar / 10, WinFar / 10);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WinWidth, WinHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphic");
	Init_Grafc();
	Func();
	glutMainLoop();
	Delete_Matrix();
	return 0;
}
