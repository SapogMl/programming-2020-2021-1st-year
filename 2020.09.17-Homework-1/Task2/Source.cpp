#include <iostream>
using namespace std;

void Instructions() {
	cout << "Input order: a; b; 1 - sum, 2 - subtract, 3 - multiply" << endl;
}

int main() {

	system("cls");
	Instructions();

	int chastnoe = 0;
	int a = 0;
	int b = 0;
	cin >> a; // �������
	cin >> b; // ��������

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1: //��������
	{
		int i = b;
		while (b <= a) {
			b += i;
			chastnoe += 1;
		}
		cout << chastnoe;
		break;
	}

	case 2: //���������
	{
		while (a >= b) {
			a -= b;
			chastnoe += 1;
		}
		cout << chastnoe;
		break;
	}

	case 3: //���������
	{
		int i = b;
		while (i <= a - b) {
			chastnoe += 1;
			i = b * chastnoe;
		}
		cout << chastnoe;
		break;
	}


	}

	return 0;
}