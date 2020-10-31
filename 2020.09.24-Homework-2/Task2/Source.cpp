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

	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl; //yea
	cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b (n, a, b вводится с клавиатуры)" << endl;
	cout << "2 - Развернуть массив" << endl;
	cout << "3 - Поменять элементы массива местами в парах. Если число элементов нечетно, последний элемент остается на своем месте." << endl;
	cout << "4 - Циклический сдвиг вправо на 1" << endl;
	cout << "5 - Развернуть две половинки массива. n - индекс элемента, разделяющего половинки." << endl;
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