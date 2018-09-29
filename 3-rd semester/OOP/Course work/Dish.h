#pragma once
#include "Type_of_dish.h"
#include <iostream>

using namespace std;

//����� ���� ����� �� �������������
char *d_nameOfDish[] = { "���������", "��������", "����", "��������", "�����", "�������", "������", "������", "���������", "�����", "���������", "�����", "������", "�������", "�����", "������", "����������", "������", "������", "�����", "��������", "������", "������", "�������" };

class Dish {/*(�����, ֳ��, ��� ������)*/
private:
	TypeOfDish type_of_dish;
	char *nameOfDish;
	int price;
public:
	//����������� �� �������������
	Dish() : type_of_dish() {
		int i = rand() % 24;
		nameOfDish = new char[strlen(d_nameOfDish[i]) + 1];
		strcpy(nameOfDish, d_nameOfDish[i]);
		price = rand() % 10001;
	}
	//����������� �����������
	Dish(char *a_type, char *a_nameOfDish, int a_price) : type_of_dish(a_type){
		if (a_price < 0)
			throw Wrong_Argument_Exeption();
		this->nameOfDish = a_nameOfDish;
		this->price = a_price;
	}
	//����������� ���������
	Dish(const Dish &copy) : type_of_dish(copy.type_of_dish) {
		nameOfDish = new char[strlen(copy.nameOfDish) + 1];
		strcpy(nameOfDish, copy.nameOfDish);
		price = copy.price;
	}
	//�������������� �������� ��������� � ����
	friend ostream& operator << (ostream &os, const Dish &o_dish) {
		os << setw(15) << o_dish.type_of_dish;
		os << setw(15) << o_dish.nameOfDish;
		os << setw(15) << o_dish.price;
		return os;
	}
	//�������������� �������� �������� � ������
	friend istream& operator >> (istream &is, Dish &o_dish) {
		is >> o_dish.type_of_dish;
		is >> o_dish.nameOfDish;
		is >> o_dish.price;
		return is;
	}

	void Set();//����� ������� ����
	void Show();//����� ���� �������� �� ������� �������

	int getPrice() {
		return price;
	}

	char *getNameOfDish() {
		return nameOfDish;
	}

	char *getTypeOfDish() {
		return type_of_dish.getType();
	}

	~Dish() {
		if (nameOfDish)
			delete[] nameOfDish;
	}
};
//��������� ������ ������� ����
void Dish::Set() {
	int i;
	bool flg = true;
	nameOfDish = new char[30];
	cout << "  ������� �������� �����: ";
	while (flg) {
		rewind(stdin);
		cin.clear();
		cin >> nameOfDish;
		for (i = 0; nameOfDish[i]; i++)
			if (nameOfDish[i] >= '!' && nameOfDish[i] <= '@' || nameOfDish[i] >= '[' && nameOfDish[i] <= '`' || nameOfDish[i] == '~' || nameOfDish[i] == ',' || nameOfDish[i] == ' ')
				break;
		if (nameOfDish[i])
			cout << "  ������� �������� �������! ������� �������� ��� ���: ";
		else flg = false;
	}

	type_of_dish.Set();

	flg = true;
	cout << "  ������� ���� �����: ";
	while (flg) {
		cin.clear();
		rewind(stdin);
		cin >> price;
		if (!cin || price < 0 || price > 10000)
			cout << "  �������� ��������, ������� �����: ";
		else flg = false;
	}
}
//��������� ������ �������� �� �������
void Dish::Show() {
	cout << setw(11) << nameOfDish << "|";
	type_of_dish.Show();
	cout << setw(9) << price << "|" << endl;
}