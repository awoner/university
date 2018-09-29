#pragma once
#pragma warning(disable : 4996)

#include "Date.h"
#include <iostream>

using namespace std;

//����� ���� �� �������������
char *d_names[] = { "�������", "�����", "����", "����", "����", "������", "������", "���������", "��������", "���������", "������", "�������", "������", "�����" };
//����� ������ �� �������������
char *d_surnames[] = { "������", "������", "������", "������", "���������", "����������", "��������", "�������", "�����", "������", "�����", "��������", "��������", "����" };

class Person {/*(�������, ���, ���� (����������))*/
private:
	Date birthday_date;
	char *name,
		*surname;
public:
	//����������� ���������������
	Person() : birthday_date() {	
		int i = rand() % 14;
		name = new char[strlen(d_names[i]) + 1];
		strcpy(name, d_names[i]);
		i = rand() % 14;
		surname = new char[strlen(d_surnames[i]) + 1];
		strcpy(surname, d_surnames[i]);
	}
	//����������� �����������
	Person(int a_day, int a_month, int a_year, char *a_name, char *a_surname) : birthday_date(a_day, a_month, a_year) {					//����������� �����������
		this->name = new char[strlen(a_name) + 1];
		strcpy(this->name, a_name);
		this->surname = new char[strlen(a_surname) + 1];
		strcpy(this->surname, a_surname);
	}
	//����������� ���������
	Person(const Person &copy) {	
		this->birthday_date = copy.birthday_date;
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		surname = new char[strlen(copy.surname) + 1];
		strcpy(surname, copy.surname);
	}
	//�������������� �������� ��������� � ����
	friend ostream& operator << (ostream &os, const Person &o_person) {
		os << setw(15) << o_person.name << endl;
		os << setw(15) << o_person.surname << endl;
		return os;
	}
	//�������������� �������� �������� � ������
	friend istream& operator >> (istream &is, Person &o_person) {
		is >> o_person.name;
		is >> o_person.surname;
		return is;
	}

	virtual void Set();//����� ������� ����
	virtual void Show();//����� ���� �������� �� ������� �������

	char *getName() {
		return name;
	}

	char* getSurname() {
		return surname;
	}

	Date getBDate() {
		return birthday_date;
	}
	//���������� ����������
	virtual ~Person() {	
		if (name)
			delete[] name;
		if (surname)
			delete[] surname;
	}
};
//��������� ������ ������� ����
void Person::Set() {
		int i;
		bool flg = true;
		name = new char[30];
		cout << "  ������� ���: ";
		while (flg) {
			rewind(stdin);
			cin.clear();
			cin >> name;
			for (i = 0; name[i]; i++)
				if (name[i] >= '!' && name[i] <= '@' || name[i] >= '[' && name[i] <= '`' || name[i] == '~' || name[i] == ',' || name[i] == ' ')
					break;
			if (name[i])
				cout << "  ������� �������� �������! ������� ��� ��� ���: ";
			else flg = false;
		}
		flg = true;

		surname = new char[30];
		cout << "  ������� �������: ";
		while (flg) {
			rewind(stdin);
			cin.clear();
			cin >> surname;
			for (i = 0; surname[i]; i++)
				if (surname[i] >= '!' && surname[i] <= '@' || surname[i] >= '[' && surname[i] <= '`' || surname[i] == '~' || surname[i] == ',' || name[i] == ' ')
					break;
			if (surname[i])
				cout << "  ������� �������� �������! ������� ������� ��� ���: ";
			else flg = false;
		}
		cout << "  ������� ���� ��������" << endl;
		birthday_date.Set();
}
//��������� ������ �������� �� �������
void Person::Show() {
	cout << setw(10) << setfill(' ') << name << " ";
	cout << setw(10) << surname << "|";
	birthday_date.Show();
}