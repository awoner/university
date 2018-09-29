#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cctype>


class Client {
private:

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
	printf("Default constructor.");
  }

  Client(char* sur, int card, float summ, int day, int mounth, int year, float dscnt) {
    surname = new char[strlen(sur) + 1];
    strcpy(surname, sur);
    d_card = card;
    sum = summ;
    day_f = day;
    mounth_f = mounth;
    year_f = year;
    discount = dscnt;
  }

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

  void Set() {
    surname = new char[20];
    surname = Buf();
    printf("Enter num of discount card(not more than 6 num): ");
    while (scanf_s("%d", &d_card, 6) != 1 || d_card > 999999) {
      printf("////Invalid value, try again: ");
      while (getchar() != '\n');
    }

    printf("Enter sum(GRN): ");
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

  void Get() {
    printf("\n\nSurname: %s\n", surname);
    printf("Number of discount card: %d\n", d_card);
    printf("Total sum(grn): %.2f\n", sum);
    printf("Data of first order: %d", day_f);
    printf(".%d", mounth_f);
    printf(".%d\n", year_f);
    printf("Discount(percents): %.1f\n", discount);
  }

  Client(const Client &t) {
    surname = new char[strlen(t.surname) + 1];
    strcpy(surname, t.surname);
  /*  surname = t.surname;*/
    d_card = t.d_card;
    sum = t.sum;
    day_f = t.day_f;
    mounth_f = t.mounth_f;
    year_f = t.year_f;
    discount = t.discount;
  }

  ~Client() {
    if (surname != nullptr){
      delete[] surname;
	  printf("\n\nDestructor is working!\n\n");
	}
  }

};

Client Bob;

int main()
{
  //printf("Default constructor.");
  Bob.Get();
  Client Aleksey;
  printf("\nAlex:\n");
  Aleksey.Set();
  Aleksey.Get();
  printf("\n\nInit constructor.\n\n");
  Client Rick("Sanchez", 1111, 1488, 10, 12, 2012, 12);
  Rick.Get();
  printf("\n\nMorty(copy of constructor): \n\n");
  Client Morty(Rick);
  Morty.Get();
  _getch();
  return 0;
}