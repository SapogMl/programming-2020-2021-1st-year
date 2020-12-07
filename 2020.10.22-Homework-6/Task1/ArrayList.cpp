#include "ArrayList.h"
#include<iostream>

using namespace std;

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.count;
	data = new int[count];
	for (int i = 0; i < count; data[i] = list.data[i], i++) {}
	str = nullptr;
}

ArrayList::~ArrayList()
{
	clear();
}

void ArrayList::addToStr(int& index, char symbol)
{
	str[index] = symbol;
	index++;
}


void ArrayList::addToStr(int& index, int number)
{
	if (number < 0)
	{
		addToStr(index, '-');
	}
	for (int i = index; i < (number < 0 ? index + numLength(number) - 1 : index + numLength(number)); i++)
	{
		str[i] = number % 10;
		number /= 10;
	}
	index += numLength(number);
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	count++;
	set(count - 1, element);
	return true;
}

bool ArrayList::add(int index, int element)
{
	if ((index < 0) or (index >= count))
	{
		return false;
	}
	if (index == count - 1)
	{
		add(element);
		return true;
	}

	if (length() == capacity)
	{
		expand();
	}
	count++;
	for (int i = index; i < count - 1; set(i + 1, get(i)), i++) {}
	set(index, element);

	return true;
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < length(); i++)
	{
		if (data[i] == element)
		{
			return i;
		}
	}

	return -1;
}

bool ArrayList::isEmpty()
{
	if (length() == 0)
	{
		return true;
	}
	return false;
}

char* ArrayList::toString()
{
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}

	int index = 0;
	int stringL = numLength(length()) + numLength(capacity) + 3;
	str = new char[stringL];

	addToStr(index, '[');
	addToStr(index, count);
	addToStr(index, '/');
	addToStr(index, capacity);
	addToStr(index, ']');

	return str;
}

bool ArrayList::remove(int index)
{
	if ((index < 0) or (index >= length()))
	{
		return false;
	}

	for (int i = index; i < length() - 1; i++)
	{
		data[i] = data[i + 1];
	}
	count--;

	return true;
}

bool ArrayList::swap(int index1, int index2)
{
	if ((index1 < 0) or (index2 < 0) or (index1 >= length()) or (index2 >= length()))
	{
		return false;
	}

	int buf = get(index1);
	set(index1, get(index2));
	set(index2, buf);

	return true;

}

int ArrayList::length()
{
	return count;
}

void ArrayList::clear()
{
	if (data != nullptr)
	{ 
		delete[] data;
		data == nullptr;
		count = 0;
	}
}

bool ArrayList::contains(int element)
{
	for (int i = 0; i < length(); i++)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index)
{
	if ((index < 0) or (index >= length()))
	{
		return -1;
	}

	return data[index];
}

bool ArrayList::set(int index, int element)
{
	if ((index < 0) or (index >= length()))
	{
		return -1;
	}

	data[index] = element;
	return true;
}

void ArrayList::expand()
{
	int* newData = new int[capacity + 1];
	for (int i = 0; i < capacity; newData[i] = data[i], i++) {}
	capacity++;
	delete[] data;
	data = newData;
	delete[] newData; // а надо?
}

int ArrayList::numLength(int number)
{
	if (number < 0)
	{
		return numLength(-number) + 1;
	}

	int counter = 0;
	while (number > 0)
	{
		number /= 10;
		counter++;
	}

	return counter;
}