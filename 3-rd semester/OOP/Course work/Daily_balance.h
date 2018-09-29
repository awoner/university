#pragma once
#include "Order.h"
#include "exeption.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

class DailyBalance {/*(Список замовлень страв)*/
private:
	Order **ordList;
	int size;
public:
	//конструктор за замовчуванням
	DailyBalance() {
		size = 1 + rand() % 5;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order();
	}
	//конструктор за замовчуванням в якому є можливість задати кількість замовлень
	DailyBalance(int n) {
		if (n < 0)
			throw Wrong_Argument_Exeption();
		size = n;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order;
	}
	//конструктор за замовчуванням в якому є можливість задати кількість замовлень та страв у цих замовленнях
	DailyBalance(int n, int n1) {
		if (n < 0 || n1 < 0)
			throw Wrong_Argument_Exeption();
		size = n;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order(n1);
	}
	//конструктор ініціалізації
	DailyBalance(int count_of_orders, Dish **a_listOfDishes, int count_of_dishes, int year_of_order, int month_of_order, int day_of_order, int day_of_celner, int month_of_celner, int year_of_celner, char *celner_name, char *celner_surname, char *celner_category) {
		this->size = count_of_orders;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order(a_listOfDishes, count_of_dishes, year_of_order, month_of_order, day_of_order, day_of_celner, month_of_celner, year_of_celner, celner_name, celner_surname, celner_category);
	}
	//конструктор копіювання
	DailyBalance(const DailyBalance &copy) {
		size = copy.size;
		ordList = new Order*[size];
		for (int i = 0; i < size; i++)
			ordList[i] = new Order(*copy.ordList[i]);
	}
	//перевантажений оператор індексації
	Order &operator [](int index) {
		if (index < 0 || index >= size)
			throw Out_Of_Range_Exception("Ошибка! Обращение к несуществующему элементу массива.");
		else
			return *ordList[index];
	}
	//перевантажений оператор виведення в потік
	friend ostream& operator << (ostream &os, const DailyBalance &o_daily_balance) {
		for (int i = 0; i < o_daily_balance.size; i++)
			os << *o_daily_balance.ordList[i] << endl;
		return os;
	}
	//перевантажений оператор введення з потоку
	friend istream& operator >> (istream &is, DailyBalance &o_daily_balance) {
		for (int i = 0; i < o_daily_balance.size; i++)
			is >> *o_daily_balance.ordList[i];
		return is;
	}

	void Set();//метод змінення полів
	void Show();//метод який виводить на консоль таблицю

	Order **getArr() {
		return ordList;
	}

	int getSize() {
		return size;
	}
	//деструктор
	~DailyBalance() {
		for (int i = 0; i < size; i++)
			delete[] ordList[i];
	}
};
//реалізація методу змінення полів
void DailyBalance::Set() {
	cout << "Введите количество заказов: ";
	bool flg = true;
	while (flg) {
		cin.clear();
		rewind(stdin);
		cin >> size;
		if (!cin || size <= 0)
			cout << "Ошибка, введите снова: ";
		else flg = false;
	}

	for (int i = 0; i < size; i++) {
		cout << "\nЗаказ №" << i + 1 << endl;
		ordList[i]->Set();
	}
}
//реалізація виводу таблички на консоль
void DailyBalance::Show() {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(10) << "№ Заказа|" <<  setw(15) << "Дата заказа|" << setw(30) << "Кельнер" << setw(22) << "|";
	cout << setw(23) << "Блюда" << setw(19) << "|" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|" << setw(10) << "-|" << setw(15) << "-|" << setw(22) << "Имя Фамилия|" << setw(15) << "Дата рождения|" << setw(15) << "Категория|";
	cout << setw(10) << "№ Блюда|" << setw(12) << "Название|" << setw(10) << "Тип|" << setw(10) << "Цена(грн)|" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		cout << "|" << setw(9) << i + 1 << "|";
		ordList[i]->Show();
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	}
}