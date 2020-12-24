#include<iostream>
#include<clocale>
#include<ctime>
#include"Settings.h"

using namespace std;

void options()
{
	cout << "1-5 - ¬ывести массив одного из типов (диагональный, диагональный задом наперед, с повтором строк, угловой, спиральный)" << endl;
	cout << "0 - ¬ыход" << endl;
}

void processChoice(int choice, int n)
{
	int dim = n;
	switch(choice)
	{
	case 1:
	{
		diagSymm(dim);
		break;
	}
	case 2:
	{
		diagSymmBackwards(dim);
		break;
	}
	case 3:
	{
		lines(dim);
		break;
	}
	case 4:
	{
		oneToN(dim);
		break;
	}
	case 5:
	{
		spiral(dim);
		break;
	}
	break;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "–азмер массива = ";
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

	// diagSymm(n);
	// diagSymmBackwards(n);
	// lines(n);
	// oneToN(n);
	// spiral(n);

	return EXIT_SUCCESS;
}