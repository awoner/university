#include "stdafx.h"
#include <iostream>

using namespace std;


struct list{
	list *next;
	char elem;
};

struct list2{
	list2 *next;
	list2 *pred;
	char elem;
};


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUSSIAN");
list *first; 
list *p; 
char ch, let; 
int str=1, el=1; 
bool found = false; 
first = new list(); 
first->next = NULL; 
p = first; 

cout << "\nЗадание №1\n\nВведите текст:" << endl; 

while ((ch = getchar()) != '\n') { 
p->elem = ch; 
p->next = new list(); 
p = p->next; 
} 
p->next = NULL; 

cout << "Введите букву:" << endl; 
let = getchar(); 
cout << endl << endl;
fflush(stdin); 


int res = 0; 
p = first; 



while (p->next != NULL) 
{ 
if (p->elem == let) ++res; 
p = p->next; 
} 

cout << " " << "Число вхождений: " << "  " << res  << endl; 

if (first->elem == let){ 
first = first->next; 
cout<< " " << "Строка: 1, Элемент: 1" <<endl; 
} 
p = first; 
while (p->next != NULL){ 
if(p->elem==' ')
{ 
	str++;
	el=0;
} 
if (p->elem == let)
{ 
cout<< " " << "Строка: " << str << " Элемент: " << el <<endl; 
//break; 
} 

p = p->next; 
el++; 
} 

cout << endl << endl;
cout << "//////////////////////////////////////////////////////////" << endl;




		list2 *first1 = new list2();
	first1->pred = NULL;
	first1->next = NULL;
	list2 *p1, *last1, *pl1;
	p1 = first1;



	cout << "\n\nЗадание №2\n\nВведите текст:" << endl;
	while ((ch = getchar()) != '\n'){
		p1->elem = ch;
		p1->next = new list2();
		p1->next->pred = p1;
		p1 = p1->next;
	}	
		p1->next = NULL;
		last1 = p1;




	cout << "Введите символ: " << endl;
	let = getchar();
	fflush(stdin);

	p1 = first1;
	for (int i = 0; p1 != last1 && p1->elem != let; i++){
		p1 = p1->next;
	}

	pl1 = last1;
	for (int i = 0; pl1 != first1 && pl1->elem != let; i++){
		pl1 = pl1->pred;
	}

	if (p1 != pl1 && p1 != last1 && p1->next != pl1->pred && p1->next != pl1){
		list2 *temp1 = pl1->pred;
		p1->next->next = pl1;
		pl1->pred = p1->next;
		p1->next = temp1;
		p1 = pl1->pred;
		pl1 = temp1;
		temp1 = pl1->pred;
		if (temp1 == p1){
			pl1->next = temp1;
			temp1->pred = pl1;
		}
		while (temp1 != p1){
			temp1->next = temp1->pred;
			temp1->pred = pl1;
			pl1->next = temp1;
			pl1 = temp1;
			temp1 = temp1->next;
		}
	}

	
	cout << "Левый элемент: " << p1->pred->elem << "\t" << "Правый элемент: " << p1->next->elem <<  endl;
		



system("pause"); 
return 0; 
}
