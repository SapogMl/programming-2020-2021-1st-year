#include <iostream> 
#include <string>
#include <clocale>
#include "Add.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long n1 = 0;
	double n2 = 0.0;
	bool pass = false;

	do
	{
		cout << "������� ����� ������������� �����: ";
		if (readInt(n1) != 0) { pass = true;  }
	} while (pass == false);

	pass = false;

	cout << "";
	do
	{
		cout << "������� ����� ��� ������� ������������� �����: ";
		if (readDouble(n2) != 0) { pass = true; }
	} while (pass == false);

	cout << n1 << " + " << n2 << " = " << n1 + n2;
	return 0;
}

// TODO: �� �������� ��� ������������� �����
