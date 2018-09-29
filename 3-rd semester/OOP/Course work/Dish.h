#pragma once
#include "Type_of_dish.h"
#include <iostream>

using namespace std;

//масив назв страв за замовчуванням
char *d_nameOfDish[] = { "Бендерики", "Бифштекс", "Борщ", "Винегрет", "Гриль", "Драники", "Жаркое", "Жульен", "Запеканка", "Зразы", "Капустняк", "Кебаб", "Лагман", "Лазанья", "Лапша", "Мафины", "Налистники", "Оливье", "Паштет", "Харчо", "Хачапури", "Шаурма", "Шашлык", "Яичница" };

class Dish {/*(Назва, Ціна, Тип страви)*/
private:
	TypeOfDish type_of_dish;
	char *nameOfDish;
	int price;
public:
	//конструктор за замовчуванням
	Dish() : type_of_dish() {
		int i = rand() % 24;
		nameOfDish = new char[strlen(d_nameOfDish[i]) + 1];
		strcpy(nameOfDish, d_nameOfDish[i]);
		price = rand() % 10001;
	}
	//конструктор ініціалізації
	Dish(char *a_type, char *a_nameOfDish, int a_price) : type_of_dish(a_type){
		if (a_price < 0)
			throw Wrong_Argument_Exeption();
		this->nameOfDish = a_nameOfDish;
		this->price = a_price;
	}
	//конструктор копіювання
	Dish(const Dish &copy) : type_of_dish(copy.type_of_dish) {
		nameOfDish = new char[strlen(copy.nameOfDish) + 1];
		strcpy(nameOfDish, copy.nameOfDish);
		price = copy.price;
	}
	//перевантажений оператор виведення в потік
	friend ostream& operator << (ostream &os, const Dish &o_dish) {
		os << setw(15) << o_dish.type_of_dish;
		os << setw(15) << o_dish.nameOfDish;
		os << setw(15) << o_dish.price;
		return os;
	}
	//перевантажений оператор введення з потоку
	friend istream& operator >> (istream &is, Dish &o_dish) {
		is >> o_dish.type_of_dish;
		is >> o_dish.nameOfDish;
		is >> o_dish.price;
		return is;
	}

	void Set();//метод змінення полів
	void Show();//метод який виводить на консоль таблицю

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
//реалізація методу змінення полів
void Dish::Set() {
	int i;
	bool flg = true;
	nameOfDish = new char[30];
	cout << "  Введите название блюда: ";
	while (flg) {
		rewind(stdin);
		cin.clear();
		cin >> nameOfDish;
		for (i = 0; nameOfDish[i]; i++)
			if (nameOfDish[i] >= '!' && nameOfDish[i] <= '@' || nameOfDish[i] >= '[' && nameOfDish[i] <= '`' || nameOfDish[i] == '~' || nameOfDish[i] == ',' || nameOfDish[i] == ' ')
				break;
		if (nameOfDish[i])
			cout << "  Введены неверные символы! Введите название еще раз: ";
		else flg = false;
	}

	type_of_dish.Set();

	flg = true;
	cout << "  Введите цену блюда: ";
	while (flg) {
		cin.clear();
		rewind(stdin);
		cin >> price;
		if (!cin || price < 0 || price > 10000)
			cout << "  Неверное значение, введите снова: ";
		else flg = false;
	}
}
//реалізація виводу таблички на консоль
void Dish::Show() {
	cout << setw(11) << nameOfDish << "|";
	type_of_dish.Show();
	cout << setw(9) << price << "|" << endl;
}