#include <locale.h>
#include <conio.h>
#include <iostream>
#include "Daily_balance.h"
#include <fstream>
#include <string>
#include <windows.h>
#include "exeption.hpp"

using namespace std;

//� ��� ������������ ���� ������� �� ������� �� � ����������
//������� ����������� ������������ �����(������� ������� ���� � ���������)  
void Average_Counts_Of_Dishes(DailyBalance &db) {
	float sum = 0;
	for (int i = 0; i < db.getSize(); i++)
		sum += db[i].getSize();
	sum /= db.getSize();
	cout << "������� �������� ���������� ���� � ������: " << sum << endl;
}

//������� ����������� ������������ �����(������� ������� ���������)  
void Average_Price(DailyBalance &db) {
	float sum = 0;
	for (int i = 0; i < db.getSize(); i++)
		for (int j = 0; j < db[i].getSize(); j++)
			sum += db[i][j].getPrice();
	sum /= db.getSize();
	cout << "������� �������� ��������� �������: " << sum << " ���." << endl;
}

//������� ������ �� �������� �� ��������� ����� 
void Find(DailyBalance &db) {
	int n;
	int num_tmp;
	char *str_tmp = new char[30];
	while (true) {
		cout << "\n\t1. ����� �� ��������� ����" << endl;
		cout << "\t2. ����� �� ���������� ����" << endl;
		cout << "\t3. ����� � ����" << endl;
		cout << "\n��� �����: ";
		rewind(stdin);
		cin.clear();
		cin >> n;
		switch (n) {
		case 1:
			cout << "\n ������� �����: ";
			cin >> num_tmp;
			for (int i = 0; i < db.getSize(); i++) {
				if (db[i].CompareNum(num_tmp) == true) {
					db[i].Show();
				}
			}
			break;
		case 2:
			cout << "\n ������� �����: ";
			cin >> str_tmp;
			for (int i = 0; i < db.getSize(); i++)
				db[i].CompareStr(str_tmp);
			break;
		case 3:
			return;
			break;
		default:
			cout << "\n������ ������ ��� � ����. ������� ��� ���." << endl;
			break;
		}
	}
	delete[] str_tmp;
}

template<typename T>//�������� ������� ������ �� ���������� ����� ������ �����
void Text_Write(T **arr, int n) {
	ofstream Ft("Text.txt");
	if (!Ft.is_open())
		throw Bad_File_Write_Exeption("������! ��������� ���� �� ��� ������ ��� ������!");
	else {
		for (int i = 0; i < n; i++)
			Ft << *arr[i] << endl;
		cout << "\n��������� ���� ������� ������!" << endl;
	}
	Ft.close();
}

template<typename T>//�������� ������� ���������� � ���������� ����� ������ ����� �� ������ ������� �����
void Text_Read(T **arr, int n) {
	ifstream Ft("Text.txt");
	if (!Ft.is_open())
		throw Bad_File_Read_Exeption("������! ��������� ���� �� ��� ������ ��� ����������!");
	else {
		for (int i = 0; i < n; i++) {
			Ft >> *arr[i];
			arr[i]->Show();
		}
		cout << "\n��������� ���� ������� ������!" << endl;
	}
	Ft.close();
}

template<typename T>//�������� ������� ������ �� �������� ����� ������ �����
void Binary_Write(T **arr, int n) {
	ofstream Fb("Binary.dat", ios::binary);
	if (!Fb.is_open())
		throw Bad_File_Write_Exeption("������! �������� ���� �� ��� ������ ��� ������!");
	else {
		for (int i = 0; i < n; i++)
			Fb.write((char*)&arr[i], sizeof(&arr[i]));
		cout << "\n�������� ���� ������� ������!" << endl;
	}
	Fb.close();
}

template<typename T>//�������� ������� ���������� � �������� ����� ������ ����� �� ������ ������� �����
void Binary_Read(T **arr, int n) {
	ifstream Fb("Binary.dat", ios::binary);
	if (!Fb.is_open())
		throw Bad_File_Read_Exeption("������! �������� ���� �� ��� ������ ��� ����������!");
	else {
		cout << "\n�������� ���� ������� ������!" << endl;
		for (int i = 0; i < n; i++) {
			Fb.read((char*)&arr[i], sizeof(T));
			arr[i]->Show();
		}
	}
	Fb.close();
}

void Menu() {
	int n = 0;
	DailyBalance db(10, 10);
	DailyBalance db1(10, 10);
	DailyBalance db2(10, 10);
	while (true){
		cout << "\n����" << endl;
		cout << "\t1. ������ ������" << endl;
		cout << "\t2. ������� ������ � �������" << endl;
		cout << "\t3. ������ ������ �� ����" << endl;
		cout << "\t4. ���������� ������" << endl;
		cout << "\t5. �����" << endl;
		cout << "\t6. �����" << endl;
		cout << "\n��� �����: ";
			cin >> n;
			switch (n){
				case 1:
					db.Set();
					break;
				case 2: 
					db.Show();
					Average_Counts_Of_Dishes(db);
					Average_Price(db);
					break;
				case 3:
					Binary_Write(db.getArr(), db.getSize());
					Text_Write(db.getArr(), db.getSize());
					break;
				case 4:
					Binary_Read(db1.getArr(), db1.getSize());
					Text_Read(db2.getArr(), db2.getSize());
					break;
				case 5:
					Find(db);
					break;
				case 6:
					exit(0);
					break;
				default:
					cout << "\n������ ������ ��� � ����. ������� ��� ���." << endl;
					break;
			}
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		Menu();
	}
	catch (MyException &ex) { //������������ ���� ���� �������� �� ����������(���������) �� ����������� �� �������� ������ ���������
		cout << ex.what();	  //������ ��� ���� ���������� ���� ��������
	}

	_getch();
	return 0;
}