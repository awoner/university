#include <locale.h>
#include <conio.h>
#include <iostream>
#include "Daily_balance.h"
#include <fstream>
#include <string>
#include <windows.h>
#include "exeption.hpp"

using namespace std;

//у звіті обгрунтовано чому наступні дві функції не є шаблонними
//функція знаходження статистичних даних(середня кількість став у замовленні)  
void Average_Counts_Of_Dishes(DailyBalance &db) {
	float sum = 0;
	for (int i = 0; i < db.getSize(); i++)
		sum += db[i].getSize();
	sum /= db.getSize();
	cout << "Среднее значение количества блюд в заказе: " << sum << endl;
}

//функція знаходження статистичних даних(середня вартість замовлень)  
void Average_Price(DailyBalance &db) {
	float sum = 0;
	for (int i = 0; i < db.getSize(); i++)
		for (int j = 0; j < db[i].getSize(); j++)
			sum += db[i][j].getPrice();
	sum /= db.getSize();
	cout << "Среднее значение стоимости заказов: " << sum << " грн." << endl;
}

//функція пошуку за числовим та текстовим полем 
void Find(DailyBalance &db) {
	int n;
	int num_tmp;
	char *str_tmp = new char[30];
	while (true) {
		cout << "\n\t1. Поиск по числовому полю" << endl;
		cout << "\t2. Поиск по строковому полю" << endl;
		cout << "\t3. Выход в меню" << endl;
		cout << "\nВаш выбор: ";
		rewind(stdin);
		cin.clear();
		cin >> n;
		switch (n) {
		case 1:
			cout << "\n Введите число: ";
			cin >> num_tmp;
			for (int i = 0; i < db.getSize(); i++) {
				if (db[i].CompareNum(num_tmp) == true) {
					db[i].Show();
				}
			}
			break;
		case 2:
			cout << "\n Введите слово: ";
			cin >> str_tmp;
			for (int i = 0; i < db.getSize(); i++)
				db[i].CompareStr(str_tmp);
			break;
		case 3:
			return;
			break;
		default:
			cout << "\nТакого пункта нет в меню. Введите еще раз." << endl;
			break;
		}
	}
	delete[] str_tmp;
}

template<typename T>//шаблонна функція запису до текстового файлу масиву обєктів
void Text_Write(T **arr, int n) {
	ofstream Ft("Text.txt");
	if (!Ft.is_open())
		throw Bad_File_Write_Exeption("Ошибка! Текстовый файл не был открыт для записи!");
	else {
		for (int i = 0; i < n; i++)
			Ft << *arr[i] << endl;
		cout << "\nТекстовый файл успешно создан!" << endl;
	}
	Ft.close();
}

template<typename T>//шаблонна функція зчитування з текстового файлу масиву обєктів до іншого массиву обєктів
void Text_Read(T **arr, int n) {
	ifstream Ft("Text.txt");
	if (!Ft.is_open())
		throw Bad_File_Read_Exeption("Ошибка! Текстовый файл не был открыт для считывания!");
	else {
		for (int i = 0; i < n; i++) {
			Ft >> *arr[i];
			arr[i]->Show();
		}
		cout << "\nТекстовый файл успешно считан!" << endl;
	}
	Ft.close();
}

template<typename T>//шаблонна функція запису до бінарного файлу масиву обєктів
void Binary_Write(T **arr, int n) {
	ofstream Fb("Binary.dat", ios::binary);
	if (!Fb.is_open())
		throw Bad_File_Write_Exeption("Ошибка! Бинарный файл не был открыт для записи!");
	else {
		for (int i = 0; i < n; i++)
			Fb.write((char*)&arr[i], sizeof(&arr[i]));
		cout << "\nБинарный файл успешно создан!" << endl;
	}
	Fb.close();
}

template<typename T>//шаблонна функція зчитування з бінарного файлу масиву обєктів до іншого массиву обєктів
void Binary_Read(T **arr, int n) {
	ifstream Fb("Binary.dat", ios::binary);
	if (!Fb.is_open())
		throw Bad_File_Read_Exeption("Ошибка! Бинарный файл не был открыт для считывания!");
	else {
		cout << "\nБинарный файл успешно считан!" << endl;
		for (int i = 0; i < n; i++) {
			Fb.read((char*)&arr[i], sizeof(T));
			arr[i]->Show();
		}
	}
	Fb.close();
}

void Menu() {
	int n = 0;
	DailyBalance db(10, 10);
	DailyBalance db1(10, 10);
	DailyBalance db2(10, 10);
	while (true){
		cout << "\nМеню" << endl;
		cout << "\t1. Ввести данные" << endl;
		cout << "\t2. Вывести данные в таблице" << endl;
		cout << "\t3. Запись данных на диск" << endl;
		cout << "\t4. Считывание данных" << endl;
		cout << "\t5. Поиск" << endl;
		cout << "\t6. Выход" << endl;
		cout << "\nВаш выбор: ";
			cin >> n;
			switch (n){
				case 1:
					db.Set();
					break;
				case 2: 
					db.Show();
					Average_Counts_Of_Dishes(db);
					Average_Price(db);
					break;
				case 3:
					Binary_Write(db.getArr(), db.getSize());
					Text_Write(db.getArr(), db.getSize());
					break;
				case 4:
					Binary_Read(db1.getArr(), db1.getSize());
					Text_Read(db2.getArr(), db2.getSize());
					break;
				case 5:
					Find(db);
					break;
				case 6:
					exit(0);
					break;
				default:
					cout << "\nТакого пункта нет в меню. Введите еще раз." << endl;
					break;
			}
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		Menu();
	}
	catch (MyException &ex) { //контролюючий блок який відловлює всі виключення(структури) які наслідуються від Базового классу виключень
		cout << ex.what();	  //показує яке саме виключення було схоплене
	}

	_getch();
	return 0;
}