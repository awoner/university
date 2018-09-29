// ConsoleApplication49.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include<conio.h>
#include<time.h>
#include <iomanip>
#include <math.h>
using namespace std;

POINT op;
HWND hWnd;
HDC hDC;
const double pi = 3.14159265;

void Clear() {
	system("cls");
	InvalidateRgn(hWnd, 0, 0);
}
void DrawLine(int a, int b, int c, int ox, int oy, COLORREF color) {
	SelectObject(hDC, CreatePen(PS_SOLID, 1, color));

	double x = ox;
	double y = oy;
	MoveToEx(hDC, x, y, &op);
	double pi = 3.1415926;
	x = a*cos(2 * pi / b*c - pi / 2) + ox;
	y = a*sin(2 * pi / b*c - pi / 2) + oy;

	LineTo(hDC, x, y);
}



int _tmain(int argc, _TCHAR* argv[])
{
	hWnd = GetConsoleWindow();
	hDC = GetDC(hWnd);
	SelectObject(hDC, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
	int o1 = 800, o2 = 150;
	int ox = 320, oy = 200;
	double x, y, r;

	do {
		while (!_kbhit()) {
			Clear();

			time_t t1 = time(0);
			tm time;
			localtime_s(&time, &t1);
			cout << time.tm_hour << ":" << time.tm_min << ":" << time.tm_sec << endl;
			SelectObject(hDC, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
			int a = 100;
			double t = 0.0;
			x = a*cos(0) + o1;
			y = a*sin(0) + o2;
			for (int i = 0; i < 700; i++, t += 0.01) {
				MoveToEx(hDC, x, y, &op);
				x = a*cos(t) + o1;
				y = a*sin(t) + o2;
				LineTo(hDC, x, y);
			}

			DrawLine(40, 12, time.tm_hour, o1, o2, RGB(255, 255, 0));
			DrawLine(60, 60, time.tm_min, o1, o2, RGB(255, 0, 255));
			DrawLine(90, 60, time.tm_sec, o1, o2, RGB(0, 255, 255));

			SelectObject(hDC, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
			MoveToEx(hDC, 320, 20, &op);
			LineTo(hDC, 310, 40);
			MoveToEx(hDC, 320, 20, &op);
			LineTo(hDC, 330, 40);
			MoveToEx(hDC, 320, 20, &op);
			LineTo(hDC, 320, 380);


			MoveToEx(hDC, 20, 200, &op);
			LineTo(hDC, 620, 200);
			MoveToEx(hDC, 620, 200, &op);
			LineTo(hDC, 600, 190);
			MoveToEx(hDC, 620, 200, &op);
			LineTo(hDC, 600, 210);


			SelectObject(hDC, CreatePen(PS_SOLID, 1, RGB(255, 255, 255)));
			int c = 10000;
			double d = 0.01;
			r = sqrt(2 * c*cos(0));
			x = r*cos(0) + ox;
			y = r*sin(0) + oy;
			for (int i = 0; i <1500; i++, d += 0.01) {
				r = sqrt(2 * c*cos(2 * d));
				MoveToEx(hDC, x, y, &op);
				x = r * cos(d) + ox;
				y = r * sin(d) + oy;
				LineTo(hDC, x, y);
			}
		}
	} while (_getch() == 13);

	cout << "Press any key to exit";
	_getch();
	return 0;
}

