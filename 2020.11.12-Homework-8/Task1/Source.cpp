/*
ПРОБЛЕМА: ввод списка из 3-х элементов -> удаление элемента с индексом 1 -> если после этого попытаться вывести список, возникает проблема с указателями 

Видимо, это несогласование того, что знает о себе LinkedList и того, что требует
от него оператор <<, но мне пока не удалось понять, где они разошлись :^/
Поищу, но была бы благодарна подсказке, если она у вас навскидку найдется.

Вероятно, ноги у этого добра растут из extractTail и конструктор LinkedList хочет 
сказать нам, что после удаления хвоста он не знает никакого data->next.

Вывод списка и добавление в него элементов сами по себе работаю корректно (по 
крайней мере, пока не сломались). 
*/

#include<iostream>
#include<clocale>
#include<ctime>
#include"LinkedList.h"
using namespace std;

void Menu()
{
	cout << "1 - Вывести список" << endl; 
	cout << "2 - Добавить элемент" << endl; 
	cout << "3 - Удалить элемент" << endl; 
}

void UserChoice(LinkedList& list, int choice)
{
	switch (choice)
	{
	case 1:
	{
		cout << list << endl;
		break;
	}
	case 2:
	{
		int el = 0;
		cout << "Элемент = ";
		cin >> el;
		list += el;
		break;
	}
	case 3:
	{
		int i = 0;
		cout << "Индекс = ";
		cin >> i;
		list -= i;
		break;
	}
	break;
	}

}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	LinkedList list;

	int choice = 0;
	do
	{
		system("cls");
		Menu();
		cin >> choice;
		UserChoice(list, choice);
		system("pause");
	} while (choice != 0);

	

	return EXIT_SUCCESS;

}