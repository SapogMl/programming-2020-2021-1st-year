#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void Menu()
{
	cout << "0 � �����" << endl;
	cout << "1 � �������� � ������ 10 (��. �����������) ��������� ������������� ���������� �����" << endl;
	cout << "2 � �������� � ������ 10 ��������� ������������� ���������� �����" << endl;
	cout << "3 � �������� ������� ������ ����������� � ��������� ������������ �������" << endl;
	cout << "4 � ���������� ��� �������� �������" << endl;
	cout << "((��. �����������)) 5 � �������� ������ ������������� ������� ������� �� 0" << endl; // ��� ��� �� ��������, �� �� ������� ���� �� � ����� ����. ��������� ���-�� �����?
	cout << "6 � ������� ������" << endl;
}

void UserChoice(ArrayList& s, int choice)
{
	switch (choice)
	{
	case 1:
	{
		ArrayList randlist;

		int list_el = 0;
		for (int i = 0; i < 5; i++)
		{
			list_el = rand() % 100;
			randlist.add(list_el > 9 ? list_el : list_el + 10);
		}
		
		if (!s.isEmpty())
		{
			int index = 0;
			cout << "������ = ";
			cin >> index;
			s.addAll(index, randlist);
		}
		else
		{
			s.addAll(randlist);
		}
		break;
	}
	case 2:
	{
		ArrayList randlist;

		int list_el = 0;
		for (int i = 0; i < 5; i++)
		{
			list_el = rand() % 100;
			randlist.add(list_el > 9 ? -(list_el) : -(list_el + 10));
		}

		if (!s.isEmpty())
		{
			int index = 0;
			cout << "������ = ";
			cin >> index;
			s.addAll(index, randlist);
		}
		else
		{
			s.addAll(randlist);
		}
		break;
	}
	case 3:
	{
		int index_min = s.length() - 1;
		int index_max = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s.get(index_max) < s.get(i))
			{
				index_max = i;
				cout << index_max << " max" << endl;
			}
			if (s.get(index_min) > s.get(s.length() - i - 1))
			{
				index_min = s.length() - i - 1;
				cout << index_min << " min" << endl;;
			}
		}
		s.swap(index_max, index_min);

		break;
	}
	case 4:
	{
		for (int i = 0; i < s.length(); i++)
		{
			s.swap(rand() % (s.length() - 1), rand() % (s.length() - 1));
		}
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
		break;
	}
	case 6:
	{
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