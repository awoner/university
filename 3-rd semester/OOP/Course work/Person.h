#pragma once
#pragma warning(disable : 4996)

#include "Date.h"
#include <iostream>

using namespace std;

//масив імен за замовчуванням
char *d_names[] = { "Алексей", "Денис", "Юрий", "Иван", "Илья", "Андрей", "Богдан", "Владислав", "Анатолий", "Александр", "Максим", "Евгений", "Виктор", "Павел" };
//масив прізвищ за замовчуванням
char *d_surnames[] = { "Гарник", "Трухан", "Данько", "Засека", "Артамонов", "Мартыненко", "Скороход", "Юрченко", "Бочок", "Шматко", "Бевза", "Войтович", "Колотуша", "Ташу" };

class Person {/*(Прізвище, Ім’я, Дата (народження))*/
private:
	Date birthday_date;
	char *name,
		*surname;
public:
	//конструктор зазамовчуванням
	Person() : birthday_date() {	
		int i = rand() % 14;
		name = new char[strlen(d_names[i]) + 1];
		strcpy(name, d_names[i]);
		i = rand() % 14;
		surname = new char[strlen(d_surnames[i]) + 1];
		strcpy(surname, d_surnames[i]);
	}
	//конструктор ініціалізації
	Person(int a_day, int a_month, int a_year, char *a_name, char *a_surname) : birthday_date(a_day, a_month, a_year) {					//конструктор ініціалізації
		this->name = new char[strlen(a_name) + 1];
		strcpy(this->name, a_name);
		this->surname = new char[strlen(a_surname) + 1];
		strcpy(this->surname, a_surname);
	}
	//конструктор копіювання
	Person(const Person &copy) {	
		this->birthday_date = copy.birthday_date;
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		surname = new char[strlen(copy.surname) + 1];
		strcpy(surname, copy.surname);
	}
	//перевантажений оператор виведення в потік
	friend ostream& operator << (ostream &os, const Person &o_person) {
		os << setw(15) << o_person.name << endl;
		os << setw(15) << o_person.surname << endl;
		return os;
	}
	//перевантажений оператор введення з потоку
	friend istream& operator >> (istream &is, Person &o_person) {
		is >> o_person.name;
		is >> o_person.surname;
		return is;
	}

	virtual void Set();//метод змінення полів
	virtual void Show();//метод який виводить на консоль таблицю

	char *getName() {
		return name;
	}

	char* getSurname() {
		return surname;
	}

	Date getBDate() {
		return birthday_date;
	}
	//віртуальний деструктор
	virtual ~Person() {	
		if (name)
			delete[] name;
		if (surname)
			delete[] surname;
	}
};
//реалізація методу змінення полів
void Person::Set() {
		int i;
		bool flg = true;
		name = new char[30];
		cout << "  Введите имя: ";
		while (flg) {
			rewind(stdin);
			cin.clear();
			cin >> name;
			for (i = 0; name[i]; i++)
				if (name[i] >= '!' && name[i] <= '@' || name[i] >= '[' && name[i] <= '`' || name[i] == '~' || name[i] == ',' || name[i] == ' ')
					break;
			if (name[i])
				cout << "  Введены неверные символы! Введите имя еще раз: ";
			else flg = false;
		}
		flg = true;

		surname = new char[30];
		cout << "  Введите фамилию: ";
		while (flg) {
			rewind(stdin);
			cin.clear();
			cin >> surname;
			for (i = 0; surname[i]; i++)
				if (surname[i] >= '!' && surname[i] <= '@' || surname[i] >= '[' && surname[i] <= '`' || surname[i] == '~' || surname[i] == ',' || name[i] == ' ')
					break;
			if (surname[i])
				cout << "  Введены неверные символы! Введите фамилию еще раз: ";
			else flg = false;
		}
		cout << "  Введите дату рождения" << endl;
		birthday_date.Set();
}
//реалізація виводу таблички на консоль
void Person::Show() {
	cout << setw(10) << setfill(' ') << name << " ";
	cout << setw(10) << surname << "|";
	birthday_date.Show();
}