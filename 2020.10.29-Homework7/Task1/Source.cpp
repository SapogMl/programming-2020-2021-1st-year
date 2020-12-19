#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;


/*
Вывод х
Добавление в конец х
Добавление в начало х 
Сложение списков х 
Удаление посл вхождения
Удаление начала
*/


void Options()
{
	cout << "1 - Добавить элемент в конец" << endl;
	cout << "2 - Добавить элемент в начало" << endl;
	cout << "3 - Сложить списки" << endl;
	cout << "4 - Удалить последнее вхождение элемента" << endl;
	cout << "5 - Удалить первый элемент" << endl;
	cout << "6 - Вывод" << endl;
}

void processChoice(int choice, ArrayList& a)
{
	switch (choice)
	{
	case 1:
	{
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		a += el;
		break;
	}
	case 2:
	{
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		a = el + a;
		break;
	}
	case 3:
	{
		a = a + a;
		break;
	}
	case 4:
	{
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		a -= el;
		break;
	}
	case 5:
	{
		a = 0 - a;
		break;
	}
	case 6:
	{
		cout << a << endl;
		break;
	}
	break;
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	ArrayList a;

	int choice = 0;

	do
	{
		system("cls");
		Options();
		cin >> choice;
		processChoice(choice, a);
		system("pause");
	} while (choice != 0);


	return EXIT_SUCCESS;
}