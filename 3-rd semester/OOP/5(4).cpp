// 4ооп.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

class Date {
private:
	int year, week;
public:
	Date() : year(2017), week(40) {
		printf("\nDate default constructor\n");
	}

	Date(int year1, int week1) : year(year1), week(week1) {
		printf("\nDate init constructor\n");
	}

	Date(const Date &d) {
		year = d.year;
		week = d.week;
	}

	 virtual void Show() {
		printf("\nShow Date: ");
		printf("\nyear - %d, week - %d\n", year, week);
	}

	virtual ~Date() {
		printf("\nDate destructor\n");
	}
};

class Flower {
private:
	char *name, *color;
public:
	Flower() {
		name = new char[strlen("Flower") + 1];
		strcpy(name, "Flower");
		color = new char[strlen("Color") + 1];
		strcpy(color, "Color");
		printf("\nFlower default constructor\n");
	}

	Flower(char *name1, char *color1) {
		name = new char[strlen(name1) + 1];
		strcpy(name, name1);
		color = new char[strlen(color1) + 1];
		strcpy(color, color1);
		printf("\nFlower init constructor\n");
	}

	Flower(const Flower &f) {
		name = new char[strlen(f.name) + 1];
		strcpy(name, f.name);
		color = new char[strlen(f.color) + 1];
		strcpy(color, f.color);
	}

	virtual void Show() {
		printf("\nShow Flower\n");
		printf("\nName of flower: \"%s\"\nColor of flower: %s\n", name, color);
	}

	~Flower() {
		if (name) {
			delete[] name;
		}
		if (color) {
			delete[] color;
			}
		printf("\nFlower destructor\n");
	}
};

class Flower_Product : virtual public Flower {
private:
	Flower f;
	char *TypeOfSale;
public:
	Flower_Product() : f() {
		printf("\nFlower_Product default constructor\n");
	}

	Flower_Product (char *name1, char *color1, char *TypeOfSale1) : f(name1, color1) {
		printf("\nFlower_Product init constructor\n");
		TypeOfSale = new char[strlen(TypeOfSale1) + 1];
		strcpy(TypeOfSale, TypeOfSale1);
	}

	Flower_Product(const Flower_Product &fp) : f(fp) {
		TypeOfSale = new char[strlen(fp.TypeOfSale) + 1];
		strcpy(TypeOfSale, fp.TypeOfSale);
	}

	void Show() {
		printf("\n\t\tShow F_P\n");
		f.Show();
		printf("\nType of sale: %s\n", TypeOfSale);
	}

	~Flower_Product() {
		if (TypeOfSale) {
			delete[] TypeOfSale;
		}
		printf("\nFlower_Product destructor\n");
	}
};

class Consignment : public Flower_Product  {
private:
	Flower_Product fp;
	int count;
public:
	Consignment() : fp(), count(10) {
		printf("\nConsignment default constructor\n");
	}

	Consignment(char *name1, char *color1, char *TypeOfSale1, int count1) : fp(name1, color1, TypeOfSale1), count(count1) {
		printf("\nConsignement init constructor\n");
	}

	Consignment(const Consignment &c) : fp(c) {
		count = c.count;
	}

	void Show() {
		printf("\n\t\tShow Consignmet\n");
		fp.Show();
		printf("\nCount of this type of flowers = %d\n", count);
	}

	~Consignment() {
		printf("\nConsignement destructor\n");
	}
};

class Delivery : virtual public Date, public Consignment {
private:
	Date d;
	Consignment c;
public:
	Delivery() : d(), c() {
		printf("\nDelivery default constructor\n");
	}

	Delivery(int year1, int week1, char *name1, char *color1, char *TypeOfSale1, int count1) : d(year1, week1), c(name1, color1, TypeOfSale1, count1) {
		printf("\nDelivery init constructor\n");
	}

	Delivery(const Delivery &d) : d(d), c(d) {}

	void Show() {
		printf("\n\t\tShow Delivery\n");
		d.Show();
		c.Show();
	}

	~Delivery() {
		printf("\nDelivery destructor\n");
	}
};

class Sale : virtual public Date, public Consignment {
private:
	Date d;
	Consignment c;
public:
	Sale() : d(), c() {
		printf("\nSale default constructor\n");
	}

	Sale(int year1, int week1, char *name1, char *color1, char *TypeOfSale1, int count1) : d(year1, week1), c(name1, color1, TypeOfSale1, count1) {
		printf("\nSale init constructor\n");
	}

	Sale(const Sale &s) : d(s), c(s) {}

	void Show() {
		printf("\n\t\tShow Sale\n");
		d.Show();
		c.Show();
	}

	~Sale() {
		printf("\nSale destructor\n");
	}
};

class Daily_Balance : public Delivery, public Sale {
private:
	Delivery d;
	Sale s;
public:
	Daily_Balance() : d(), s() {
		printf("\nDaily_Balance default constructor\n");
	}

	Daily_Balance(int year1, int week1, char *name1, char *color1, char *TypeOfSale1, int count1) : d(year1, week1, name1, color1, TypeOfSale1, count1), s(year1, week1, name1, color1, TypeOfSale1, count1) {
		printf("\nDaily_Balance init constructor\n");
	}

	Daily_Balance(const Daily_Balance &db) : d(db), s(db) {}

	void Show() {
		printf("\n\t\tShow D_B\n");
		d.Show();
		s.Show();
	}

	~Daily_Balance() {
		printf("\nDaily_Balance destructor\n");
	}
};

int main()
{
	Date *d;
	int c = 1;
	while (c == 1) {
		Daily_Balance *db = new Daily_Balance(2001, 21, "Aloe", "Green", "Vase", 37);
		delete db;
		printf("\n-------------------------Date-------------------------\n");
		d = new Date(2007, 47);
		d->Show();
		printf("\n------------------------------------------------------\n\n");
		delete d;
		printf("\n-----------------------Delivery-----------------------\n");
		d = new Delivery(2005, 17, "Aster", "Blue", "By the piece", 17);
		d->Show();
		printf("\n------------------------------------------------------\n\n");
		delete d;
		printf("\n-------------------------Sale-------------------------\n");
		d = new Sale(2007, 39, "Camellia", "Pink", "Bouquet", 73);
		d->Show();
		printf("\n------------------------------------------------------\n");
		delete d;
		printf("\nIf you want to continue - press 1, if not - press 0.\nEnter your choice: ");
		while (scanf_s("%d", &c) != 1 || c < 0 || c > 1) {
			printf("Invalid value, press 1 or 0: ");
			while (getchar() != '\n');
		}
	}
	return 0;
}

