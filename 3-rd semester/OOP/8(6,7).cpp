//середнє геометричне для площ прямокутників вільних від еліпсів;
//=======================================================================
//різниця в часі виконання операції впорядкування за символьним полем
//наявного масиву об"єктів для випадку коли це поле о"єктів є динамічним
//масивом сиволів, що закинчується "\0" - символом, з випадком, коли теж 
//поле є об"ектом класу string стандартної бібліотеки;
//=======================================================================
//#include "stdafx.h"
#pragma warning(disable : 4996)
#define _USE_MATH_DEFINES
#include <cmath>  
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

namespace myexeption {
	class MyException {
		const char *message;
	public:
		MyException(const char *message = "Unknown exception!") : message(message) {}

		const char* what() const {
			return message;
		}
	};

	struct Wrong_Argument_Exeption : MyException {
		Wrong_Argument_Exeption(const char *message = "Wrong argument exception!") : MyException(message) {}
	};

	struct Out_Of_Range_Exception : MyException {
		Out_Of_Range_Exception(const char *message = "Out of range exception!") : MyException(message) {}
	};

	struct Bad_File_Exeption : MyException {
		Bad_File_Exeption(const char *message = "Bad file exception!") : MyException(message) {}
	};

	struct Bad_File_Write_Exeption : MyException {
		Bad_File_Write_Exeption(const char *message = "Bad file write exception!") : MyException(message) {}
	};

	struct Bad_File_Read_Exeption : MyException {
		Bad_File_Read_Exeption(const char *message = "Bad file read exception!") : MyException(message) {}
	};

	struct Invalid_File_Type_Exeption : MyException {
		Invalid_File_Type_Exeption(const char *message = "Invalid file type exception!") : MyException(message) {}
	};
}

class Figures abstract {
public:
	virtual void Set() = 0;
	virtual inline double Square() = 0;
	virtual void Text_Write(char*) = 0;
	virtual long int Text_Read(long int, char*) = 0;
	virtual ~Figures() {}
};

class Point {
private:
	double x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}

	Point(double x1, double y1) {
		x = x1;
		y = y1;
	}

	Point(const Point &p) {
		x = p.x;
		y = p.y;
	}

	void operator() (double x1, double y1) {
		x = x1;
		y = y1;
	}

	void Text_Write(char*path = "EllipseToRectangle(text).txt") {
		ofstream Text_output_file(path, ios::app);
		if (!Text_output_file.is_open())
			throw myexeption::Bad_File_Exeption();
		Text_output_file << x << " " << y << endl;
		Text_output_file.close();
	}

	long int Text_Read(long int pos = 0, char *path = "EllipseToRectangle(text).txt") {
		ifstream Text_input_file(path);
		Text_input_file.seekg(pos);
		if (!Text_input_file.is_open())
			throw myexeption::Bad_File_Exeption();
		double tmpX, tmpY;
		Text_input_file >> tmpX >> tmpY;
		if (Text_input_file.fail()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Write_Exeption();
		}
		if (Text_input_file.bad()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Write_Exeption();
		}
		x = tmpX;
		y = tmpY;
		long int p = Text_input_file.tellg();
		Text_input_file.close();
		return p;
	}

	friend ostream& operator<<(ostream& os, const Point& p) {
		os << p.x << endl;
		os << p.y << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Point& p) {
		is >> p.x;
		is >> p.y;
		return is;
	}

	void Set() {
		x = rand() % 100;
		y = rand() % 100;
	}

	void Get() {
		cout << "x: " << setw(5) << setprecision(3) << x << ", y: "
			<< setw(5) << setprecision(3) << y << (char)179;
	}

	double getX() { return x; }

	double getY() { return y; }
};

class Ellipse : virtual public Figures {
private:
	Point p;
	double r1, r2;
public:
	Ellipse() : p() {
		r1 = 1 + rand() % 30;
		r2 = 1 + rand() % (int)r1;
	}

