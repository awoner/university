#include <iostream>
#include <iomanip>
//#include <GL\glut.h>
//#include <GL\freeglut.h>

using namespace std;

//---------Constants----------
int n = 2;
int m = 200;
constexpr double a = 0.0;
constexpr double b = 1.0;
double h = 0.2;
//int n = 150;// ((b - a) / h) + 10;
//----------------------------

double **x, **e, **k0, **k1, **k2, **k3, **k4, **k5, **y, **yp;
double **x1, **x2;
double **e1, **e2;
int WinWidth = 600, WinHeight = WinWidth;

void initArrs();
void deleteArrs();
double f(double, int);
double fp(double, double, int);
void MethodRKF5(double, double**, double**);
void MethodRK4(double, double**, double**);
void Graphic();

int main(int argc, char*argv[]) {
	int v;
	//do {
		cout << "1.Runga-Kutta-Felberg's method(5 order)" << endl;
		cout << "2.Runga-Kutta's method(4 order)" << endl;
		cout << "Enter your choice >> ";
		cin >> v;
		switch (v) {
		case 1:
		{
			initArrs();
			cout.flags(ios::fixed);
			cout.precision(7);

			MethodRKF5(h, x, e);

			MethodRKF5(h / 5, x1, e1);

			MethodRKF5(h / 25, x2, e2);

			//glutInit(&argc, argv);

			//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
			//glutInitWindowSize(WinHeight, WinHeight);
			//glutInitWindowPosition(20, 400);
			//glutCreateWindow("Graphic");
			//glClearColor(0, 0, 0, 0);
			//glMatrixMode(GL_PROJECTION);
			//glLoadIdentity();
			////glOrtho(-0.025, 2, -0.025, 200.0, -1, 1);
			//glOrtho(-0.025, 1.2, -0.025, 40.0, -1, 1);
			//glutDisplayFunc(Graphic);

			//glutMainLoop();
			deleteArrs();
			break;
		}
		case 2:
		{
			initArrs();
			cout.flags(ios::fixed);
			cout.precision(10);

			MethodRK4(h, x, e);

			MethodRK4(h / 5, x1, e1);

			MethodRK4(h / 25, x2, e2);
			deleteArrs();
			break;
		}
		default:
			cout << "Wrong choice!" << endl;
			break;
		}
	//} while (true);
	system("pause");
	return 0;
}

void initArrs() {
	x = new double*[n];
	e = new double*[n];
	x1 = new double*[n];
	e1 = new double*[n];
	x2 = new double*[n];
	e2 = new double*[n];
	k0 = new double*[n];
	k1 = new double*[n];
	k2 = new double*[n];
	k3 = new double*[n];
	k4 = new double*[n];
	k5 = new double*[n];
	y = new double*[n];
	yp = new double*[n];
	for (int i = 0; i < n; i++) {
		x[i] = new double[m];
		e[i] = new double[m];
		x1[i] = new double[m];
		e1[i] = new double[m];
		x2[i] = new double[m];
		e2[i] = new double[m];
		k0[i] = new double[m];
		k1[i] = new double[m];
		k2[i] = new double[m];
		k3[i] = new double[m];
		k4[i] = new double[m];
		k5[i] = new double[m];
		y[i] = new double[m];
		yp[i] = new double[m];
	}
}

void deleteArrs() {
	for (int i = 0; i < n; i++){
		delete[] k0[i];
		delete[] k1[i];
		delete[] k2[i];
		delete[] k3[i];
		delete[] k4[i];
		delete[] k5[i];
		delete[] y[i];
		delete[] yp[i];
		delete[] x[i];
		delete[] e[i];
		delete[] x1[i];
		delete[] e1[i];
		delete[] x2[i];
		delete[] e2[i];
	}
	delete[] k0;
	delete[] k1;
	delete[] k2;
	delete[] k3;
	delete[] k4;
	delete[] k5;
	delete[] y;
	delete[] yp;
	delete[] x;
	delete[] x1;
	delete[] x2;
	delete[] e;
	delete[] e1;
	delete[] e2;
}

double f(double x, int flg) {
	if (flg == 0)
		return (2.5 - 3.5 * exp((-1.0 / 0.03) * ((x * x / 2.0) + x)));
	if (flg == 1)
		return sin(x);
}

double fp(double x, double y, int flg) {
	if (flg == 0)
		return ((5.0 / 2.0) * (1.0 + x) - (1.0 + x) * y) / 0.03;
	if (flg == 1)
		return cos(x);
}

