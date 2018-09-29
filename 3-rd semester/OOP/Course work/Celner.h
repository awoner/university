#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

//масив категорій кельнерів
char *d_category[] = { "Первая", "Вторая", "Третья", "Четвертая", "Пятая" };

class Celner : public Person {/*(Персона, Категорія)*/
private:
	char *category;
public:
	//конструктор за замовчуванням
	Celner() : Person() {		
		int i = rand() % 5;
		category = new char[strlen(d_category[i]) + 1];
		strcpy(category, d_category[i]);
	}
	//конструктор ініціалізації
	Celner(int a_day, int a_month, int a_year, char *a_name, char *a_surname, char *a_category) : Person(a_day, a_month, a_year, a_name, a_surname) {					//конструктор ініціалізації
		this->category = new char[strlen(a_category) + 1];
		strcpy(this->category, a_category);
	}
	//конструктор копіювання
	Celner(const Celner &copy) : Person(copy) {	
		category = new char[strlen(copy.category) + 1];
		strcpy(category, copy.category);
	}
	//перевантажений оператор виведення в потік
	friend ostream& operator << (ostream &os, Celner &o_celner) {
		os << o_celner.getName();
		os << o_celner.getSurname();
		os << o_celner.getBDate();
		os << o_celner.category;
		return os;
	}
	//перевантажений оператор введення з потоку
	friend istream& operator >> (istream &os, Celner &o_celner) {
		os >> o_celner.getName();
		os >> o_celner.getSurname();
		os >> o_celner.getBDate();
		os >> o_celner.category;
		return os;
	}

	void Set();//метод змінення полів
	void Show();//метод який виводить на консоль таблицю

	char * getCategory() {
		return category;
	}
	//деструктор
	~Celner() {
		if (category)
			delete[] category;
	}
};
//реалізація методу змінення полів
void Celner::Set() {						
	cout << " Введите данные о кельнере" << endl;
	Person::Set();
	int i;

	bool flg = true;

	category = new char[30];
	cout << "  Введите категорию кельнера: ";
	while (flg) {
		rewind(stdin);
		cin.clear();
		cin >> category;
		for (i = 0; category[i]; i++)
			if (category[i] >= '!' && category[i] <= '@' || category[i] >= '[' && category[i] <= '`' || category[i] == '~' || category[i] == ',')
				break;
		if (category[i])
			cout << " Введены неверные символы! Введите категорию еще раз: ";
		else flg = false;
	}
}
//реалізація виводу таблички на консоль
void Celner::Show() {
	Person::Show();
	cout << setw(14) << setfill(' ') << category << "|";
}