	Ellipse(int R1, int R2) {
		r1 = R1 / 2.0;
		r2 = R2 / 2.0;
	}

	Ellipse(const Ellipse &e) {
		r1 = e.r1;
		r2 = e.r2;
	}

	void operator() (int R1, int R2, double x, double y) {
		p(x, y);
		r1 = R1;
		r2 = R2;
	}

	void Text_Write(char*path = "EllipseToRectangle(text).txt") {
		ofstream Text_output_file(path, ios::app);
		if (!Text_output_file.is_open())
			throw myexeption::Bad_File_Exeption();
		Text_output_file << r1 << " " << r2 << endl;
		Text_output_file.close();
	}

	long int Text_Read(long int pos = 0, char *path = "EllipseToRectangle(text).txt") {
		ifstream Text_input_file(path);
		Text_input_file.seekg(pos);
		if (!Text_input_file.is_open())
			throw myexeption::Bad_File_Exeption();
		double tmpR1, tmpR2;
		Text_input_file >> tmpR1 >> tmpR2;
		if (Text_input_file.fail()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Write_Exeption();
		}
		if (Text_input_file.bad()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Write_Exeption();
		}
		r1 = tmpR1;
		r2 = tmpR2;
		long int p = Text_input_file.tellg();
		Text_input_file.close();
		return p;
	}

	friend ostream& operator<<(ostream& os, const Ellipse& e) {
		os << e.r1 << endl;
		os << e.r2 << endl;
		os << e.p;
		return os;
	}

	friend istream& operator>>(istream& is, Ellipse& e) {
		is >> e.r1;
		is >> e.r2;
		is >> e.p;
		return is;
	}

	inline double Square() override { return M_PI * r1 * r2; }

	void Set() override {
		r1 = 1 + rand() % 30;
		r2 = 1 + rand() % (int)r1;
	}

	void Get() {
		cout << "r1: " << setw(5) << setprecision(3) << r1
			<< ", r2: " << setw(5) << r2 << (char)179;
		p.Get();
	}

	double getR1() { return r1; }

	double getR2() { return r2; }

	Point getPoint() { return p; }
};

class Rectangle : virtual public Figures {
private:
	Point p;
	int a, b;
public:
	Rectangle() : p() {
		a = 1 + rand() % 30;
		b = 1 + rand() % 30;
	}

	Rectangle(int a1, int b1) {
		if (a == b || a < 0 || b < 0)
			throw myexeption::Wrong_Argument_Exeption("Sides of rectangle shouldn't be equal or less than 0.");
		a = a1;
		b = b1;
	}

	Rectangle(const Rectangle &rec) {
		a = rec.a;
		b = rec.b;
	}

	void operator() (int A, int B, double x, double y) {
		p(x, y);
		a = A;
		b = B;
	}

	void Text_Write(char*path = "EllipseToRectangle(text).txt") {
		ofstream Text_output_file(path, ios::app);
		if (!Text_output_file.is_open())
			throw myexeption::Bad_File_Exeption();
		Text_output_file << a << " " << b << endl;
		Text_output_file.close();
	}

	long int Text_Read(long int pos = 0, char *path = "EllipseToRectangle(text).txt") {
		ifstream Text_input_file(path);
		Text_input_file.seekg(pos);
		if (!Text_input_file.is_open())
			throw myexeption::Bad_File_Exeption();
		int tmpA, tmpB;
		Text_input_file >> tmpA >> tmpB;
		if (Text_input_file.fail()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Write_Exeption();
		}
		if (Text_input_file.bad()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Write_Exeption();
		}
		a = tmpA;
		b = tmpB;
		long int p = Text_input_file.tellg();
		Text_input_file.close();
		return p;
	}

	friend ostream& operator<<(ostream& os, const Rectangle& r) {
		os << r.a << endl;
		os << r.b << endl;
		return os;
	}