void MethodRKF5(double h1, double **x, double **e) {

	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "|" << setw(15) << "x|" << setw(15) << "y|" << setw(15) << "yp|" << setw(15) << "e|" << setw(15) << "100 * e / yp|" << endl;
	//cout << "+--------------------------------------------------------------------------+" << endl;

	yp[0][0] = -1.0;
	yp[1][0] = 1.0;

	int m1 = (b - a) / h1;

	for (int i = 0; i < n; i++) {
		cout << "+--------------------------------------------------------------------------+" << endl;
		for (int j = 0; j <= m1; j++) {
			x[i][j] = a + j * h1;
			y[i][j] = f(x[i][j], i);
			k0[i][j] = h1 * fp(x[i][j], y[i][j], i);
			k1[i][j] = h1 * fp(x[i][j] + (1.0 / 6.0) * h1, y[i][j] + (1.0 / 6.0) * k0[i][j], i);
			k2[i][j] = h1 * fp(x[i][j] + (4.0 / 15.0) * h1, y[i][j] + (4.0 / 75.0) * k0[i][j] + (16.0 / 75.0) * k1[i][j], i);
			k3[i][j] = h1 * fp(x[i][j] + (2.0 / 3.0) * h1, y[i][j] + (5.0 / 6.0) * k0[i][j] - (3.0 / 8.0) * k1[i][j] + (5.0 / 2.0) * k2[i][j], i);
			k4[i][j] = h1 * fp(x[i][j] + (4.0 / 5.0) * h1, y[i][j] - (8.0 / 5.0) * k0[i][j] - (144.0 / 25.0) * k1[i][j] - 4.0 * k2[i][j] + (16.0 / 25.0) * k3[i][j], i);
			k5[i][j] = h1 * fp(x[i][j] + h1, y[i][j] + (361.0 / 320.0) * k0[i][j] - (18.0 / 5.0) * k1[i][j] + (407.0 / 128.0) * k2[i][j] - (11.0 / 80.0) * k3[i][j] + (55.0 / 128.0) * k4[i][j], i);
			if (j != m1)
				yp[i][j + 1] = yp[i][j] + (31.0 / 384.0) * k0[i][j] + (1125.0 / 2816.0) * k2[i][j] + (9.0 / 32.0) * k3[i][j] + (125.0 / 768.0) * k4[i][j] + (5.0 / 66.0) * k5[i][j];
			e[i][j] = abs(yp[i][j] - y[i][j]);

			cout << "|" << setw(14) << x[i][j] << "|" << setw(14) << y[i][j] << "|" << setw(14) << yp[i][j] << "|" << setw(14) << e[i][j] << "|" << setw(14) << abs(100.0 * e[i][j] / yp[i][j]) << "|" << endl;
		}
	}
	cout << "+--------------------------------------------------------------------------+" << endl;
}

void MethodRK4(double h1, double **x, double **e) {

	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "|" << setw(15) << "x|" << setw(15) << "y|" << setw(15) << "yp|" << setw(15) << "e|" << setw(15) << "100 * e / yp|" << endl;
	//cout << "+--------------------------------------------------------------------------+" << endl;
	
	yp[0][0] = -1.0;
	yp[1][0] = 1.0;

	int m1 = (b - a) / h1;

	for (int i = 0; i < n; i++) {
		cout << "+--------------------------------------------------------------------------+" << endl;
		for (int j = 0; j <= m1; j++) {
			x[i][j] = a + j * h1;
			y[i][j] = f(x[i][j], i);
			k1[i][j] = h1 * fp(x[i][j], y[i][j], i);
			k2[i][j] = h1 * fp(x[i][j] + h1 / 2.0, y[i][j] + k1[i][j] / 2.0, i);
			k3[i][j] = h1 * fp(x[i][j] + h1 / 2.0, y[i][j] + k2[i][j] / 2.0, i);
			k4[i][j] = h1 * fp(x[i][j] + h1, y[i][j] + k3[i][j], i);
			if (j != m1)
				yp[i][j + 1] = yp[i][j] + (1.0 / 6.0) * (k1[i][j] + 2.0 * k2[i][j] + 2.0 * k3[i][j] + k4[i][j], i);
			e[i][j] = abs(yp[i][j] - y[i][j]);

			cout << "|" << setw(14) << x[i][j] << "|" << setw(14) << y[i][j] << "|" << setw(14) << yp[i][j] << "|" << setw(14) << e[i][j] << "|" << setw(14) << abs(100.0 * e[i][j] / yp[i][j]) << "|" << endl;
		}
	}
	cout << "+--------------------------------------------------------------------------+" << endl;
}

//void Graphic() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glLineWidth(2);
//	glColor3f(1.0, 1.0, 1.0);
//	glBegin(GL_LINES);
//	glVertex2f(0, 0);
//	glVertex2f(WinWidth, 0);
//	glEnd();
//
//	glBegin(GL_LINES);
//	glVertex2f(0, WinHeight);
//	glVertex2f(0, 0);
//	glEnd();
//
//
//	glPointSize(3);
//	glBegin(GL_POINTS);
//	glColor3f(1, 0, 0);
//
//	for (int j = 0; j < (((b - a) / h) + 1); j++)
//		glVertex2f(0.07 * x[0][j], 0.07 * e[0][j]);
//
//	glPointSize(1);
//	glColor3f(0, 1, 0);
//
//	for (int j = 0; j < (((b - a) / (h / 5)) + 1); j++)
//		glVertex2f(x1[0][j], e1[0][j]);
//	
//	glColor3f(0, 0, 1);
//
//	for (int j = 0; j < (((b - a) / (h / 25)) + 1); j++)
//			glVertex2f(x2[0][j], e2[0][j]);
//
//	glEnd();
//
//	glutSwapBuffers();
//}