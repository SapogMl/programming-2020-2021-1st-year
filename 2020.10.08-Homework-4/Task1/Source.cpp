#include<iostream>
#include<clocale>
#include<ctime>
#include"Header.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
}

void processChoice(Header& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		a.print();
		break;
	}
	break;
	case 2:
	{
		cout << "������� = ";
		int el = 0;
		cin >> el;
		a.add(el);
		break;
	}
	break;
	case 3:
	{
		cout << "������ = ";
		int index = 0;
		cin >> index;
		cout << "������� = ";
		int el = 0;
		cin >> el;
		a.addToIndex(index, el);
		break;
	}
	break;
	case 4:
	{
		cout << "������ = ";
		int index = 0;
		cin >> index;
		a.remove(index);
		break;
	}
	break;
	case 5:
	{
		cout << "������ ������� ��������� �������� � ������ ��� ������� �� ������� (1 / 2) ? ";
		int b = 0;
		cin >> b;

		if (b == 1)
		{
			cout << "������� = ";
			int el = 0;
			cin >> el;
			a.indexOf(el);
		}
		else
		{
			cout << "������ = ";
			int index = 0;
			cin >> index;
			a.get(index);
		}
		break;
	}
	break;
	case 6:
	{
		cout << "���������� ����� ��������� = ";
		int length = 0;
		cin >> length;
		a.addAll(length);
		break;
	}
	break;
	case 7:
	{
		cout << "���������� ����� ��������� = ";
		int length = 0;
		cin >> length;
		cout << "������ ������� = ";
		int index = 0;
		cin >> index;
		a.addAllToIndex(length, index);
		break;
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	Header a;

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}