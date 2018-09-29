#include <iomanip>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <cstdio> 
#include <conio.h>
using namespace std;

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string temp;
	ifstream file_read(argv[1]);
	ofstream file_write(argv[2]);
	while (true)
	{
		
		if (file_read.eof()) break;
		getline(file_read,temp);
		file_write << temp <<endl;
	}
	file_read.close();
	file_write.close();
	system("pause");
	return 0;
}
