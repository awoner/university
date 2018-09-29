#include "stdafx.h"
#include <glut.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int n = 4;
int WinHeight, WinWidth = WinHeight = 400;
int WinFar = 10;

	void Print(double arr[n][n]) {
		for (int i = 0; i < n; i++) {
			cout << "|";
			for (int j = 0; j < n; j++) {
				cout << setw(11) << arr[i][j];
			}
			cout << "|\n";
		}
	}

	void Nvect(double x[n]) {
		double arr1[n][n] = { { 4, 1000, 2, 3 },{ 3, -1, 1, -3 },{ 100, -3, -2, 0 },{ 2, 2, 0, -1 } };
		double vect[n] = { 5, -1, -3, -1 };
		cout << "vector of discrepancies: {";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr1[i][j] *= x[i];
				vect[i] -= arr1[i][j];

			}
			cout << vect[i] << ", ";
		}
		cout << "}\n\n";
	}

	void Approx(double arr[n][n], double vect[n], int count, double eps) {	
		bool flag = false;
		int k_max = 50;
		double xk[n], x[n] = { 0, 0, 0, 0 };
		while (flag == false && (count <= k_max)) {
			for (int i = 0; i < n; i++) {
				double s = 0;
				for (int j = 0; j < n; j++) {
					s += arr[i][j] * x[j];
				}
				xk[i] = x[i] - s + vect[i];
			}
			int i = 0;
			double g = 0, s = 0;
			while (g < eps && i < n) {
				g = abs(xk[i] - x[i]);
				s = abs(xk[i]);
				if (s > 1) {
					g /= s;
				}
				i++;
			}

			count++;
			cout << "xk = {";
			for (int i = 0; i < n; i++) {
				x[i] = xk[i];
				cout << x[i] << ", ";
			}
			cout << " }\n";
			if (i == n) {
				flag = true;
				cout << "\nSolution found\n";
				cout << "xk = {";
				for (int i = 0; i < n; i++) {
					x[i] = xk[i];
					cout << x[i] << ", ";
				}
				cout << " }\n";
			}
		}
		if (count > k_max) {
			cout << "\nThe iteration method does not match\n";
		}
		cout << "\nCount " << count << endl;
	
	}

	int Approx1(double arr[n][n], double vect[n], double eps) {
		int count = 0;
		bool flag = false;
		int k_max = 50;
		double xk[n], x[n] = { 0, 0, 0, 0 };
		while (flag == false && (count <= k_max)) {
			for (int i = 0; i < n; i++) {
				double s = 0;
				for (int j = 0; j < n; j++) {
					s += arr[i][j] * x[j];
				}
				xk[i] = x[i] - s + vect[i];
			}
			int i = 0;
			double g = 0, s = 0;
			while (g < eps && i < n) {
				g = abs(xk[i] - x[i]);
				s = abs(xk[i]);
				if (s > 1) {
					g /= s;
				}
				i++;
			}
			if (i == n) {
				flag = true;
			}
			count++;
			for (int i = 0; i < n; i++) {
				x[i] = xk[i];
			}

		}
		return count;
	}

	void Jordan(double arr[n][n], double vect[n], int count, double eps) {
		for (int j = 0; j < n; j++) {
			for (int i = j; i < n; i++) {
				if (arr[i][j] > arr[j][j]) {
					for (int k = 0; k < n; k++) {
						swap(arr[i][k], arr[j][k]);
					}
					swap(vect[i], vect[j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			double tmp = arr[i][i];
			vect[i] /= tmp;
			for (int j = 0; j < n; j++) {
				arr[i][j] = arr[i][j] / tmp;
			}
		}
		cout << "\n";
		cout << "Transformed matrix:\n";
		Print(arr);
		cout << "\n";
		cout << "Vector: {";
		for (int i = 0; i < n; i++) {
			cout << vect[i] << ", ";
		}
		cout << "}\n";
		cout << "\n";	
		Nvect(vect);
		Approx(arr, vect, count, eps);
	}



void DrawGraphic(double arr[n][n], double vect[n], float x, float y) {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-x, 0);
	glVertex2f(x, 0);
	glEnd();

	glBegin(GL_LINES); 
	glVertex2f(0, y);
	glVertex2f(0, -y);

	for (int i = -WinWidth; i < WinWidth; i++) {
		glVertex2f(i * 3, -0.7);
		glVertex2f(i * 3, 0.7);
	}

	for (int i = -WinHeight; i < WinHeight; i++) {
		glVertex2f(-0.7, i * 3);
		glVertex2f(0.7, i * 3);
	}

	glEnd();
	glLineWidth(3);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 0.0);

	double eps = 0.1; 
	int c = 0;

	while (eps >= pow(10, -5)) {
		c = Approx1(arr, vect, eps);
		glVertex2d(c, eps * WinWidth); 
		eps /= 10;
	}

	glEnd();
	glDisable(GL_LINE_SMOOTH);
}

void Draw() {
	double arr[n][n] = { { 4, 1000, 2, 3 },{ 3, -1, 1, -3 },{ 100, -3, -2, 0 },{ 2, 2, 0, -1 } };
	double vect[n] = { 5, -1, -3, -1 };
	int count = 0;
	double eps = 0.001;
	cout << "Original Matrix:\n";
	Print(arr);	
	Jordan(arr, vect, count, eps);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawGraphic(arr, vect, WinWidth, WinHeight);
	glFlush();
}

void Init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WinWidth / 8, WinWidth / 8, -WinHeight / 8, WinHeight / 8, -WinFar / 10, WinFar / 10);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WinWidth, WinHeight);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Graphic");
	glutDisplayFunc(Draw);
	Init();
	glutMainLoop();
	return 0;
}