// Joint - Text Editior.cpp: главный файл проекта.

#include "stdafx.h"
#include "Form1.h"

using namespace Курсач;

[STAThreadAttribute]
int main()
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Создание главного окна и его запуск
	Application::Run(gcnew Form1());
	return 0;
}
