/*

Создать динамический массив, заполнить его случайными числами, отсортировать его тремя базовыми методами : пузырек, вставки, выбор.
Каждую сортировку выполнить по 1000 раз и вывести среднее количество сравнений и среднее количество перестановок для каждой из сортировок.
Сравнить результаты для массивов длиной 5, 10, 15 и 20.
Добавить возможность заполнения массива идущими подряд числами по возрастанию и по убыванию(важно для проверки правильности подсчета количества сравнений и количества перестановок).

ЧЕКЛИСТ
x создание массива
x заполнение случайными числами
x сортировка пузырьком
x сортировка вставкой
x сортировка выбором
x среднее количество сравнений
x среднее количество перестановок
x заполнение по возрастанию
x заполнение по убыванию
x вывод

*/

//все сортировки по возрастанию

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


void randomFill(int* array);
void printArray(int* array);

int* createArray(int length);
void BubbleSort(int* array, int* cmpm);
void InsertionSort(int* array, int* cmpm);
void SelectionSort(int* array, int* cmpm);

void ascendFill(int* array);
void descendFill(int* array);


int main() {
	srand(time(NULL));

	int cm_average;
	int pm_average;
	
	cout << "Bubble Sort:" << '\n';
	for (int j = 1; j < 5; j++) {
		cm_average = 0;
		pm_average = 0;
		cout << "array length = " << 5 * j;
		for (int i = 0; i < 1000; i++) {
			int* array = createArray(j * 5);
			int* cmpm = new int[2];
			cmpm[0] = 0;
			cmpm[1] = 0;
			randomFill(array);
			BubbleSort(array, cmpm);
			cm_average += cmpm[0];
			pm_average += cmpm[1];
			delete[] array;
			delete[] cmpm;
		}
		cout << ", avg. comparisons = " << cm_average / 1000 << ", avg. permutations = " << pm_average / 1000 << endl;
	}

	cout << '\n';

	cout << "Insertion Sort:" << '\n';
	for (int j = 1; j < 5; j++) {
		cm_average = 0;
		pm_average = 0;
		cout << "array length = " << 5 * j;
		for (int i = 0; i < 1000; i++) {
			int* array = createArray(j * 5);
			int* cmpm = new int[2];
			cmpm[0] = 0;
			cmpm[1] = 0;
			// randomFill(array);
			descendFill(array);
			InsertionSort(array, cmpm);
			cm_average += cmpm[0];
			pm_average += cmpm[1];
			delete[] array;
			delete[] cmpm;
		}
		cout << ", avg. comparisons = " << cm_average / 1000 << ", avg. permutations = " << pm_average / 1000 << endl;
	}

	cout << '\n';

	cout << "Selection Sort:" << '\n';
	for (int j = 1; j < 5; j++) {
		cm_average = 0;
		pm_average = 0;
		cout << "array length = " << 5 * j;
		for (int i = 0; i < 1000; i++) {
			int* array = createArray(j * 5);
			int* cmpm = new int[2];
			cmpm[0] = 0;
			cmpm[1] = 0;
			randomFill(array);
			SelectionSort(array, cmpm);
			cm_average += cmpm[0];
			pm_average += cmpm[1];
			delete[] array;
			delete[] cmpm;
		}
		cout << ", avg. comparisons = " << cm_average / 1000 << ", avg. permutations = " << pm_average / 1000 << endl;
	}

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

void BubbleSort(int * array, int* cmpm) {
	bool flag = true;
	int t;
	while (flag == true) {
		flag = false;
		for (int i = 1; i < array[0] - 1; i++) {
			cmpm[0]++;
			if (array[i] > array[i + 1]) {
				t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
				flag = true;
				cmpm[1]++;
			}
		}
	}
}

void InsertionSort(int * array, int* cmpm) {
	int j, edge;
	for (int i = 3; i < array[0]; i++) {
		j = i;
		edge = array[i];
		cmpm[0]++;
		while ((j > 1) && (array[j - 1] > edge)){
			array[j] = array[j - 1];
			j--;
			cmpm[1]++;
		}
		array[j] = edge;
		cmpm[1]++;
	}
}

void SelectionSort(int* array, int* cmpm) {
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