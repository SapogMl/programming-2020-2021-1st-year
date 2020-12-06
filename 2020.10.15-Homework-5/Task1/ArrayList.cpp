#include "ArrayList.h"
#include<iostream>

using namespace std;

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.count;
	data = new int[count];
	for (int i = 0; i < count; data[i] = list.data[i], ++i);
	str = nullptr;
}

ArrayList::~ArrayList()
{
	clear();
}

void ArrayList::expand(int deltaL)
{
	int newCap = capacity + (deltaL < 1 ? capacity : deltaL);
	int* newData = new int[newCap];
	for (int i = 0; i < capacity; newData[i] = data[i], i++);
	capacity = newCap;
	delete[] data;
	data = newData;
}

int ArrayList::numLength(int number)
{
	if (number < 0)
	{
		return 1 + numLength(-number);
	}

	int result = 1;
	while (number > 9)
	{
		result++;
		number /= 10;
	}
	return result;
}

void ArrayList::addSymbolToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int& index, int number)
{
	int length = numLength(number);
	
	if (number < 0)
	{
		addSymbolToStr(index, '-');
		addNumberToStr(index, -number);
	}
	else
	{
		for (int i = 0; i < length; ++i)
		{
			int digit = number % 10;
			str[index + length - 1 - i] = '0' + digit;
			number /= 10;
		}

		index += length;
	}
}

bool ArrayList::isValid(int index)
{
	return (index < count) && (index > -1);
}

bool ArrayList::add(int element)
{
	if (capacity = count)
	{
		expand(1);
	}
	count++;
	set(count - 1, element);
	return true;
}

bool ArrayList::add(int index, int element)
{
	if ((index == count - 1) or ((count == 0) and (index == 0)))
	{
		add(element);
		return true;
	}
	if (!isValid(index))
	{
		return false;
	}
	if (capacity == count)
	{
		expand(1);
	}

	count++;
	for (int i = 0; i < count - index; i++)
	{
		set(count - 1 - i, get(count - 2 - i));
	}
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
	if ((index == count - 1) or ((count == 0) and (index == 0)))
	{
		addAll(list);
		return true;
	}
	if (!isValid(index))
	{
		return false;
	}

	for (int i = 0; i < list.length(); i++)
	{
		add(i + index, list.get(i));
	}
	return true;
}

void ArrayList::clear()
{
	if (data != nullptr)
	{
		delete[] data;
		data = new int[10];
		capacity = 10;
	}
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	count = 0;
}

bool ArrayList::contains(int element)
{
	for (int i = 0; i < count; i++)
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
	if (!isValid(index))
	{
		return -1;
	}

	return data[index];
}

bool ArrayList::set(int index, int element)
{
	if (!isValid(index))
	{
		return false;
	}
	data[index] = element;
	return true;
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; i++)
	{
		if (element == get(i))
		{
			return i;
		}
	}
}

bool ArrayList::isEmpty()
{
	if (count > 0)
	{
		return false;
	}
	return true;
}

char* ArrayList::toString()
{
	str = nullptr;

	int lineLength = 6 + numLength(length()) + numLength(capacity);

	for (int i = 0; i < length(); i++)
	{
		lineLength += numLength(get(i));
	}

	int index = 0;
	str = new char[lineLength];

	addSymbolToStr(index, '[');
	addNumberToStr(index, length());
	addSymbolToStr(index, '/');
	addNumberToStr(index, capacity);
	addSymbolToStr(index, ']');
	addSymbolToStr(index, ' ');
	addSymbolToStr(index, '{');

	if (length() != 0)
	{
		lineLength += 2 * (length() - 1);
	}
	
	for (int i = 0; i < length(); i++)
	{
		addNumberToStr(index, data[i]);
		if (i != length() - 1)
			{
			addSymbolToStr(index, ',');
			addSymbolToStr(index, ' ');
		}
	}

	addSymbolToStr(index, '}');
	return str;
}

bool ArrayList::remove(int index)
{
	if (!isValid(index))
	{
		return false;
	}

	for (int i = 0; i < count - index - 1; i++)
	{
		data[i] = data[i + 1];
	}
	count--;

	return true;
}

bool ArrayList::swap(int index1, int index2)
{
	if ((!isValid(index1)) or (!isValid(index2)))
	{
		return false;
	}

	int t = get(index1);
	set(index1, get(index2));
	set(index2, t);
	return true;
}

int ArrayList::length()
{
	return count;
}