	friend istream& operator>>(istream& is, Rectangle& r) {
		is >> r.a;
		is >> r.b;
		is >> r.p;
		return is;
	}

	inline double Square() override { return a * b; }

	void Set() override {
		a = 1 + rand() % 30;
		b = 1 + rand() % 30;
	}

	void Get() {
		cout << (char)179 << "a: " << setw(5) << setprecision(3) << a << ", b:" << setw(5) << b << (char)179;
	}

	int getA() { return a; }

	int getB() { return b; }

	Point getPoint() { return p; }
};

class EllipseToRectangle {
private:
	Ellipse e;				//еліпс
	Rectangle rec;			//прямокутник
	double free_rec;		//площа прямокутника вільна від еліпса	
	string s_descr;
	char *descr;
	char id;
public:
	static int Count;

	EllipseToRectangle() : rec() {
		e(rec.getA() / 2, rec.getB() / 2, 0, 0);

		free_rec = Free_rec();

		Count++;
		if (Count == 91)
			Count = 65;

		id = (char)abs(Count);
		s_descr = id;
		s_descr += "-Ellipse";
		descr = new char[s_descr.size() + 1];
		strcpy(descr, s_descr.c_str());
	}

	EllipseToRectangle(EllipseToRectangle &etr) : rec(etr.rec) {
		e(etr.getEllipse().getR1(), etr.getEllipse().getR2(), 0, 0);
		free_rec = etr.free_rec;
		s_descr = etr.s_descr;
		descr = new char[s_descr.size() + 1];
		for (int i = 0; i < 15; i++)
			descr[i] = etr.descr[i];
	}

	void Text_Write(char*path = "EllipseToRectangle(text).txt") {
		ofstream Text_output_file(path, ios::app);
		if (!Text_output_file.is_open())
			throw myexeption::Bad_File_Exeption();
		Text_output_file << e.getR1() << " " << e.getR2() << " " << e.getPoint().getX() << " "
			<< e.getPoint().getY() << " " << rec.getA() << " " << rec.getB() << " " << rec.getPoint().getX() << " " << rec.getPoint().getY() << " " << free_rec <<
			" " << descr << endl;
		Text_output_file.close();
	}

	long int Text_Read(long int pos = 0, char *path = "EllipseToRectangle(text).txt") {
		ifstream Text_input_file(path);
		Text_input_file.seekg(pos);
		if (!Text_input_file.is_open())
			throw myexeption::Bad_File_Exeption();
		double tmpR1, tmpR2, tmpEX, tmpEY, tmpA, tmpB, tmpRX, tmpRY, tmpFR;
		Text_input_file >> tmpR1 >> tmpR2 >> tmpEX >> tmpEY >> tmpA >> tmpB >> tmpRX >> tmpRY;
		(Text_input_file >> tmpFR).get();
		char *tmpDSCR = new char[s_descr.size() + 1];
		Text_input_file.getline(tmpDSCR, 10, '\n');
		if (Text_input_file.fail()) {
			delete[]tmpDSCR;
			Text_input_file.close();
			throw myexeption::Bad_File_Read_Exeption();
		}
		if (Text_input_file.bad()) {
			delete[]tmpDSCR;
			Text_input_file.close();
			throw myexeption::Bad_File_Read_Exeption();
		}
		strcpy(descr, tmpDSCR);
		e(tmpR1, tmpR2, tmpEX, tmpEY);
		rec(tmpA, tmpB, tmpRX, tmpRY);
		free_rec = tmpFR;
		delete[]tmpDSCR;
		long int p = Text_input_file.tellg();
		Text_input_file.close();
		return p;
	}

	friend ostream& operator<<(ostream& os, const EllipseToRectangle& etr) {
		os << etr.rec;
		os << etr.free_rec << endl;
		os << etr.s_descr << endl;
		os << etr.e;
		return os;
	}

