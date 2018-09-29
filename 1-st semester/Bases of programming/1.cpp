﻿/*******************************************************/
/*           Лабораторная  работа ╧                   */
/*          Типы данных и ввод-вывод                   */
/*        Пример выполнения. Вариант ╧1              */
/*******************************************************/
#include <stdio.h>
#include <iostream>
#include "stdafx.h"
#pragma warning ( disable : 4996 )
using namespace std;
int _tmain(int argc, _TCHAR* argv[]) {
 char name1[4], name2[20], name3[8], sd1[3], sd2[9], sd3[6];
 int ovp1 = 0, ovp2 = 0, ovp3 = 0, oop1 = 0, oop2 = 0, oop3 = 0; 
 int c1 =0, c2 = 0, c3 = 0;
 float sq1, sq2, sq3;
 /* Введение фактических данных*/
 printf("1. Введите: название, группу, место обитания, численность популяции >");
 scanf("%s %s %d %d %d",name1, sd1, &ovp1, &oop1, &c1);
 printf("2. Введите: название, группу, место обитания, численность популяции >");
 scanf("%s %s %d %d %d",name2, sd2, &ovp2, &oop2, &c2);
 printf("3. Введите: название, группу, место обитания, численность популяции >");
 scanf("%s %s %d %d %d",name3, sd3, &ovp3, &oop3, &c3);
 /* Вывод таблицы */
 /* вывод заголовков */
 printf("--------------------------------------------------------- \n");
 printf("|Некоторие виды антилоп                                  |\n");
 printf("|--------------------------------------------------------|\n");
 printf("| Название | группа| Место обитания|Численность популяции|\n");
 printf("|          |       |               |                     |\n");
 printf("|          |       |               |                     |\n");
 printf("|          |       |               |                     |\n");
 printf("|----------|-------|---------------|---------------------|\n");
 /* вывод строк фактических данных */
 printf("| %9s     | %c | %3d | %-5.1f |\n", name1, sd1, ovp1, oop1, c1);
 printf("| %9s    | %c | %3d | %-5.1f |\n", name2, sd2, ovp2, oop2, c2);
 printf("| %9s     | %c | %3d | %-5.1f |\n", name3, sd3, ovp3, oop3, c3);
 /* вывод примечаний */
 printf("|--------------------------------------------------------|\n");
 printf("| Группы: A - настоящие антилопы; B - Коровьи антилопы;  |\n");
 printf("|            H - лошадиные антилопы                      |\n");
 printf("--------------------------------------------------------- \n");
 return 0;
}