#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "stdafx.h"
#include <conio.h>

using namespace std;

	struct cserv {
	
		int number;
		char brand [30];
		int mileage;
		char master [30];
		int sum;
	
	};
	
	struct cserv arr[30];
	struct cserv tmp;
	int sch = 0;
	int er;
void vvod();
int menu();
void out();
void del();
void change();
void find();

int main()
{
	setlocale(LC_ALL, "rus");
	    while(1)
 { switch(menu())
 { 
 case 1:vvod();break;
 case 2:find();break;
 case 3:change();break;
 case 4:del();break;
 case 5:out();break;
 case 6: return 0;
 default: cout<<"Не верный выбор/n";
 }
 } 
	system ("pause");
	return 0;
}

void vvod(){
	
	if(sch<30){
		 cout<<"Структура номер: "<<sch+1<<endl;
		 cout<< "___________________________________________________"<<endl;
		cout << "Реестрационный номер автомобиля: ";
		cin >> arr[sch].number;
        cout << "Марка: ";
		cin >> arr[sch].brand;
		cout << "Пробег: ";
		cin >> arr[sch].mileage;
        cout << "Мастер, выполнивший ремонт: ";
	    cin >> arr[sch].master;
		cout << "Сумма ремонта: ";
		cin >> arr[sch].sum;
		cout<< "___________________________________________________"<<endl;
		sch++;
	}
	else cout << "Введено максимальное кол-во записей" ;
	
	}

int menu()
{
int er;
cout<< "___________________________________________________"<<endl;
 cout<<"Введите:\n";
 cout<<"1-Ввод массива структур\n";
 cout<<"2-Поиск в массиве структур по заданному параметру\n";
 cout<<"3-Изменение заданной структуры\n";
 cout<<"4-Удаление структуры из массива\n"; 
 cout<<"5-Вывод на экран массива структур\n";
 cout<<"6-Выход\n";
 cout<< "___________________________________________________"<<endl;
 cin>>er;
return er;
} 

void out() 
{
 int sw; 
 int k;
 if (sch==0)
 cout<<"\nНет структур: \n";
 else
 {
 cout<< "___________________________________________________"<<endl;
 cout<<"\nВведите: \n";
 cout<<"1-Вывод на экран какого-либо массива структур\n";
 cout<<"2-Вывод на экран всех массивов структур\n";
 cout<< "___________________________________________________"<<endl;
 cin>>sw;
 if(sw==1)
 {
 cout<< "___________________________________________________"<<endl;
 cout<<"Введите номер массива структур, который нужно вывести\n";
 cout<< "___________________________________________________"<<endl;
 cin>>k;
 cout<<endl;
 cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<"Реестрационный номер автомобиля:\t" << arr[k-1].number << endl;;
 cout<<"Марка:\t" << arr[k-1].brand << endl;
 cout<<"Пробег:\t" << arr[k-1].mileage << endl;
 cout<<"Мастер, выполнивший ремонт:\t" << arr[k-1].master << endl;
 cout<<"Сумма ремонта:\t" << arr[k-1].sum << endl;
 cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 }
 if(sw==2)
 { for(int i=0;i<sch;i++) 
 {
 cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 cout<<"Реестрационный номер автомобиля:\t"<<arr[i].number<<endl;
 cout<<"Марка:\t"<<arr[i].brand <<endl;
 cout<<"Пробег:\t"<<arr[i].mileage<<endl;
 cout<<"Мастер, выполнивший ремонт:\t"<<arr[i].master<<endl;
 cout<<"Сумма ремонта:\t"<<arr[i].sum <<endl;
cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
 }
 }
 }
}
	
void del()
{ 
	int d;
 cout<< "___________________________________________________"<<endl;
 cout<<"\nКакую из структур вы хотите удалить из массива\n";
 cout<<"Если необходимо удалить все структуры, нажмите '99'\n";
 cout<< "___________________________________________________"<<endl;
 cin>>d;
 if (d!=99)
 {
	for (int i=(d-1);i<sch;i++)
 arr[i]=arr[i+1]; 
 sch=sch-1; 
 }
 if (d==99) 
 { 
    for(int i=0;i<30;i++)
 arr[i]=tmp; 
 sch=0;
 }
} 

void change() 
{ int c; 
 int per;
 cout<< "___________________________________________________"<<endl;
 cout<<"\nВведите номер структуры\n";
 cout<< "___________________________________________________"<<endl;
 cin>> c;
do
 {
 cout<< "___________________________________________________"<<endl;
 cout<<"Введите: \n";
 cout<<"1-Изменение реестрационного номера автомобиля\n";
 cout<<"2-Изменение марки\n";
 cout<<"3-Изменение пробега\n";
 cout<<"4-Изменение иени мастера\n";
 cout<<"5-Изменение суммы за ремонт\n";
 cout<<"6-Прекращение\n";
 cout<< "___________________________________________________"<<endl;
 cin>>per;
switch (per)
 { case 1: cout<<"\nВведите новый реестрационный номер автомобиля\n";
cin>>arr[c-1].number;
 break;
 case 2:
 cout<<"\nВведите новую марку\n";
cin>>arr[c-1].brand;
 break;
 case 3:
 cout<<"Введите новый пробег \n";
cin>>arr[c-1].mileage;
 break;
 case 4:
 cout<<"Введите другое имя мастера\n";
cin>>arr[c-1].master; 
 break;
 case 5:
 cout<<"Введите новую сумму за ремонт\n";
cin>>arr[c-1].sum;
 break;
 case 6:
 return;
 }
}while(1); 
}

void find() 
{
 int sw; 
 if (sch==0)
 cout<<"\nНет структур: \n";
 else
 {
	 cout<< "___________________________________________________"<<endl;
cout<<"Введите: \n";
 cout<<"1-Реестрационный номера автомобиля\n";
 cout<<"2-Марка\n";
 cout<<"3-Пробег\n";
 cout<<"4-Имя мастера\n";
 cout<<"5-Сумма за ремонт\n";
 cout<<"6-Выйти\n";

 cout<< "___________________________________________________"<<endl;
 cin>>sw; 
 for(int i=0;i<sch;i++){
	cout<< "___________________________________________________"<<endl;
 switch (sw) {
      
        case 1:
          	 cout<<"Реестрационный номер автомобиля:"<<arr[i].number << endl; 
            break;
        case 2:
        cout<<"Марка:"<<arr[i].brand << endl;
            break;
        case 3:
           cout<<"Пробег:"<<arr[i].mileage << endl;
            break;
        case 4:
         cout<<"Мастер, выполнивший ремонт:"<<arr[i].master << endl;
            break;
        case 5:
         cout<<"Сумма ремонта:"<<arr[i].sum << endl;
            break;
			 case 6: return;
        default:
            cerr << "Вы выбрали неверный вариант" << endl;
           break;
    } 
}
}
}