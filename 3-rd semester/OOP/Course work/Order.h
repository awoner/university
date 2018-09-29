#pragma once
#include "Celner.h"
#include "Dish.h"
#include "exeption.hpp"
#include <iostream>

using namespace std;

class Order : public Celner{/*(������ �����, �������, ���� (����������))*/
private:
	Dish **listOfDishes;
	Date order_date;
	int size;
public:
	//����������� �� �������������
	Order() : Celner(), order_date() {
		size = 1 + rand() % 5;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++) 
			listOfDishes[i] = new Dish;
	}
	//����������� �� ������������� � ����� � ��������� ������ ������� �����
	Order(int n) : Celner(), order_date() {
		if (n < 0)
			throw Wrong_Argument_Exeption();
		size = n;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++)
			listOfDishes[i] = new Dish;
	}
	//����������� �����������
	Order(Dish **a_listOfDishes, int count_of_dishes, int year_of_order, int month_of_order, int day_of_order, int day_of_celner, int month_of_celner, int year_of_celner, char *celner_name, char *celner_surname, char *celner_category) :
		Celner(day_of_celner, month_of_celner, year_of_celner, celner_name, celner_surname, celner_category), order_date(year_of_order, month_of_order, day_of_order) {
		this->size = count_of_dishes;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++)
			listOfDishes[i] = new Dish(*a_listOfDishes[i]);
	}
	//����������� ���������
	Order(const Order &copy) {
		size = copy.size;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++)
			listOfDishes[i] = new Dish(*copy.listOfDishes[i]);
	}
	//�������������� �������� ����������
	Dish &operator [](int index) {
		if (index < 0 || index >= size)
			throw Out_Of_Range_Exception("������! ��������� � ��������������� �������� �������.");
		else
			return *listOfDishes[index];
	}
	//�������������� �������� ��������� � ����
	friend ostream& operator << (ostream &os, Order &o_order) {
		os << setw(15) << o_order.order_date;
		os << setw(15) << o_order.getName();
		os << setw(15) << o_order.getSurname();
		os << o_order.getBDate();
		os << setw(15) << o_order.getCategory();
		for (int i = 0; i < o_order.size; i++)
			os << *o_order.listOfDishes[i] << endl;
		return os;
	}
	//�������������� �������� �������� � ������
	friend istream& operator >> (istream &is, Order &o_order) {
		is >> o_order.order_date;
		is >> o_order.getName();
		is >> o_order.getSurname();
		is >> o_order.getCategory();
		is >> o_order.getCategory();
		for (int i = 0; i < o_order.size; i++)
			is >> *o_order.listOfDishes[i];
		return is;
	}

	void Set();//����� ������� ����
	void Show();//����� ���� �������� �� ������� �������
	bool CompareNum(int);//����� ����������� ����� ���� ��������� ��� ������ �� ��������� ����
	void CompareStr(char*);//����� ����������� ���������� ���� ���� ��������� ��� ������ �� ����������� ����

	Dish **getArr() {
		return listOfDishes;
	}

	int getSize() {
		return size;
	}
	//����������
	~Order() {
		for (int i = 0; i < size; i++)
			delete[] listOfDishes[i];
	}
};
//��������� ������ ������� ����
void Order::Set() {
	Celner::Set();
	cout << " ������� ���� ������" << endl;
	order_date.Set();
	cout << " ������� ���������� ����: ";
	bool flg = true;
	while (flg) {
		cin.clear();
		rewind(stdin);
		cin >> size;
		if (!cin || size <= 0)
			cout << " ������, ������� �����: ";
		else flg = false;
	}

	for (int i = 0; i < size; i++) {
		cout << "\n ����� �" << i + 1 << endl;
		listOfDishes[i]->Set();
	}
}
//��������� ������ �������� �� �������
void Order::Show() {
	order_date.Show();
	Celner::Show();
	for (int i = 0; i < size; i++) {
		if (i > 0) 
			cout << "|" << setw(86) << i + 1 << "|";
		else 
			cout << setw(9) << i + 1 << "|"; 
		listOfDishes[i]->Show();
	}
}
//��������� ������ ����������� �����
bool Order::CompareNum(int tmp) {
	if (tmp == order_date.getDay() || tmp == order_date.getMonth() || tmp == order_date.getYear()) {
		return true;
	}
	if (tmp == Celner::getBDate().getDay() || tmp == Celner::getBDate().getMonth() || tmp == Celner::getBDate().getYear()) {
		Celner::Show();
	}
	for (int i = 0; i < size; i++){
		if (tmp == listOfDishes[i]->getPrice()) {
			listOfDishes[i]->Show();
		}
	}
}
//��������� ������ ����������� ���������� ����
void Order::CompareStr(char* tmp) {
	if (strcmp(tmp, Celner::getName()) == 0 || strcmp(tmp, Celner::getSurname()) == 0 || strcmp(tmp, Celner::getCategory()) == 0) {
		Celner::Show();
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		if (strcmp(tmp, listOfDishes[i]->getNameOfDish()) == 0 || strcmp(tmp, listOfDishes[i]->getTypeOfDish()) == 0)
			listOfDishes[i]->Show();
	}
}