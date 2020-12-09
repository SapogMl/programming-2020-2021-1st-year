#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;


void Options()
{
	cout << "1 - Добавить элемент в конец" << endl;
	cout << "2 - Добавить элемент по индексу" << endl;
	cout << "3 - Циклически сдвинуть массив на n элементов" << endl;
	cout << "4 - Проверить, может ли массив стать симметричным, если удалить из него элемент" << endl;
	cout << "5 - О массиве" << endl;
}

void processChoice(int choice, ArrayList& a)
{
	switch (choice)
	{
	case 1:
	{
		int el = 0;

		cout << "Элемент = ";
		cin >> el;
		a.add(el);
		break;
	}
	case 2:
	{
		int el = 0;
		int index = 0;

		cout << "Элемент = ";
		cin >> el;
		cout << "Индекс = ";
		cin >> index;
		a.add(index, el);
		break;
	}
	case 3:
	{
		int n = 0;
		cout << "n = ";
		cin >> n;

		int temp = 0;

		for (int j = 0; j < (n > 0 ? n : -n); j++)
		{
			temp = (n > 0 ? a.get(a.length() - 1) : a.get(0));
			if (n > 0)
			{
				for (int i = a.length() - 1; i > 0; i--)
				{
					a.set(i, a.get(i - 1));
				}
				a.set(0, temp);
			}
			if (n < 0)
			{
				for (int i = 0; i < a.length() - 1; i++)
				{
					a.set(i, a.get(i + 1));
				}
				a.set(a.length() - 1, temp);
			}
		}
		
		break;
	}
	case 4:
	{
		ArrayList cut;
		bool symm = true;
		
		for (int i = 0; i < a.length(); i++)
		{
			cut = a;
			cut.remove(i);
			for (int j = 0; j < cut.length() / 2; j++)
			{
				if (cut.get(j) != cut.get(cut.length() - 1 - j))
				{
					symm = false;
				}
			}
		}
		cout << (symm == true ? "Можно" : "Нельзя") << endl;
		break;
	}
	case 5:
	{
		cout << a.toString() << endl;

		bool symm = true;
		for (int i = 0; i < a.length() / 2; i++)
		{
			if (a.get(i) != a.get(a.length() - 1 - i))
			{
				symm = false;
				break;
			}
		}
		cout << "Массив симметричен: " << (symm == true ? "ДА" : "НЕТ") << endl;
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