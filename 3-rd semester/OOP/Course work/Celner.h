#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

//����� �������� ��������
char *d_category[] = { "������", "������", "������", "���������", "�����" };

class Celner : public Person {/*(�������, ��������)*/
private:
	char *category;
public:
	//����������� �� �������������
	Celner() : Person() {		
		int i = rand() % 5;
		category = new char[strlen(d_category[i]) + 1];
		strcpy(category, d_category[i]);
	}
	//����������� �����������
	Celner(int a_day, int a_month, int a_year, char *a_name, char *a_surname, char *a_category) : Person(a_day, a_month, a_year, a_name, a_surname) {					//����������� �����������
		this->category = new char[strlen(a_category) + 1];
		strcpy(this->category, a_category);
	}
	//����������� ���������
	Celner(const Celner &copy) : Person(copy) {	
		category = new char[strlen(copy.category) + 1];
		strcpy(category, copy.category);
	}
	//�������������� �������� ��������� � ����
	friend ostream& operator << (ostream &os, Celner &o_celner) {
		os << o_celner.getName();
		os << o_celner.getSurname();
		os << o_celner.getBDate();
		os << o_celner.category;
		return os;
	}
	//�������������� �������� �������� � ������
	friend istream& operator >> (istream &os, Celner &o_celner) {
		os >> o_celner.getName();
		os >> o_celner.getSurname();
		os >> o_celner.getBDate();
		os >> o_celner.category;
		return os;
	}

	void Set();//����� ������� ����
	void Show();//����� ���� �������� �� ������� �������

	char * getCategory() {
		return category;
	}
	//����������
	~Celner() {
		if (category)
			delete[] category;
	}
};
//��������� ������ ������� ����
void Celner::Set() {						
	cout << " ������� ������ � ��������" << endl;
	Person::Set();
	int i;

	bool flg = true;

	category = new char[30];
	cout << "  ������� ��������� ��������: ";
	while (flg) {
		rewind(stdin);
		cin.clear();
		cin >> category;
		for (i = 0; category[i]; i++)
			if (category[i] >= '!' && category[i] <= '@' || category[i] >= '[' && category[i] <= '`' || category[i] == '~' || category[i] == ',')
				break;
		if (category[i])
			cout << " ������� �������� �������! ������� ��������� ��� ���: ";
		else flg = false;
	}
}
//��������� ������ �������� �� �������
void Celner::Show() {
	Person::Show();
	cout << setw(14) << setfill(' ') << category << "|";
}