#pragma once
#include <iostream>

char *d_type[] = { "Первое", "Второе", "Десерт" };

using namespace std;

class TypeOfDish {/*(перша, друга, десерт)*/
private:
	char *type;
public:
	//конструктор за замовчуванням
	TypeOfDish() {			
		int i = rand() % 3;
		type = new char[strlen(d_type[i]) + 1];
		strcpy(type, d_type[i]);
	}
	//конструктор ініціалізації
	TypeOfDish(char *a_type)  {	
		this->type = new char[strlen(a_type) + 1];
		strcpy(this->type, a_type);
	}
	//конструктор копіювання
	TypeOfDish(const TypeOfDish &copy) {
		type = copy.type;
	}
	//перевантажений оператор виведення в потік
	friend ostream& operator << (ostream &os, const TypeOfDish &o_type_of_dish) {
		os << setw(15) << o_type_of_dish.type;
		return os;
	}
	//перевантажений оператор введення з потоку
	friend istream& operator >> (istream &is, TypeOfDish &o_type_of_dish) {
		is >> o_type_of_dish.type;
		return is;
	}

	void Set();//метод змінення полів
	void Show();//метод який виводить на консоль таблицю

	char *getType() {
		return type;
	}
	//деструктор
	~TypeOfDish() {
		if (type)
			delete[] type;
	}
};
//реалізація методу змінення полів
void TypeOfDish::Set() {
	bool flg = true;								
	type = new char[10];
	cout << "   Выберите тип блюда" << endl;
	cout << "\n    1. Первое"<< endl;
	cout << "\n    2. Второе" << endl;
	cout << "\n    3. Десерт" << endl;
	int a;
	cout << "\n   Ваш выбор: ";
	while (flg == true) {
		rewind(stdin);
		cin.clear();
		cin >> a;
		switch (a) {
		case 1:
			type = d_type[0];
			flg = false;
			break;
		case 2:
			type = d_type[1];
			flg = false;
			break;
		case 3:
			type = d_type[2];
			flg = false;
			break;
		default:
			cout << "Такого типа блюда нету. Введите еще раз." << endl;
		}
	}
}
//реалізація виводу таблички на консоль
void TypeOfDish::Show() {
	cout << setw(9) << type << "|";
}