#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void Menu()
{
	cout << "0 Ч ¬ыход" << endl;
	cout << "х 1 Ч ƒобавить в список 10 случайных положительных двузначных чисел (по индексу) - см. комментарии" << endl; 
	// при выводе в конце строки образуютс€ рандомные символы, которых в рамках вместимости str там быть не может
	// в (неизвестной) зависимости от того, что генерируетс€, код крашитс€ после 3-4 добавлений без видимой закономерности и с непон€тными ошибками

	cout << "2 Ч ƒобавить в список 10 случайных отрицательных двузначных чисел (в конец)" << endl;
	cout << "3 Ч ѕомен€ть местами первый минимальный и последний максимальный элемент" << endl;
	cout << "4 Ч ѕеремешать все элементы массива" << endl;
	cout << "5 Ч «аменить каждый отрицательный элемент массива на 0" << endl;
	cout << "6 Ч ¬ывести массив" << endl;
}

void UserChoice(ArrayList& s, int choice)
{
	switch (choice)
	{
	case 1:
	{
		ArrayList list;
		int a = 0;

		int index = 0;
		cout << "»ндекс = ";
		cin >> index;

		for (int i = 0; i < 10; i++)
		{
			a = rand() % 100;
			list.add(a > 9 ? a : a + 10);
		}
		s.addAll(index, list);
		cout << s.toString() << endl;
		break;
	}
	case 2:
	{
		ArrayList list;
		int a = 0;

		for (int i = 0; i < 10; i++)
		{
			a = -(rand() % 100);
			list.add(a < -9 ? a : a - 10);
		}
		s.addAll(list);
		cout << s.toString() << endl;
		break;
	}
	case 3:
	{
		int max = s.length();
		int min = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s.get(s.length() - i) > s.get(max))
			{
				max = s.length() - i;
			}
			if (s.get(i) < s.get(min))
			{
				min = i;
			}
		}

		s.swap(min, max);
		cout << s.toString() << endl;
		break;
	}
	case 4:
	{
		for (int i = 0; i < rand() % s.length(); i++)
		{
			s.swap(rand() % s.length(), rand() % s.length());
		}
		cout << s.toString() << endl;
		break;
	}
	case 5:
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s.get(i) < 0)
			{
				s.set(i, 0);
			}
		}
		cout << s.toString() << endl;
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	ArrayList s;

	int choice = 0;
	do
	{
		system("cls");
		Menu();
		cin >> choice;
		UserChoice(s, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}