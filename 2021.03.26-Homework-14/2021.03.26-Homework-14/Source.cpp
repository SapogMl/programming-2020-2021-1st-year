/*

������� ������������ ������, ��������� ��� ���������� �������, ������������� ��� ����� �������� �������� : �������, �������, �����.
������ ���������� ��������� �� 1000 ��� � ������� ������� ���������� ��������� � ������� ���������� ������������ ��� ������ �� ����������.
�������� ���������� ��� �������� ������ 5, 10, 15 � 20.
�������� ����������� ���������� ������� ������� ������ ������� �� ����������� � �� ��������(����� ��� �������� ������������ �������� ���������� ��������� � ���������� ������������).

�������
�������� �������
x ���������� ���������� �������
x ���������� ���������
���������� ��������
x ���������� �������
������� ���������� ���������
������� ���������� ������������
x ���������� �� �����������
x ���������� �� ��������
x �����

*/

//��� ���������� �� �����������

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


void randomFill(int* array);
void printArray(int* array);

int* createArray(int length);
void BubbleSort(int* array);
void InsertionSort(int* array);
void SelectionSort(int* array);

void ascendFill(int* array);
void descendFill(int* array);


int main() {
	srand(time(NULL));

	int length;
	cin >> length;

	int* array = createArray(length);

	randomFill(array);
	printArray(array);
	InsertionSort(array);
	printArray(array);

	delete[] array;

	return EXIT_SUCCESS;
}


void randomFill(int* array) {
	for (int i = 1; i < array[0]; i++) {
		array[i] = rand() % 100;
	}
}

void printArray(int* array) {
	for (int i = 1; i < array[0]; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int* createArray(int length)
{
	int* array = new int[length + 1];
	array[0] = length + 1;
	return array;
}

void BubbleSort(int * array) {
	bool flag = true;
	int t;
	while (flag == true) {
		flag = false;
		for (int i = 1; i < array[0] - 1; i++) {
			if (array[i] > array[i + 1]) {
				t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
				flag = true;
			}
		}
	}
}

void InsertionSort(int * array) {
	int j, edge;
	for (int i = 3; i < array[0]; i++) {
		j = i;
		edge = array[i];
		while ((j > 1) && (array[j - 1] > edge)){
			array[j] = array[j - 1];
			j--;
		}
		array[j] = edge;
	}
}

void SelectionSort(int* array) {
	int min;
	int t;
	for (int i = 1; i < array[0]; i++) {
		min = i;
		for (int j = i; j < array[0]; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		t = array[i];
		array[i] = array[min];
		array[min] = t;
	}
}

void ascendFill(int* array) {
	for (int i = 1; i < array[0]; i++) {
		array[i] = i;
	}
}

void descendFill(int* array) {
	for (int i = 1; i < array[0]; i++) {
		array[i] = array[0] - i;
	}
}