	friend istream& operator>>(istream& is, EllipseToRectangle& etr) {
		is >> etr.rec;
		is >> etr.free_rec;
		is >> etr.s_descr;
		is >> etr.e;
		return is;
	}

	double Free_rec() { return rec.Square() - e.Square(); }

	void Get() {
		rec.Get();
		e.Get();
		cout << setw(15) << free_rec << (char)179;
		cout << setw(15) << s_descr << (char)179;
	}

	Rectangle getRectangle() { return rec; }

	double getFreeRec() { return free_rec; }

	char *getChar() { return descr; }

	Ellipse getEllipse() { return e; }

	string getString() { return s_descr; }

	~EllipseToRectangle() {
		if (descr)
			delete[] descr;
	}
};

int EllipseToRectangle::Count = 64;

template < typename T1>
void Stat(EllipseToRectangle **arr, T1 n) {
	//(SqrFreeRec 1 * SqrFreeRec 2 * SqrFreeRec 3 * ... * SqrFreeRec n)^(1/n) 
	double f;
	f = pow(arr[0]->getFreeRec(), (1.0 / n));
	for (int i = 1; i < n; i++)
		f *= pow(arr[i]->getFreeRec(), (1.0 / n));
	cout << "\nGeometric mean for squares of rectangles free of ellipses: " << f << endl;
}

void Char_Sort(EllipseToRectangle **etr, int n) {
	unsigned t = clock();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(etr[j]->getChar(), etr[j]->getChar()) < 0)
				swap(etr[i], etr[j]);
	cout << "Time of sort(char's): " << (clock() - t) / 10000.0 << endl;
}

void String_Sort(EllipseToRectangle **etr, int n) {
	unsigned t = clock();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (etr[i]->getString().compare(etr[j]->getString()) > 0)
				swap(etr[i], etr[j]);
	cout << "Time of sort(string's): " << ((float)(clock() - t)) / 10000.0 << endl;
}

void Number_Sort(EllipseToRectangle **etr, int n) {
	unsigned t = clock();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (etr[i]->getFreeRec() < etr[j]->getFreeRec())
				swap(etr[i], etr[j]);
	cout << "Time of sort(num's): " << ((float)(clock() - t)) / 10000.0 << endl;
}

bool My_Num_Comp(EllipseToRectangle *etr1, EllipseToRectangle *etr2) {
	return (etr1->getFreeRec() > etr2->getFreeRec());
}

bool My_Str_Comp(EllipseToRectangle *etr1, EllipseToRectangle *etr2) {
	return (etr1->getString().compare(etr2->getString()) < 0);
}

void Vec(EllipseToRectangle **etr, int n) {
	vector<EllipseToRectangle*> v;
	v.reserve(n);
	//cout << "Vector" << endl;
	for (int i = 0; i < n; i++) {
		v.push_back(etr[i]);
		//	cout << *v[i] << endl;
	}
	unsigned t1 = clock();
	sort(v.begin(), v.end(), My_Num_Comp);
	cout << "\nTime of STL sort(num's): " << ((float)(clock() - t1)) / 10000.0 << endl;
	/*for (int i = 0; i < n; i++)
	cout << *v[i] << endl;*/
	unsigned t2 = clock();
	sort(v.begin(), v.end(), My_Str_Comp);
	cout << "Time of STL sort(string's): " << ((float)(clock() - t2)) / 10000.0 << endl;
	/*for (int i = 0; i < n; i++)
	cout << *v[i] << endl;*/
	v.clear();
}

class ListOfEllipses {
private:
	EllipseToRectangle **etr;
	int num;
public:
	ListOfEllipses() {}
	ListOfEllipses(int n) {
		if (n < 0)
			throw myexeption::Wrong_Argument_Exeption();
		EllipseToRectangle::Count = 64;
		num = n;
		etr = new EllipseToRectangle*[num];
		for (int i = 0; i < num; i++)
			etr[i] = new EllipseToRectangle;
		Stat(etr, num);			//Geometric mean for squares of rectangles free of ellipses
		Char_Sort(etr, num);      //sort char's
		Number_Sort(etr, num);	//sort numbers
		String_Sort(etr, num);    //sort string's
		Vec(etr, num);
	}

