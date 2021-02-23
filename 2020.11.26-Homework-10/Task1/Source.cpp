#include<iostream>
#include<clocale>
#include<ctime>
#include"Settings.h"

using namespace std;

void options()
{
	cout << "1-5 - ������� ������ ������ �� ����� (������������, ������������ ����� �������, � �������� �����, �������, ����������)" << endl;
	cout << "0 - �����" << endl;
}

void processChoice(int choice, int n)
{
	switch(choice)
	{
	case 1:
	{
		diagSymm(n);
		break;
	}
	case 2:
	{
		diagSymmBackwards(n);
		break;
	}
	case 3:
	{
		lines(n);
		break;
	}
	case 4:
	{
		oneToN(n);
		break;
	}
	case 5:
	{
		spiral(n);
		break;
	}
	break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "������ ������� = ";
	int n = 0;
	cin >> n;

	int choice = -1;

	do
	{
		system("cls");
		options();
		cin >> choice;
		processChoice(choice, n);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}