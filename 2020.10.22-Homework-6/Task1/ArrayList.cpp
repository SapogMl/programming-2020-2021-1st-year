#include "ArrayList.h"
#include<iostream>

using namespace std;

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	for (int i = 0; i < count; data[i] = list.data[i], i++) {}
	str = nullptr;
}

ArrayList::~ArrayList()
{
	clear();
}

void ArrayList::expand()
{
	int* newData = new int[capacity + 1];
	for (int i = 0; i < count; newData[i] = data[i], i++) {}
	capacity++;
	delete[] data;
	data = newData;
	delete[] newData;
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

void ArrayList::addToStr(int& index, char symbol)
{
	str[index] = symbol;
	index++;
}


void ArrayList::addToStr(int& index, int number)
{
	int nomL = (number < 0 ? (numLength(number) - 1) : numLength(number));

	if (nomL < numLength(number))
	{
		addToStr(index, '-');
		number = -number;
	}
	for (int i = index + nomL - 1; i >= index; i--)
	{
		str[i] = '0' + number % 10; // а как сделать так, чтобы нули тоже выводились?
		number /= 10;
	}
	index += nomL;
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	count++;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if ((index < 0) or (index >= count))
	{
		return false;
	}

	if (length() == capacity)
	{
		expand();
	}
	count++;
	for (int i = count; i > index; set(i, get(i - 1)), i--) {}
	set(index, element);

	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	for (int i = 0; i < list.length(); i++)
	{
		add(list.data[i]);
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	for (int i = 0; i < list.length(); i++)
	{
		add(index + i, list.data[i]);
	}
	return true;
}

void ArrayList::clear()
{
	delete[] data;
	delete[] str;
	count = 0;
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
		return false;
	}

	data[index] = element;
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
	int stringL = numLength(length()) + numLength(capacity) + 6 + 2 * (count - 1);

	for (int i = 0; i < count; i++)
	{
		stringL += numLength(data[i]);
	}

	str = new char[stringL];

	addToStr(index, '[');
	addToStr(index, count);
	addToStr(index, '/');
	addToStr(index, capacity);
	addToStr(index, ']');
	addToStr(index, ' ' );
	addToStr(index, '{');

	for (int i = 0; i < count; i++)
	{
		addToStr(index, data[i]);
		if (i == count - 1)
		{
			addToStr(index, '}');
		}
		else
		{
			addToStr(index, ',');
			addToStr(index, ' ');
		}
	}

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