	friend ostream& operator<<(ostream& os, ListOfEllipses& l) {
		for (int i = 0; i < l.getSize(); i++)
			os << *l[i];
		return os;
	}

	friend istream& operator>>(istream& is, ListOfEllipses& l) {
		for (int i = 0; i < l.getSize(); i++) {
			is >> *l[i];
		}
		return is;
	}

	void Get() {
		cout << (char)218;
		for (int i = 0; i < 89; i++)
			cout << (char)196;
		cout << (char)191 << endl;

		cout << (char)179 << setw(17) << "Rectangle" << (char)179 << setw(20) << "Ellipse" << (char)179 << setw(18) << "Center point" << (char)179;
		cout << setw(15) << "Free square" << (char)179 << setw(15) << "Description " << (char)179 << endl;

		cout << (char)195;
		for (int i = 0; i < 89; i++)
			cout << (char)196;
		cout << (char)180 << endl;

		for (int i = 0; i < num; i++) {
			etr[i]->Get();
			cout << endl;
		}
		cout << (char)192;

		for (int i = 0; i < 89; i++)
			cout << (char)196;
		cout << (char)217;
	}

	void Text_Write(char*path = "EllipseToRectangle(text).txt") {
		ofstream Text_output_file(path, ios_base::app);
		if (!Text_output_file.is_open())
			throw myexeption::Bad_File_Exeption();
		for (int i = 0; i < num; i++)
			etr[i]->Text_Write(path);
		Text_output_file.close();
	}

	long int Text_Read(long int pos = 0, char *path = "EllipseToRectangle(text).txt") {
		ifstream Text_input_file(path);
		Text_input_file.seekg(pos);
		if (!Text_input_file.is_open())
			throw myexeption::Bad_File_Exeption();
		if (Text_input_file.fail()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Read_Exeption();
		}
		if (Text_input_file.bad()) {
			Text_input_file.close();
			throw myexeption::Bad_File_Read_Exeption();
		}
		Text_input_file.get();
		long int p = Text_input_file.tellg();
		for (int i = 0; i < num; i++)
			p = etr[i]->Text_Read(p, path);
		Text_input_file.close();
		return p;
	}

	int getSize() { return num; }

	EllipseToRectangle **getArr() { return etr; }

	EllipseToRectangle* operator [](int index) {
		if (index < 0 || index >= num)
			throw myexeption::Out_Of_Range_Exception();
		return etr[index];
	}
};

void getEl(ListOfEllipses &l) {
	int n = 0;
	cout << "Enter the number of element information about which you would like to know: ";
	cin >> n;
	if (n < 0 || n >= l.getSize())
		throw myexeption::Out_Of_Range_Exception();

	for (int i = 0; i < 89; i++)
		cout << (char)196;

	cout << *l[n] << endl;

	for (int i = 0; i < 89; i++)
		cout << (char)196;
}

void Quest(ListOfEllipses &l) {
	bool flg = true;
	char answ1;
	do {
		cout << "\nDo you want to print all elements?" << endl << "Please enter Y(Yes) or N(No) >>>> ";
		cin >> answ1;
		switch (answ1) {
		case 'Y': case 'y':
			cout << "\n\nAll elements" << endl;
			l.Get();
			flg = false;
			break;
		case 'N': case 'n':
			flg = false;
			break;
		default:
			cout << "\nI dont know what is mean '" << answ1 << "'" << endl;
			break;
		}
	} while (flg == true);

	flg = true;
	char answ2;
	do {
		cout << "\nDo you want to get info about some element ?" << endl << "Please enter Y(Yes) or N(No) >>>> ";
		cin >> answ2;
		switch (answ2) {
		case 'Y': case 'y':
			getEl(l);
			break;
		case 'N': case 'n':
			cout << "\nOK." << endl;
			flg = false;
			break;
		default:
			cout << "\nI dont know what is mean '" << answ2 << "'" << endl;
			break;
		}
	} while (flg == true);
}

