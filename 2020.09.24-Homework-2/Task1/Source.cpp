#include<iostream>
using namespace std;


void ExpandArray(int*& arr, int& length) { //OK

	int newLength = length + 1;
	int* newArr = new int[newLength];
	for (int i = 0; i < length; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	length = newLength;
}




void AddToArray(int*& arr, int& count, int& length, int element) {  //OK
	
	if (count == length)
	{
		ExpandArray(arr, length);
	}
	arr[count] = element;
	count++;
}

void PrintArray(int*& arr, int length) { // OK

	for (int i = 0; i < length; i++) 
	{
		cout << arr[i] << " ";
	}
}

int MaxNumber(int* arr, int count) {

	int maxPos = arr[0];
	for (int i = 0; i < count; i++)
	{
		/* maxPos = (arr[i] > arr[maxPos]);
		* по какой-то причине работает некорректно */
		
		if (arr[maxPos] < arr[i])
		{
			maxPos = i;
		}
	}
	return maxPos;
}

int MinElement(int* arr, int count) { 

	int min = arr[0];
	for (int i = 0; i < count; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

int SumArray(int* arr, int length) { 
	
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum;
}

void Reverse(int* arr, int length) {

	for (int i = 0; i < length; i++) 
	{
		cout << arr[length - i - 1] << " ";
	}
}

void printMenu() {

	system("cls");
	setlocale(LC_ALL, "Russian");

	cout << "MENU" << endl;
	cout << "0 - Выход" << endl;
	cout << "1 - Добавить элемент в массив" << endl;
	cout << "2 - Вывести массив на экран" << endl;
	cout << "3 - Найти номер максимального элемента массива" << endl;
	cout << "4 - Найти минимальный элемент массива" << endl;
	cout << "5 - Посчитать сумму элементов массива" << endl;
	cout << "6 - Вывести массив в обратном порядке" << endl;


}

int main() {

	int choice = -1;
	int length = 5;
	int count = 0;
	int* arr = new int[length];

	system("cls"); // на множественное использование system VS огрызается, но, насколько я понимаю, ошибкой это, по сути, не является
	while (choice != 0) { 

		printMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int inputValue = 0;
			cin >> inputValue;
			AddToArray(arr, count, length, inputValue);
			break;
		}
		case 2:
		{
			PrintArray(arr, length);
			break;
		}
		case 3:
		{
			cout << MaxNumber(arr, count) << endl;
			break;
		}
		case 4:
		{
			cout << MinElement(arr, count) << endl;
			break;
		}
		case 5:
		{
			cout << SumArray(arr, length) << endl;
			break;
		}
		case 6:
		{
			Reverse(arr, length);
		}
		}
		system("pause");
	}
	delete[] arr;
	return 0;
}
