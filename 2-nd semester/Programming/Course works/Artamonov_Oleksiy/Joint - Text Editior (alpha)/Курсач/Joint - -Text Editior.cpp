// Joint - Text Editior.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Form1.h"

using namespace ������;

[STAThreadAttribute]
int main()
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew Form1());
	return 0;
}