template<class T>
class InFile {
private:
	T **arr;
	int size_of_array;	
public:
	InFile(T **arg, int n) {
		size_of_array = n;
		arr = new T*[size_of_array];
		for (int i = 0; i < size_of_array; i++)
			arr[i] = new T(*arg[i]);
	}

	void Binary_Write(char *path = "EllipsesToRectangles(binary).dat") {
		ofstream Binary_output_file(path, ios::binary);
		if (!Binary_output_file.is_open())
			throw myexeption::Bad_File_Write_Exeption();
		for (int i = 0; i < size_of_array; i++)
			Binary_output_file.write((char*)&arr[i], sizeof(&arr[i]));
		Binary_output_file.close();
	}

	void Binary_Read(T **etr, int n, char *path = "EllipsesToRectangles(binary).dat") {
		ifstream Binary_input_file(path, ios::binary);
		if (!Binary_input_file.is_open())
			throw myexeption::Bad_File_Read_Exeption();
		else
			for (int i = 0; i < n; i++)
				Binary_input_file.read((char*)&etr[i], sizeof(T));
		cout << "File read out!" << endl;
		Binary_input_file.close();
	}

	void Text_Write(char *path = "EllipsesToRectangles(text).txt") {
		ofstream Text_output_file(path, ios::app);
		if (!Text_output_file.is_open())
			throw myexeption::Bad_File_Exeption();
		Text_output_file << typeid(T).hash_code() << endl;
		for (int i = 0; i < size_of_array; i++)
			arr[i]->Text_Write(path);
		Text_output_file.close();
	}

	void Text_Read(T **arg, int n, char *path = "EllipsesToRectangles(text).txt") {
		ifstream Text_input_file(path);
		if (!Text_input_file.is_open())
			throw myexeption::Bad_File_Exeption();
		size_t hash_of_type;
		Text_input_file >> hash_of_type;
		long int p = Text_input_file.tellg();
		for (int i = 0; i < n; i++) {
			Text_input_file.seekg(p);
			if (Text_input_file.fail()) {
				Text_input_file.close();
				throw myexeption::Bad_File_Read_Exeption();
			}
			if (Text_input_file.bad()) {
				Text_input_file.close();
				throw myexeption::Bad_File_Read_Exeption();
			}
			if (hash_of_type == typeid(T).hash_code())
				p = arg[i]->Text_Read(Text_input_file.tellg(), path);
		}
	}
};

int main(int argc, const char * argv[]) {
	srand(time(NULL));
	int count_of_ellipses = 0;
	try {
		cout << "Enter count of ellipses: ";
		cin >> count_of_ellipses;
		if (count_of_ellipses < 0)
			throw myexeption::MyException("Bad value! Count of ellipses don't be less than 0.");
		ListOfEllipses l(count_of_ellipses);

		InFile<EllipseToRectangle> f(l.getArr(), l.getSize());
		f.Text_Write();
		f.Binary_Write();

		ListOfEllipses binary_test(count_of_ellipses);
		ListOfEllipses text_test(count_of_ellipses);

		f.Binary_Read(binary_test.getArr(), binary_test.getSize());
		f.Text_Read(text_test.getArr(), text_test.getSize());

		Quest(l);
		Quest(binary_test);
		Quest(text_test);
	}
	catch (myexeption::MyException &ex) {
		cout << endl << ex.what() << endl;
	}
	catch (...) {
		throw myexeption::MyException();
	}
	_getch();
	return 0;
}