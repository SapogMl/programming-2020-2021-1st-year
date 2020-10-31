#include<iostream>
#include<clocale>
#include<ctime>
#include"Header.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Вывести массив на экран" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Добавить элемент в позицию" << endl;
	cout << "4 - Удалить элемент по индексу" << endl;
	cout << "5 - Найти элемент" << endl;
	cout << "6 - Добавить несколько элементов" << endl;
	cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << endl;
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
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		a.add(el);
		break;
	}
	break;
	case 3:
	{
		cout << "Индекс = ";
		int index = 0;
		cin >> index;
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		a.addToIndex(index, el);
		break;
	}
	break;
	case 4:
	{
		cout << "Индекс = ";
		int index = 0;
		cin >> index;
		a.remove(index);
		break;
	}
	break;
	case 5:
	{
		cout << "Индекс первого вхождения элемента в массив или элемент по индексу (1 / 2) ? ";
		int b = 0;
		cin >> b;

		if (b == 1)
		{
			cout << "Элемент = ";
			int el = 0;
			cin >> el;
			a.indexOf(el);
		}
		else
		{
			cout << "Индекс = ";
			int index = 0;
			cin >> index;
			a.get(index);
		}
		break;
	}
	break;
	case 6:
	{
		cout << "Количество новых элементов = ";
		int length = 0;
		cin >> length;
		a.addAll(length);
		break;
	}
	break;
	case 7:
	{
		cout << "Количество новых элементов = ";
		int length = 0;
		cin >> length;
		cout << "Индекс вставки = ";
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