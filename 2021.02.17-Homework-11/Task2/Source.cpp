#include<cstdarg>
#include<iostream>
using namespace std;

double average(int n, ...) {
	double result = 0;
	int * ptr = &n + 1;
	for (int i = 0; i < n; i++)
	{
		result += *ptr;
		*ptr++;
	}
	return result / n;
}

int main() {
	cout << average(4, 0, 1, 2, 3);
	return EXIT_SUCCESS;
}

/* 
2. Реализовать функцию
double average(int n, ...)
считающую среднее арифметическое n чисел.
*/