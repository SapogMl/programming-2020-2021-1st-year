#include <iostream>
#include <string>
#include "Add.h"

using namespace std;

int readInt(long long& number)
{
	string ll;
	getline(cin, ll);
// 	bool nega = (number > 0 ? false : true);
	long long buf = 0;

	for (int i = 0 /* (nega == true ? 1 : 0) */; i < ll.size() /* (nega == true ? ll.size() + 1 : ll.size() */; i++)
	{
		if ((i == 0) and (int(ll[i]) == 48) and (ll.size() != 1))
		{
			resolveError(5);
			return 0;
		}  // не пашет, как надо
		if ((int(ll[i]) < 58) and (int(ll[i]) > 47))
		{
			buf = buf * 10 - '0' + ll[i];
		}
		else
		{
			if (int(ll[i]) == 32)
			{
				resolveError(1);
				return 0;
			}
			if ((int(ll[i]) > 64) and (int(ll[i]) < 91))
			{
				resolveError(3);
				return 0;
			}
			else
			{
				resolveError(2);
				return 0;
			}
		}
	}
	number = buf; /* (nega = false ? buf : -buf) */
	return number;
}

double readDouble(double& number)
{
	string d;
	getline(cin, d);
	double buf = 0;
	bool dot = false;

	int power = 0;

	for (int i = 0; i < d.size(); i++)
	{
		if (int(d[i]) == 46)
		{
			dot = true;
			continue;
		}
		else if (dot == true)
		{
			if (d[i] == '.')
			{
				resolveError(4);
				return 0;
			}
			else
			{
				power++;
			}
		}
		else if ((int(d[i]) < 58) and (int(d[i]) > 47))
		{
			buf = buf * 10 - '0' + d[i];
		}
		else 
		{
			if (int(d[i]) == 32)
			{
				resolveError(1);
				return 0;
			}
			if ((int(d[i]) > 64) and (int(d[i]) < 91))
			{
				resolveError(3);
				return 0;
			}
			else if (dot != true)
			{
				resolveError(2);
				return 0;
			}
		}
	}

	number = buf;
	for (int i = 0; i < power; i++) { number /= 10;  }

	return number;
}

void resolveError(int errorcode)
{
	string errorType1[13] = {"пробелы.", "символы.", "буквы.", "лишние точки."};

	cout << "Ошибка: ";

	if (errorcode != 5)
	{
		if (randomResponse() == 0)
		{
			errorTemplate(randomResponse());
		}
		else
		{
			errorTemplate(randomResponse());
		}
		cout << errorType1[errorcode - 1] << endl;
	}
	else
	{
		cout << "число не может начинаться с 0." << endl;
	}
}

int randomResponse() // notice: ничерта не рандомит
{
	int resp = rand() % 2;
	return resp;
}

void errorTemplate(int option)
{
	if (option == 0)
	{
		cout << "в записи числа не разрешается использовать ";
	}
	else
	{
		cout << "в записи числа присутствуют ";
	}
}