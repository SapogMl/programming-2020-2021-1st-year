/*продемонстрировать работу всех функций
показать, что все функции и операторы корректно работают:
1). С пустым списком.
2). Со списком из 1 элемента.
3). Со списком из нескольких элементов.
*/

#include<iostream>
#include"LinkedList.h"

using namespace std;



int main()
{
	
	LinkedList list;

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	list[3] += 4; // оператор +=


	cout << list << endl;
	list -= 0;
	cout << list << endl;

	return EXIT_SUCCESS;

}