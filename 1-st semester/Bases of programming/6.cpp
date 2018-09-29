#include <math.h>
#include <iostream>

using namespace std;

int main()
{
	float x=0.56, y=0.28, sum=0;
	float eps = 0.0001;

	for (int i = 0; i == 0;)
	{
		cout << "enter x: ";
		cin >> x;
		if (x < -1 || x>1)
		{
			cout << "ERROR" << endl;
			system("pause");
			system("cls");
		}
		else i++;
	}

	float ch = 0.56, zn = 1;  //ch i zn - чисельник і знаменник відповідно, при і=0
     for (int i=0; fabs(y) > eps; i+=1)
	{
		ch *= 0.3136;              //зміна чисельника при кожному наступному і
	    zn *= 2;                            //зміна знаменника при кожному наступному і
		y = ch / (zn + 1);
		if (i % 2) y = -y;
		sum += y;
	}

	cout << "S = " << sum << endl;
	system("pause");
}
