#include<iostream>
#include "Header.h"

Header::Header()
{
	count = 0;
	capacity = 10;
	data = new int[10];
	list = new int[10];
}

Header::~Header()
{
	delete[] data;
	delete[] list;
}

void Header::expand()
{
	int* temp = new int[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	capacity *= 2;
}

bool Header::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	count++;
	return true;
}

bool Header::add(int index, int element)
{
	if (index > count)
	{
		return false;
	}
	else
	{
		if (count == capacity)
		{
			expand();
		}
		count++;

		for (int i = count; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = element;

		return true;
	}
}

bool Header::addAll(int caplist)
{
	if ((caplist + count) < capacity)
	{
		expand();
	}
	cout << "Ёлементы: ";
	for (int i = 0; i < caplist; i++)
	{
		cin >> list[i];
		add(list[i]);
	}
	clear(list, caplist);
	return true;
}


bool Header::addAll(int caplist, int index)
{
	if (index > count)
	{
		return false;
	}
	else
	{
	if (capacity < (caplist + index))
	{
		expand();
	}
	count = count + caplist;
	for (int i = count; i > index; i--)
	{
		data[i] = data[i - caplist];
	}
	cout << "Ёлементы: ";
	for (int k = 0; k < caplist; k++)
	{
		cin >> list[k];
		data[index + k] = list[k];
	}
	clear(list, caplist);
	return true;
	}
}

void Header::clear(int* mas, int count)
{
	for (int i = 0; i < count; i++)
	{
		mas[i] = 0;
	}
	count = 0;
}

bool Header::contains(int element)
{
	int i = 0;
	while ((i < count) and (data[i] != element))
	{
		i++;
	}
	if (i == count)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Header::get(int index)
{
	if (contains(data[index]) == true)
	{
		cout << "»скомый элемент = " << data[index] << endl;
		return data[index];
	}
	else
	{
		cout << "Ёлемент не найден";
		return -1;
	}
}

int Header::indexOf(int element)
{
	if (contains(element) == true)
	{
		int i = 0;
		while ((i < count) and (element != data[i]))
			{
				i++;
			}
		cout << "»ндекс искомого элемента = " << i << endl;
		return i;
	}
	else
	{
		cout << "Ёлемент не найден" << endl;
		return -1;
	}
}

bool Header::isEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Header::print()
{
	printf("[%d/%d]{", count, capacity);
	for (int i = 0; i < count; ++i)
	{
		printf("%d%s", data[i], (i == count - 1 ? "" : ", "));
	}
	printf("}\n");
}

bool Header::remove(int index)
{
	if (index >= count)
	{
		return false;
	}
	else
	{
		for (int i = index; i < count - 1; i++)
		{
			data[i] = data[i + 1];
		}
		data[count - 1] = 0;
		count--;
			return true;
	}
}

int Header::swap(int index1, int index2)
{
	if ((index1 >= count) or (index2 >= count))
	{
		return false;
	}
	else
	{
		int t = data[index1];
		data[index1] = data[index2];
		data[index2] = t;
		return true;
	}
}
