#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void Menu()
{
	cout << "0 � �����" << endl;
	cout << "� 1 � �������� � ������ 10 ��������� ������������� ���������� ����� (�� �������) - ��. �����������" << endl; 
	// ��� ������ � ����� ������ ���������� ��������� �������, ������� � ������ ����������� str ��� ���� �� �����
	// � (�����������) ����������� �� ����, ��� ������������, ��� �������� ����� 3-4 ���������� ��� ������� �������������� � � ����������� ��������

	cout << "2 � �������� � ������ 10 ��������� ������������� ���������� ����� (� �����)" << endl;
	cout << "3 � �������� ������� ������ ����������� � ��������� ������������ �������" << endl;
	cout << "4 � ���������� ��� �������� �������" << endl;
	cout << "5 � �������� ������ ������������� ������� ������� �� 0" << endl;
	cout << "6 � ������� ������" << endl;
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
		cout << "������ = ";
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