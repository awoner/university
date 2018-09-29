#pragma once
#include <iostream>

char *d_type[] = { "������", "������", "������" };

using namespace std;

class TypeOfDish {/*(�����, �����, ������)*/
private:
	char *type;
public:
	//����������� �� �������������
	TypeOfDish() {			
		int i = rand() % 3;
		type = new char[strlen(d_type[i]) + 1];
		strcpy(type, d_type[i]);
	}
	//����������� �����������
	TypeOfDish(char *a_type)  {	
		this->type = new char[strlen(a_type) + 1];
		strcpy(this->type, a_type);
	}
	//����������� ���������
	TypeOfDish(const TypeOfDish &copy) {
		type = copy.type;
	}
	//�������������� �������� ��������� � ����
	friend ostream& operator << (ostream &os, const TypeOfDish &o_type_of_dish) {
		os << setw(15) << o_type_of_dish.type;
		return os;
	}
	//�������������� �������� �������� � ������
	friend istream& operator >> (istream &is, TypeOfDish &o_type_of_dish) {
		is >> o_type_of_dish.type;
		return is;
	}

	void Set();//����� ������� ����
	void Show();//����� ���� �������� �� ������� �������

	char *getType() {
		return type;
	}
	//����������
	~TypeOfDish() {
		if (type)
			delete[] type;
	}
};
//��������� ������ ������� ����
void TypeOfDish::Set() {
	bool flg = true;								
	type = new char[10];
	cout << "   �������� ��� �����" << endl;
	cout << "\n    1. ������"<< endl;
	cout << "\n    2. ������" << endl;
	cout << "\n    3. ������" << endl;
	int a;
	cout << "\n   ��� �����: ";
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
			cout << "������ ���� ����� ����. ������� ��� ���." << endl;
		}
	}
}
//��������� ������ �������� �� �������
void TypeOfDish::Show() {
	cout << setw(9) << type << "|";
}