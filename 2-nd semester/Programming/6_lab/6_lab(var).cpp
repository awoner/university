//
//  main.cpp
//  cpp
//
//  Created by Денис Трухан on 26.04.17.
//  Copyright © 2017 Денис Трухан. All rights reserved.
//


#include <fstream>
#include <iomanip>
#include <cstdio>


#include "iostream"

#include "stdio.h"




#include<string>

using namespace std;

struct cserv {
    
    string brand ;
    
    int kolvomasterov;
    
    string adres;
    
    string vremya;
    
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

void write_file();
bool compare(string, string);

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
            
            case 6:write_file();break;
                
            case 7: return 0;
                
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
        
        cout << "Название: ";
        
        cin >> arr[sch].brand;
        
        cout << "Адрес: ";
        
        cin >> arr[sch].adres;
        
        cout << "Количество мастеров: ";
        
        cin >> arr[sch].kolvomasterov;
        
        cout << "Время работы: ";
        
        cin >> arr[sch].vremya;
        
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
    
    cout<<"6-Запись в файл\n";
    
    cout<<"7-Выход\n";
    
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
            
            cout<<"Название:\t" << arr[k-1].brand << endl;;
            
            cout<<"Адрес:\t" << arr[k-1].adres << endl;
            
            cout<<"Количество мастеров:\t" << arr[k-1].kolvomasterov << endl;
            
            cout<<"Время работы:\t" << arr[k-1].vremya << endl;
            
            cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            
            cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            
        }
        
        if(sw==2)
            
        { for(int i=0;i<sch;i++)
            
        {
            
            cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            
            cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            
            cout<<"Название:\t"<<arr[i].brand<<endl;
            
            cout<<"Адрес:\t"<<arr[i].adres <<endl;
            
            cout<<"Количество мастеров:\t"<<arr[i].kolvomasterov<<endl;
            
            cout<<"Время работы:\t"<<arr[i].vremya<<endl;
            
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
        
        cout<<"1-Изменение названия\n";
        
        cout<<"2-Изменение адреса\n";
        
        cout<<"3-Изменение количества мастеров\n";
        
        cout<<"4-Изменение времени работы\n";
        
        cout<<"5-Прекращение\n";
        
        cout<< "___________________________________________________"<<endl;
        
        cin>>per;
        
        switch (per)
        
        { case 1: cout<<"\nВведите новое название\n";
                
                cin>>arr[c-1].brand;
                
                break;
                
            case 2:
                
                cout<<"\nВведите новый адрес\n";
                
                cin>>arr[c-1].adres;
                
                break;
                
            case 3:
                
                cout<<"Введите новое количество мастеров\n";
                
                cin>>arr[c-1].kolvomasterov;
                
                break;
                
            case 4:
                
                cout<<"Введите новое время работы\n";
                
                cin>>arr[c-1].vremya;
                
                break;
                
            case 5:
                
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
        
        cout<<"1-Название\n";
        
        cout<<"2-Адрес\n";
        
        cout<<"3-Количество мастеров\n";
        
        cout<<"4-Время работы\n";
        
        cout<<"5-Выйти\n";
        
        cout<< "___________________________________________________"<<endl;
        
        cin>>sw;
        
        for(int i=0;i<sch;i++){
            
            cout<< "___________________________________________________"<<endl;
            
            switch (sw) {
                    
                case 1:{
                    
                    string po;
                    
                    cin>>po;
                    
                    for(int i = 0; i < sch; i++)
                        
                    {
                        
                        if(po == arr[i].brand){
                            
                            cout<<"Адрес:\t" << arr[i].adres << endl;
                            
                            cout<<"Количество мастеров:\t" << arr[i].kolvomasterov << endl;
                            
                            cout<<"Время работы:\t" << arr[i].vremya << endl;
                            
                        }}
                    
                    break;}
                    
                case 2:{
                    
                    string po;
                    
                    cin>>po;
                    
                    for(int i = 0; i < sch; i++)
                        
                    {
                        
                        if(po == arr[i].adres){
                            
                            cout<<"Название:\t" << arr[i].brand << endl;
                            
                            cout<<"Количество мастеров:\t" << arr[i].kolvomasterov << endl;
                            
                            cout<<"Время работы:\t" << arr[i].vremya << endl;
                            
                        }}
                    
                    break;
                    
                }
                    
                case 3:{
                    
                    int spec;
                    
                    cin>>spec;
                    
                    for(int i = 0; i < sch; i++)
                        
                    {
                        
                        if(spec == arr[i].kolvomasterov){
                            
                            cout<<"Название:\t" << arr[i].brand << endl;
                            
                            cout<<"Адрес:\t" << arr[i].adres << endl;
                            
                            cout<<"Время работы:\t" << arr[i].vremya << endl;
                            
                        }}
                    
                    break;}
                    
                case 4:{
                    
                    string spec;
                    
                    cin>>spec;
                    
                    for(int i = 0; i < sch; i++)
                        
                    {
                        
                        if(spec == arr[i].vremya)
                            
                        {
                            
                            cout<<"Название:\t" << arr[i].brand << endl;
                            
                            cout<<"Адрес:\t" << arr[i].adres << endl;
                            
                            cout<<"Количество мастеров:\t" << arr[i].kolvomasterov << endl;
                            
                            cout<<"__________________________"<<endl;
                            
                        }
                        
                    }
                    
                    break;
                    
                }
                    
                case 5: return;
                    
                default:
                    
                    cerr << "Вы выбрали неверный вариант" << endl;
                    
                    break;
                    
            }
            
        }
        
    }
    
}


void write_file()
{



    	ofstream file;
	string name;
	cout << "Введите название файла(.txt)" << endl;
	cin >> name;
	file.open(name);
	if (!file.is_open())
		cout << "Файла нету" << endl;
	else
	{
		//file.clear();
		file << "Название	" << "Адрес	"<< "Количество мастеров	"  << "Время работы	" << endl;
        for (int i = 0; i < sch; i++)
        {
            file <<setw(5)<< i + 1;
            file <<setw(15) << arr[i].brand;
            file << setw(9) << arr[i].adres;
            file << setw(13) << arr[i].kolvomasterov ;
            file << setw(30) << arr[i].vremya << endl;
		}
		file.close();
	}
	cout << "Файл успешно записан." << endl;
}



