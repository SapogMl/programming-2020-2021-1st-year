#include<iostream>
#include "ArrayList.h"
using namespace std;

/*
- добавить элемент, введенный с клавиатуры;
- вывести массив;
- проверить, является ли массив симметричным;
- циклически сдвинуть массив на n элементов. n>0 - сдвиг вправо, n<0 - сдвиг влево;
- проверить, может ли массив стать симметричным, если из него удалить один элемент.
*/

int main(int argc, char* argv[])
{
	ArrayList core;

	for (int i = 0; i < 10; core.add(i), i++) {}
	cout << core.toString();

	return EXIT_SUCCESS;
}