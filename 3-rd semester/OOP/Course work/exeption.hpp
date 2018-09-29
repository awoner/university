#pragma once
//базовий класс виключень
class MyException {
	const char *message = nullptr;
public:
	MyException(const char *message = "Unknown exception") : message(message) {}
		
	const char* what() const {
		return message;
	}
};
//виключення: "Не вірний аргумент!"
struct Wrong_Argument_Exeption : MyException {
	Wrong_Argument_Exeption(const char *message = "Wrong argument exception") : MyException(message) {}
};
//виключення: "Вихід за межі!"
struct Out_Of_Range_Exception : MyException {
	Out_Of_Range_Exception(const char *message = "Out of range exception") : MyException(message) {}
};
//виключення: "Поганий файл!"
struct Bad_File_Exeption : MyException {
	Bad_File_Exeption(const char *message = "Bad file exception") : MyException(message) {}
};
//виключення: "Поганий файл для запису!"
struct Bad_File_Write_Exeption : MyException {
	Bad_File_Write_Exeption(const char *message = "Bad file write exception") : MyException(message) {}
};
//виключення: "Поганий файл для зчитування!"	
struct Bad_File_Read_Exeption : MyException {
	Bad_File_Read_Exeption(const char *message = "Bad file read exception") : MyException(message) {}
};