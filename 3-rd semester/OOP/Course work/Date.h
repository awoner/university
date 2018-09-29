#pragma once
#include <iostream>
#include <iomanip>
#include "exeption.hpp"

using namespace std;

class Date {/*(г�, ̳����, ����)*/
private:
	int day,
		month,
		year;
public:
	//����������� �� �������������
	Date() {	
		day = 1 + rand() % 31;
		month = 1 + rand() % 12;
		year = 1980 + rand() % (2017 - 1980);
	}
	//����������� �����������
	Date(int a_day, int a_month, int a_year) {
		if (day < 0 || day > 31 || month < 0 || month > 12 || year > 2017 || year < 1980)
			throw Wrong_Argument_Exeption();
		this->day = a_day;
		this->month = a_month;
		this->year = a_year;
	}
	//����������� ���������
	Date(const Date &copy) {		
		day = copy.day;
		month = copy.month;
		year = copy.year;
	}
	//�������������� �������� ��������� � ����
	friend ostream& operator << (ostream &os, const Date &o_date) {
		os << setw(10) <<  o_date.day;
		os << setw(3) << o_date.month;
		os << setw(5) <<  o_date.year;
		return os;
	}
	//�������������� �������� �������� � ������
	friend istream& operator >> (istream &is, Date &o_date) {
		is >> o_date.day;
		is >> o_date.month;
		is >> o_date.year;
		return is;
	}

	void Set();	//����� ������� ����			
	void Show();//����� ���� �������� �� ������� �������

	int getDay() {
		return day;
	}

	int getMonth() {
		return month;
	}

	int getYear() {
		return year;
	}
	//����������
	~Date() {}				
};
//��������� ������ ������� ����
void Date::Set() {					
	bool flag = true;

	cout << "   ������� ���: ";
	while (flag) {
		cin.clear();
		rewind(stdin);
		cin >> year;
		if (!cin || year < 1980 || year > 2017 )
			cout << "   �������� ��������, ������� �����: ";
		else  flag = false; 
		}

	flag = true;
	
	cout << "   ������� �����: ";
	while (flag) {
		cin.clear();
		rewind(stdin);
		cin >> month;
		if (!cin || month < 1 || month > 12 || !cin.good())
			cout << "   �������� ��������, ����� ������ ���� �� 1 �� 12: ";
		else  flag = false;
	}
	
	flag = true;
	
	cout << "   ������� ����: ";
	if (month == 2 && year % 4 == 0) {
		while (flag) {
			cin.clear();
			rewind(stdin);
			cin >> day;
			if (!cin || day < 1 || day > 29)
				cout << "   �������� ��������, � ���� ������ 29 ����: ";
			else  flag = false;
		}
	}
	else if (month == 2 && year % 2 == 1) {
		while (flag) {
			cin.clear();
			rewind(stdin);
			cin >> day;
			if (!cin || day < 1 || day > 28)
				cout << "   �������� ��������, � ���� ������ 28 ����: ";
			else  flag = false; 
		}
	}
	if (month % 2 == 0 && month != 2) {
		while (flag) {
			cin.clear();
			rewind(stdin);
			cin >> day;
			if (!cin || day < 1 || day > 30)
				cout << "   �������� ��������, � ���� ������ 30 ����: ";
			else  flag = false;
		}
	}
	else {
		while (flag) {
			cin.clear();
			rewind(stdin);
			cin >> day;
			if (!cin || day < 1 || day > 31) {
				cout << "   �������� ��������, � ������ 30 ����: ";
			}
			else  flag = false; 
		}
	}
}
//��������� ������ �������� �� �������
void Date::Show() {
	cout << "    " << setw(2) << setfill('0') << day << "." << setw(2) << setfill('0') << month << "." << setw(4) << year << "|";
}