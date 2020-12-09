#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;


void Options()
{
	cout << "1 - �������� ������� � �����" << endl;
	cout << "2 - �������� ������� �� �������" << endl;
	cout << "3 - ���������� �������� ������ �� n ���������" << endl;
	cout << "4 - ���������, ����� �� ������ ����� ������������, ���� ������� �� ���� �������" << endl;
	cout << "5 - � �������" << endl;
}

void processChoice(int choice, ArrayList& a)
{
	switch (choice)
	{
	case 1:
	{
		int el = 0;

		cout << "������� = ";
		cin >> el;
		a.add(el);
		break;
	}
	case 2:
	{
		int el = 0;
		int index = 0;

		cout << "������� = ";
		cin >> el;
		cout << "������ = ";
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
		cout << (symm == true ? "�����" : "������") << endl;
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
		cout << "������ �����������: " << (symm == true ? "��" : "���") << endl;
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