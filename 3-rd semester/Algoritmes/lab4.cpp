// 4алг.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

struct list {
	int val;
	list *next;
};

void Make_List(list **first, list **last, int n);
void Print_List(list *first);
bool Find_El(list *first, int k);
list *Delete_El(list *first, int l);
list *Add_El(int p, list *first);
void Delete_List(list *first);


int main()
{
	int n = 10, k, l, p;
	list *first = new list();
	first->next = NULL;
	Make_List(&first, n);
	Print_List(first);
	cout << "\nEnter element which you need to find: ";
	cin >> k;
	if (Find_El(first, k) == true) {
		cout << "\nThis item is found :)\n";
	}
	else {
		cout << "\nThis item is not found :(\n";
	}
	cout << "\nEnter a number which need to delete: ";
	cin >> l;
	Delete_El(first, l);
	Print_List(first);
	cout << "\nEnter a new element: ";
	cin >> p;
	Print_List(Add_El(p, first));
	_getch();
	return 0;
}

void Make_List(list **first, int n) {

	if (n > 0) {
		(*first) = new list();
		cout << "Enter value: ";
		cin >> (*first)->val;
		(*first)->next = NULL;
		Make_List(&((*first)->next), n - 1);
	}

}

void Print_List(list *first) {
	if (first != NULL) {
		cout << first->val << "\t";
		Print_List(first->next);
	}
}

list* Delete_El(list *first, int l) {
	list *ptr;
	list *current = first;
	for (int i = 1; i < l && current != NULL; i++) {
		current = current->next;
	}
		if (current != NULL) {
			if (current == first) {
				first = first->next;
				delete(current);
				current = first;
			}
			else {
				ptr = first;
				while (ptr->next != current) {
					ptr = ptr->next;
				}
				ptr->next = current->next;
				delete(current);
				current = ptr;
			}
		}
	return first;
}

list *Add_El(int p, list *first) {
	list* new_list = new list;
	new_list->val = p;
	new_list->next = first;
	return new_list;
}

bool Find_El(list *first, int k) {
	list *ptr;
	ptr = first;
	while (ptr != NULL) {
		if (k == ptr->val) { 
			return true;
		}
		else {
			ptr = ptr->next;
		}
	}
	return false;
}

void Delete_List(list *first) {
	if (first != NULL) {
		Delete_List(first->next);
		delete first;
	}
}