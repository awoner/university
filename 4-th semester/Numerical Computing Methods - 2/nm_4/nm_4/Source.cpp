#include <iostream>
#include <fstream>
#include <iomanip>
#include <Gl/glut.h>

using namespace std;

int n = 51;
double R1 = 0,
R2 = 0.1,
g = 2500000,
Q = -60000,
Ta = 100,
T0 = 100,
k = 50,
alpha = 0.0002,
delta = (R2 - R1) / (n - 1),
dt = 0.005,
beta = 0.25,
t = 0,
e = pow(10, -8),
*delta_array, *Tn, *Tn1, *g1, *g2, *g3, *g4, *g5, *g6;

void display() {                    // Функция перерисовки дисплея
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, 600);   // Рисование системи координат
	glVertex2f(0, 0);
	glVertex2f(-0.05, 20);
	glVertex2f(0.1, 20);
	glEnd();

	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < n; i++) {
		glVertex2f(delta_array[i], g1[i]);   //location of points
	}
	glColor3f(1.0, 0.5, 0.31);
	for (int i = 0; i < n; i++) {
		glVertex2f(delta_array[i], g2[i]);   //location of points
	} 
	glColor3f(0.0, 1.0, 1.0);
	for (int i = 0; i < n; i++) {
		glVertex2f(delta_array[i], g3[i]);
	}
	glColor3f(1.0, 0.0, 1.0);
	for (int i = 0; i < n; i++) {
		glVertex2f(delta_array[i], g4[i]);   //location of points
	}			
	glColor3f(1.0, 0.5, 0.0);
	for (int i = 0; i < n; i++) {
		glVertex2f(delta_array[i], g5[i]);   //location of points
	}		
	glColor3f(0.0, 0.5, 0.0);
	for (int i = 0; i < n; i++) {
		glVertex2f(delta_array[i], g6[i]);   //location of points
	}
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	g1 = new double[n];
	g2 = new double[n];
	g3 = new double[n];
	g4 = new double[n];
	g5 = new double[n];
	g6 = new double[n];
	Tn = new double[n];
	Tn1 = new double[n];
	delta_array = new double[n];
	delta_array[0] = 0.0;
	for (int i = 1; i < n; i++)
	{
		delta_array[i] = delta_array[i - 1] + delta;
	}
	for (int i = 0; i < n; i++) Tn[i] = T0;

	while (t <= 100 + e) // max time
	{
		if (abs(t - 10)<e) {
			for (int i = 0; i < n; i++)
			{
				g1[i] = Tn[i];
				cout << g1[i] << " ";
			}
			cout << endl;
		}
		if (abs(t - 20)<e) {
			for (int i = 0; i < n; i++)
			{
				g2[i] = Tn[i];
				cout << g2[i] << " ";
			}
			cout << endl;
		}
		if (abs(t - 30)<e) {
			for (int i = 0; i < n; i++)
			{
				g3[i] = Tn[i];
				cout << g3[i] << " ";
			}
			cout << endl;
		}
		if (abs(t - 40)<e) {
			for (int i = 0; i < n; i++)
			{
				g4[i] = Tn[i];
				cout << g4[i] << " ";
			}
			cout << endl;
		}
		if (abs(t - 50)<e) {
			for (int i = 0; i < n; i++)
			{
				g5[i] = Tn[i];
				cout << g5[i] << " ";
			}
			cout << endl;
		}
		if (abs(t - 100)<e) {
			for (int i = 0; i < n; i++)
			{
				g6[i] = Tn[i];
				cout << g6[i] << " ";
			}
			cout << endl;
		}
		//Left boundary conditions
		Tn1[0] = Ta;

		for (int i = 1; i < n - 1; i++)
			Tn1[i] = Tn[i - 1] * beta + Tn[i] * (1 - 2 * beta) + Tn[i + 1] * beta + (g*pow(delta, 2)*beta / k);

		//Right boundary conditions
		Tn1[n - 1] = beta * Tn[n - 2] + (1 - 2 * beta) * Tn[n - 1] + beta * ((Q * 2 * delta) / k + Tn[n - 2]) + (g*pow(delta, 2)*beta / k);
		t += dt;
		for (int i = 0; i < n; i++) {
			Tn[i] = Tn1[i];
		}
	}
	// Стандартное создание окна в OpenGl
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(20, 110);
	glutCreateWindow("GraphicsLeha");
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.05, R2, 0, 600, -100, 100);
	glutDisplayFunc(display);
	glutMainLoop();
	getchar();
	return 0;
}