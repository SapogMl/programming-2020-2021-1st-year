/*
��������: ���� ������ �� 3-� ��������� -> �������� �������� � �������� 1 -> ���� ����� ����� ���������� ������� ������, ��������� �������� � ����������� 

������, ��� �������������� ����, ��� ����� � ���� LinkedList � ����, ��� �������
�� ���� �������� <<, �� ��� ���� �� ������� ������, ��� ��� ��������� :^/
�����, �� ���� �� ���������� ���������, ���� ��� � ��� ��������� ��������.

��������, ���� � ����� ����� ������ �� extractTail � ����������� LinkedList ����� 
������� ���, ��� ����� �������� ������ �� �� ����� �������� data->next.

����� ������ � ���������� � ���� ��������� ���� �� ���� ������� ��������� (�� 
������� ����, ���� �� ���������). 
*/

#include<iostream>
#include<clocale>
#include<ctime>
#include"LinkedList.h"
using namespace std;

void Menu()
{
	cout << "1 - ������� ������" << endl; 
	cout << "2 - �������� �������" << endl; 
	cout << "3 - ������� �������" << endl; 
}

void UserChoice(LinkedList& list, int choice)
{
	switch (choice)
	{
	case 1:
	{
		cout << list << endl;
		break;
	}
	case 2:
	{
		int el = 0;
		cout << "������� = ";
		cin >> el;
		list += el;
		break;
	}
	case 3:
	{
		int i = 0;
		cout << "������ = ";
		cin >> i;
		list -= i;
		break;
	}
	break;
	}

}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	LinkedList list;

	int choice = 0;
	do
	{
		system("cls");
		Menu();
		cin >> choice;
		UserChoice(list, choice);
		system("pause");
	} while (choice != 0);

	

	return EXIT_SUCCESS;

}