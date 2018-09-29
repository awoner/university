#pragma once
#include "Order.h"
#include "exeption.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

class DailyBalance {/*(������ ��������� �����)*/
private:
	Order **ordList;
	int size;
public:
	//����������� �� �������������
	DailyBalance() {
		size = 1 + rand() % 5;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order();
	}
	//����������� �� ������������� � ����� � ��������� ������ ������� ���������
	DailyBalance(int n) {
		if (n < 0)
			throw Wrong_Argument_Exeption();
		size = n;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order;
	}
	//����������� �� ������������� � ����� � ��������� ������ ������� ��������� �� ����� � ��� �����������
	DailyBalance(int n, int n1) {
		if (n < 0 || n1 < 0)
			throw Wrong_Argument_Exeption();
		size = n;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order(n1);
	}
	//����������� �����������
	DailyBalance(int count_of_orders, Dish **a_listOfDishes, int count_of_dishes, int year_of_order, int month_of_order, int day_of_order, int day_of_celner, int month_of_celner, int year_of_celner, char *celner_name, char *celner_surname, char *celner_category) {
		this->size = count_of_orders;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order(a_listOfDishes, count_of_dishes, year_of_order, month_of_order, day_of_order, day_of_celner, month_of_celner, year_of_celner, celner_name, celner_surname, celner_category);
	}
	//����������� ���������
	DailyBalance(const DailyBalance &copy) {
		size = copy.size;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order(*copy.ordList[i]);
	}
	//�������������� �������� ����������
	Order &operator [](int index) {
		if (index < 0 || index >= size)
			throw Out_Of_Range_Exception("������! ��������� � ��������������� �������� �������.");
		else
			return *ordList[index];
	}
	//�������������� �������� ��������� � ����
	friend ostream& operator << (ostream &os, const DailyBalance &o_daily_balance) {
		for (int i = 0; i < o_daily_balance.size; i++)
			os << *o_daily_balance.ordList[i] << endl;
		return os;
	}
	//�������������� �������� �������� � ������
	friend istream& operator >> (istream &is, DailyBalance &o_daily_balance) {
		for (int i = 0; i < o_daily_balance.size; i++)
			is >> *o_daily_balance.ordList[i];
		return is;
	}

	void Set();//����� ������� ����
	void Show();//����� ���� �������� �� ������� �������

	Order **getArr() {
		return ordList;
	}

	int getSize() {
		return size;
	}
	//����������
	~DailyBalance() {
		for (int i = 0; i < size; i++)
			delete[] ordList[i];
	}
};
//��������� ������ ������� ����
void DailyBalance::Set() {
	cout << "������� ���������� �������: ";
	bool flg = true;
	while (flg) {
		cin.clear();
		rewind(stdin);
		cin >> size;
		if (!cin || size <= 0)
			cout << "������, ������� �����: ";
		else flg = false;
	}

	for (int i = 0; i < size; i++) {
		cout << "\n����� �" << i + 1 << endl;
		ordList[i]->Set();
	}
}
//��������� ������ �������� �� �������
void DailyBalance::Show() {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(10) << "� ������|" <<  setw(15) << "���� ������|" << setw(30) << "�������" << setw(22) << "|";
	cout << setw(23) << "�����" << setw(19) << "|" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(10) << "-|" << setw(15) << "-|" << setw(22) << "��� �������|" << setw(15) << "���� ��������|" << setw(15) << "���������|";
	cout << setw(10) << "� �����|" << setw(12) << "��������|" << setw(10) << "���|" << setw(10) << "����(���)|" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		cout << "|" << setw(9) << i + 1 << "|";
		ordList[i]->Show();
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	}
}