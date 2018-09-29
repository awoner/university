#include "stdafx.h"
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std; 

enum Token_value : char {
  NAME, NUMBER, END,
  PLUS='+', MINUS='-', MUL='*', DIV='/', PRINT=';', ASSIGN='=', LP='(', RP=')', KOMA=',',
  SIN=234, COS, TAN, CTAN = 252, SQRT, ConvertToDouble, POW=255,
  ConvertToS=245
};

enum Number : char {
  NUM0='0', NUM1='1', NUM2='2',  NUM3='3', NUM4='4', NUM5='5',
  NUM6='6', NUM7='7', NUM8='8',   NUM9='9', NUMP='.'
};

Token_value curr_tok = PRINT;        // Зберігає останнє повернення функції get_token().
double number_value;                 // Зберігає цілий літерал або літерал з плаваючою комою.
string string_value;            // Зберігає ім'я.
map<string, double> constant; // Всі константи, а саме pi, e.
int errors = 0; //зберігає кількість помилок, що зустрічаються під час роботи програми                
double expr(istream*, bool);    
int sch = 1;

// Функція error() має тривіальний характер: інкрементує лічильник помилок
double error( const string &error_message) {  
  errors++;
  cerr << "error " <<errors<<":"<< error_message << endl;
  return 0;
}

Token_value get_token(istream *input) {
  char ch;
  string str="";
  int err=0;
  for(int i = 0; i < 5; i++)
  {
 do {    // Пропустити всі пробільні символи крім '\n'.
    if (!input->get(ch)) {
      return curr_tok = END; // Завершити роботу калькулятора.
    }
  } while (ch != '\n' && isspace(ch)); 
  
    str+=ch;
  switch (ch) {
    case 0: // При вводі символа кінця файла, завершити роботу калькулятора.
      return curr_tok = END;
    case PRINT:
    case '\n':
      return curr_tok = PRINT;
    case MUL:
    case DIV:
    case PLUS:
    case MINUS:
	case CTAN:
	case SIN:
    case LP:
      if(str=="sin(")
        return curr_tok = SIN;
	  if(str=="cos(")
		  return curr_tok = COS;
	  if(str=="tg(")
		  return curr_tok = TAN;
	   if(str=="ctg(")
		  return curr_tok = CTAN;
	   if(str=="sqrt(")
		  return curr_tok = SQRT;
	   if(str=="ctd(")
		  return curr_tok = ConvertToDouble;
	   if(str=="cts(")
		  return curr_tok = ConvertToS;
	   if(str=="pow(")
		  return curr_tok = POW; 
    case RP:
	case KOMA:
    case ASSIGN:
      return curr_tok = Token_value(ch); // Приводить до цілого і повернення.
    case NUM0: case NUM1: case NUM2: case NUM3: case NUM4:
    case NUM5: case NUM6: case NUM7: case NUM8: case NUM9:
	case NUMP:

      (*input).putback(ch); // Положити назад в потік...
      *input >> number_value; // І рахувати всю лексему.
      return curr_tok = NUMBER;
    default:
		if(str=="pi")
		{
			string_value = str;
			return curr_tok=NAME;
		}
		if(str=="e")
		{
			string_value = str;
			return curr_tok=NAME;
		}
  }
		
  }
 }
/*Кожна функція синтаксичного аналізу приймає аргумент типу bool,
який вказує чи повинна функція визивати get_token() для отримання чергової лексеми*/

double prim(istream* input, bool get) {
	if (get) {
    get_token(input);
  }
  switch (curr_tok) {
    case NUMBER: {
      double v = number_value;
      get_token(input);
      return v;
    }
    case NAME: {
      double v = constant[string_value];
      if (get_token(input) == ASSIGN) {
          v = expr(input, true);
      }
      return v;
    }
    case MINUS:
      return -prim(input, true);
    case LP: {
      double left = expr(input, true);
      if (curr_tok != RP) {
          return error("отсутствует ')'");
      }
      get_token(input);
      return left;
    }
	case POW: {
		double left = expr(input, true);
		if(curr_tok!=KOMA)
		{
			return error("отсутствует ','");
      }
		double right = expr(input, true);
		if(curr_tok!=')')
		{
			return error("отсутствует ')'");
      }
		get_token(input);
		return pow(left,right);
			  }
	case SIN: {

		double left = expr(input, true);
     if (curr_tok != RP) {
          return error("отсутствует ')'");
      }
      get_token(input);
		return sin(left);
			  }
    case COS: {

		double left = expr(input, true);
     if (curr_tok != RP) {
          return error("отсутствует ')'");
      }
      get_token(input);
		return cos(left);
			  }
	case TAN: {

		double left = expr(input, true);
     if (curr_tok != RP) {
          return error("отсутствует ')'");
      }
      get_token(input);
		return tan(left);
			  }
	case CTAN: {

		double left = expr(input, true);
     if (curr_tok != RP) {
          return error("отсутствует ')'");
      }
      get_token(input);
		return  (1/tan(left)); //(cos(left)/sin(left));
			  }
	case SQRT: {

		double left = expr(input, true);
     if (curr_tok != RP) {
          return error("отсутствует ')'");
      }
      get_token(input);
	  if(left<0)
	  {
		 return error("Нельзя добывать корень с отрицательного числа");
	  }
		return sqrt(left);
			  }
	case ConvertToDouble:
		{

		int left = expr(input, true);
     if (curr_tok != RP) {
          return error("')' expected");
      }
	 double b;
	 double c = 0;
	 for(int i =0; left > 0; i++)
	 {
		 b = left%2;
		 left = (left-b)/2;
		 c+=b*pow(10,i);
	 }
      get_token(input);
		return c;
			  }
  
	case ConvertToS:
		{
		int left = expr(input, true);
     if (curr_tok != RP) {
          return error("')' expected");
      }
	  cout<<hex<<left<<endl;
      get_token(input);
	  return 1;
		}
    default:
      break;
  }
}

