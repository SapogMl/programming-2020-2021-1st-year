#include <iostream>
using namespace std;

int Insert(int*& arr, int& capacity) {

	int n = 0;
	int a = 0;
	int b = 0;

	cin >> n;
	cin >> a;
	cin >> b;

	int newCapacity = capacity + 1;
	int* newArr = new int[newCapacity];
	for (int i = 0; i < capacity; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	capacity = newCapacity;
}


void printMenu() {

	system("cls");
	setlocale(LC_ALL, "Russian");

	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl; //yea
	cout << "1 - �������� � ������ n ��������� ����� � ���������� �� a �� b (n, a, b �������� � ����������)" << endl;
	cout << "2 - ���������� ������" << endl;
	cout << "3 - �������� �������� ������� ������� � �����. ���� ����� ��������� �������, ��������� ������� �������� �� ����� �����." << endl;
	cout << "4 - ����������� ����� ������ �� 1" << endl;
	cout << "5 - ���������� ��� ��������� �������. n - ������ ��������, ������������ ���������." << endl;
}


int main() {

	int choice = -1;
	int capacity = 5;
	int count = 0;
	int* arr = new int[capacity];

	system("cls"); 
	while (choice != 0) {

		printMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			
		}
		system("pause");
	}
	delete[] arr;
	return 0;
}