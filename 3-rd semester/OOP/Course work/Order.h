#pragma once
#include "Celner.h"
#include "Dish.h"
#include "exeption.hpp"
#include <iostream>

using namespace std;

class Order : public Celner{/*(Список страв, Кельнер, Дата (замовлення))*/
private:
	Dish **listOfDishes;
	Date order_date;
	int size;
public:
	//конструктор за замовчуванням
	Order() : Celner(), order_date() {
		size = 1 + rand() % 5;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++) 
			listOfDishes[i] = new Dish;
	}
	//конструктор за замовчуванням в якому є можливість задати кількість страв
	Order(int n) : Celner(), order_date() {
		if (n < 0)
			throw Wrong_Argument_Exeption();
		size = n;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++)
			listOfDishes[i] = new Dish;
	}
	//конструктор ініціалізації
	Order(Dish **a_listOfDishes, int count_of_dishes, int year_of_order, int month_of_order, int day_of_order, int day_of_celner, int month_of_celner, int year_of_celner, char *celner_name, char *celner_surname, char *celner_category) :
		Celner(day_of_celner, month_of_celner, year_of_celner, celner_name, celner_surname, celner_category), order_date(year_of_order, month_of_order, day_of_order) {
		this->size = count_of_dishes;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++)
			listOfDishes[i] = new Dish(*a_listOfDishes[i]);
	}
	//конструктор копіювання
	Order(const Order &copy) {
		size = copy.size;
		listOfDishes = new Dish*[size];
		for (int i = 0; i < size; i++)
			listOfDishes[i] = new Dish(*copy.listOfDishes[i]);
	}
	//перевантажений оператор індексації
	Dish &operator [](int index) {
		if (index < 0 || index >= size)
			throw Out_Of_Range_Exception("Ошибка! Обращение к несуществующему элементу массива.");
		else
			return *listOfDishes[index];
	}
	//перевантажений оператор виведення в потік
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
	//перевантажений оператор введення з потоку
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

	void Set();//метод змінення полів
	void Show();//метод який виводить на консоль таблицю
	bool CompareNum(int);//метод порівнювання чисел який створений для пошуку по числовому полю
	void CompareStr(char*);//метод порівнювання символьних полів який створений для пошуку по символьному полю

	Dish **getArr() {
		return listOfDishes;
	}

	int getSize() {
		return size;
	}
	//деструктор
	~Order() {
		for (int i = 0; i < size; i++)
			delete[] listOfDishes[i];
	}
};
//реалізація методу змінення полів
void Order::Set() {
	Celner::Set();
	cout << " Введите дату заказа" << endl;
	order_date.Set();
	cout << " Введите количество блюд: ";
	bool flg = true;
	while (flg) {
		cin.clear();
		rewind(stdin);
		cin >> size;
		if (!cin || size <= 0)
			cout << " Ошибка, введите снова: ";
		else flg = false;
	}

	for (int i = 0; i < size; i++) {
		cout << "\n Блюдо №" << i + 1 << endl;
		listOfDishes[i]->Set();
	}
}
//реалізація виводу таблички на консоль
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
//реалізація методу порівнювання чисел
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
//реалізація методу порівнювання символьних полів
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