// term() - множення і ділення.
double term(istream* input, bool get) {
  double left = prim(input, get);

  for ( ; ; ) {
    switch (curr_tok) {
      case MUL:
        left *= prim(input, true);
        break;
      case DIV:
        if (double d = prim(input, true)) {
            left /= d;
            break;
        }
        return error("Нельзя делить на 0");
      default:
          return left;
    }
  }
}

// expr() - додавання і віднімання.
double expr(istream* input, bool get) {
   double left = term(input, get);

  for ( ; ; ) {
    switch (curr_tok) {
      case PLUS:
        left += term(input, true);
        break;
      case MINUS:
        left -= term(input, true);
        break;
      default:
        return left;
    }
  }
}

int main() {
	setlocale(0, "");
	cout<<"                            -------------                                "<<endl;
	cout<<"                           | Калькулятор |                              "<<endl;
	cout<<"                            -------------                                "<<endl;
	cout<<"     Стандартный набор математических, тригонометрических функций, а  "<<endl;
	cout<<"  также функций перевода в двоичую и шестнадцатеричную системы счисления   "<<endl;
	cout<<"     ----------------------------------------------------------------"<<endl;
	cout<<"    |  '+'    - операция сложения.  Пример: a+b=c                    |"<<endl;
	cout<<"    |  '-'    - операция вычитания. Пример: a-b=c                    |"<<endl;
	cout<<"    |  '*'    - операция умножения. Пример: a*b=c                    |"<<endl;
	cout<<"    |  '/'    - операция деления.   Пример: a/b=c                    |"<<endl;
	cout<<"    |  '('    - левая скобка                                         |"<<endl;
	cout<<"    |  ')'    - правая скобка                                        |"<<endl;
	cout<<"    |  pow(a,b) - операция поднесения числа а в степень b            |"<<endl;
	cout<<"    |  sqrt() - операция извлечения кореня.                          |"<<endl;
	cout<<"    |  sin()  - тригонометрическая функция.                          |"<<endl;
	cout<<"    |  cos()  - тригонометрическая функция.                          |"<<endl;
	cout<<"    |  tg()   - тригонометрическая функция.                          |"<<endl;
	cout<<"    |  ctg()  - тригонометрическая функция.                          |"<<endl;
	cout<<"    |  ctd()  - перевод в двоичную систему счисления(ConvertToDouble)|"<<endl;
	cout<<"    |  cts()  - перевод в шестнадцатеричную систему счисления.       |"<<endl;
	cout<<"    |  Для окончания программы нажмите символ конца файла (Ctrl+Z).  |"<<endl;
	cout<<"    |  Создатель: Гарник Алексей                                     |"<<endl;
	cout<<"     ----------------------------------------------------------------"<<endl;
    cout<<"                       Введите ваш пример №1:"<<endl;
  istream *input = 0; // Вказівник на потік.
      input = &cin;

  constant["pi"] = 3.14159265358979323;
  constant["e"] = 2.718281828;

  while (*input) {
    get_token(input);
    if (curr_tok == END) {
      break;
    }
    // Знімає відповідальність expr() за обработку пустих виразів.
    if (curr_tok == PRINT) {
      continue;
    }
    // expr() -> term() -> prim() -> expr() ...
    cout << "Ответ:" << setprecision(11)<< expr(input, false) << endl;
	sch++;
	  cout<<"                       Введите ваш пример"<<" №"<<sch<<":"<<endl;
	errors = 0;
  }
  system("cls");
  return errors;
}