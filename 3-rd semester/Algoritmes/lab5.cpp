// ConsoleApplication9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
  
using namespace std;

struct Node {
	int val;
	Node *next, *prev;
};

class List {
private:
	Node *head, *tail;
	int n, k;
public:
	List() : head(NULL), tail(NULL) {
		cout << "Enter count of elements: ";
		cin >> n;
		cout << "\n";
	}

	void Show();
	void Add(int val);
	void Enter(List & lst);
	void Sort();

~List() {
		while (head) {
			tail = head->next;
			if (tail) {
				tail->prev = NULL;
			}
			delete head;
			head = tail;
		}
	}
};

void List::Enter(List & lst) {
	for (int i = 0; i < n; i++) {
		cout << "Enter value: ";
		cin >> k;
		lst.Add(k);
	}
	cout << "\n";
}

void List::Add(int val) {
	Node *tmp = new Node;
	tmp->next = NULL;
	tmp->val = val;
	if (head != NULL) {
		tmp->prev = tail; 
		tail->next = tmp; 
		tail = tmp;
	}
	else {
		tmp->prev = NULL;
		head = tail = tmp;
	}
}

void List::Show() {
	Node *tmp = tail;
	tmp = head;
	while (tmp != NULL) {
		cout << tmp->val << "\t";
		tmp = tmp->next;
	}
	cout << "\n";
}

void List::Sort() {
	Node *p = head->next;
	Node *q = tail->prev;
	int tmp;
	while (1) {
		tmp = p->val;
		p->val = q->val;
		q->val = tmp;
		p = p->next;
		if (p == q) {
			break;
		}
		q = q->prev;
		if (q == p) {
			break;
		}
	}
}


int main()
{
	List lst;
	lst.Enter(lst);
	lst.Show();
	lst.Sort();
	lst.Show();
	_getch();
    return 0;
}

