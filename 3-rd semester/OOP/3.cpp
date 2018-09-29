// oop3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include <cstring>
#include <cstdlib>

class Client {

//private:
	char *surname;
	int d_card, day_f, mounth_f, year_f;
	float  discount, sum;
public:
	Client() {
		surname = new char[strlen("None") + 1];
		strcpy(surname, "None");
		d_card = 0;
		sum = 0;
		day_f = 01;
		mounth_f = 01;
		year_f = 2000;
		discount = 00.00;
	}

	void Print() {
	//printf("Surname: %s\n", surname);
	printf("Number of discount card: %d\n", d_card);
	printf("Total sum: %.2f\n", sum);
	printf("Data of first order: %d", day_f);
	printf(".%d", mounth_f);
	printf(".%d\n", year_f);
	printf("Discount: %.1f\n", discount);
}
	
	void operator - (const Client &C) {
		int res, res1, res2;
		res = day_f - C.day_f;
		res1 = mounth_f - C.mounth_f;
		res2 = year_f - C.year_f;
		printf("\nKevin made the first purchase earlier Sam for %d days, %d mounth, %d years\n", abs(res), abs(res1), abs(res2));
	}
	
	void operator = (const Client &x) {
		//strcpy(x.surname, this->surname);
		this->d_card = x.d_card;
		this->sum = x.sum;
		this->day_f = x.day_f;
		this->mounth_f = x.mounth_f;
		this->year_f = x.year_f;
		this->discount = x.discount;
	}
	
	operator int() const
	{
		return int(this->sum);
	}

	float operator / (const Client &x) {
		return ((x.discount / 100) * x.sum);
	}

	void Input();
	//void Print();
	void Tab(Client Kevin, Client Sam, Client Bob);

	~Client() {
		if (surname) {
			delete[] surname;
		}
	}
};

char* Buf() {
	char *buff = new char[20];
	printf("Enter your surname: ");
	if (scanf_s("%s", buff, 19) != 1) {
		rewind(stdin);
		printf("Surname shouldn`t consist of more then 19 letters or numbers. Please try again!\n");
		buff = Buf();
	}
	rewind(stdin);
	return buff;
}

void Client::Input() {
	surname = new char[20];
	surname = Buf();
	printf("Enter num of discount card: ");
	while (scanf_s("%d", &d_card, 6) != 1 || d_card > 999999 || d_card < 0) {
		printf("////Invalid value, try again: ");
		while (getchar() != '\n');
	}

	printf("Enter sum(grn): ");
	while (scanf_s("%f", &sum, 8) != 1 || sum < 0) {
		printf("////Invalid value, try again: ");
		while (getchar() != '\n');
	}
	printf("Enter data: \n\n");
	printf("Enter day: ");
	while (scanf_s("%d.", &day_f, 2) != 1 || day_f > 31 || day_f < 1) {
		printf("////Invalid value, try again: ");
		while (getchar() != '\n');
	}
	printf("\nEnter mounth: ");
	while (scanf_s("%d.", &mounth_f) != 1 || mounth_f > 12 || mounth_f < 1) {
		printf("////Invalid value, try again: ");
		while (getchar() != '\n');
	}
	printf("\nEnter year: ");
	while (scanf_s("%d", &year_f) != 1 || year_f < 1980 || year_f > 9999) {
		printf("////Invalid value, try again: ");
		while (getchar() != '\n');
	}
	printf("\nEnter discount(percents): ");
	while (scanf_s("%f", &discount) != 1 || discount > 100 || discount < 0) {
		printf("////Invalid value, try again: ");
		while (getchar() != '\n');
	}
}



void Client::Tab(Client Kevin, Client Sam, Client Bob) {

	printf("\n--------------------------------------------------------------------------------------|\n");
	printf("       |   Surname| Number of discount card|    Sum|  Data of first purchase| Discount|\n");
	printf("--------------------------------------------------------------------------------------|\n");
	printf("  Kevin|%10s|%24d|%7.2f|        %d.%d.%d        |%9.1f|\n", Kevin.surname, Kevin.d_card, Kevin.sum, Kevin.day_f, Kevin.mounth_f, Kevin.year_f, Kevin.discount);
	printf("--------------------------------------------------------------------------------------|\n");
	printf("    Sam|%10s|%24d|%7.2f|        %d.%d.%d        |%9.1f|\n", Sam.surname, Sam.d_card, Sam.sum, Sam.day_f, Sam.mounth_f, Sam.year_f, Sam.discount);
	printf("--------------------------------------------------------------------------------------|\n");
	printf("    Bob|%10s|%24d|%7.2f|        %d.%d.%d        |%9.1f|", Bob.surname, Bob.d_card, Bob.sum, Bob.day_f, Bob.mounth_f, Bob.year_f, Kevin.discount);
	printf("\n--------------------------------------------------------------------------------------|\n");

}

void Menu(Client Kevin, Client Sam, Client Bob) {
	//float s;
	Client z;
	int a = 1;
	int v;
	float x;
	while (1)
	{
		printf("\nMenu\n\n");
		printf("1.Enter data\n");
		printf("2.Print data\n");
		printf("3.Print of preloads\n");
		printf("4.Exit\n");
		printf("\nYou order:	");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf("\nKevin\n\n");
			Kevin.Input();
			printf("\n\nSam\n");
			Sam.Input();
			printf("\n\nBob\n");
			Bob.Input();
			break;
		case 2:
			z.Tab(Kevin, Sam, Bob);
			break;
		case 3:
			printf("\n\--------------->Before assigning<---------------\n\n");
			Kevin.Print();
			Kevin = Bob;
			printf("\n--------------->After<---------------\n\n");
			Kevin.Print();
			printf("\n------------------------------\n\n");
			Kevin - Sam;
			x = Kevin / Sam;
			printf("\nSam`s discount(UAH) = %.2f\n", x);
			v = int(Kevin);
			printf("\nSum(integer) = %d\n\n", v);
			break;
		case 4:
			printf("\nExit from program\n");
			exit(1);
			break;
		default: printf("\nPlease choose variant. Try again!\n");
		}
	}
}

int main()
{
	Client Kevin ,Sam, Bob;
	Menu(Kevin, Sam, Bob);
	_getch();
	return 0;
}

