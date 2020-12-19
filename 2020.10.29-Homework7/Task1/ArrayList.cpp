#include "ArrayList.h"

ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	capacity = list.capacity;
	data = new int[capacity] { 0 };
	for (int i = 0; i < count; ++i) { data[i] = list.data[i]; }
}

ArrayList::~ArrayList()
{
	clear();
}

void ArrayList::expand()
{
	int* newData = new int[capacity * 2];
	for (int i = 0; i < capacity; i++) { newData[i] = data[i]; }
	delete[] data;
	data = newData;
	capacity *= 2;
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
	if ((index < 0) or (index > count - 1))
	{
		return false;
	}
	if (count == capacity)
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
	if ((index < 0) or (index > count - 1))
	{
		return false;
	}

	for (int i = 0; i < list.length(); i++)
	{
		add(index + i, list.data[i]);
	}
	return true;
}

void ArrayList::clear()
{
	delete[] data;
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
	if ((index < 0) or (index > count - 1))
	{
		return false;
	}

	return data[index];
}

bool ArrayList::set(int index, int element)
{
	if ((index < 0) or (index > count - 1))
	{
		return false;
	}

	data[index] = element;
	return true;
}

int ArrayList::indexOf(int element)
{
	for (int i = length() - 1; i > -1; i--)
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

bool ArrayList::remove(int index)
{
	if ((index < 0) or (index > count - 1))
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
	if ((index1 < 0) or (index1 > count - 1) or (index2 < 0) or (index2 > count - 1))
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

void ArrayList::operator+=(int item)
{
	add(item);
}

void ArrayList::operator-=(int item)
{
	if (contains(item))
	{
		remove(indexOf(item));
	}
}

ArrayList& ArrayList::operator=(const ArrayList& list)
{
	capacity = list.capacity;
	count = list.count;
	data = new int[capacity] { 0 };
	for (int i = 0; i < count; i++) { data[i] = list.data[i]; }

	return *this;
}

ArrayList operator+(const ArrayList& list, int item)
{
	ArrayList final;
	final.capacity = list.capacity;
	final.count = list.count;
	final.data = new int[final.capacity]{ 0 };
	for (int i = 0; i < final.count; i++) { final.data[i] = list.data[i]; }
	final.add(item);
	return final;
}

ArrayList operator+(int item, const ArrayList& list)
{
	ArrayList final;
	final.capacity = list.capacity;
	final.count = list.count;
	final.data = new int[final.capacity]{ 0 };
	for (int i = 0; i < final.count; i++) { final.data[i] = list.data[i]; }
	final.add(0, item);
	return final;
}

ArrayList operator+(const ArrayList& list1, const ArrayList& list2)
{
	ArrayList final;
	final.capacity = list1.capacity + list2.capacity;
	final.count = list1.count + list2.count;
	final.data = new int[final.capacity]{ 0 };
	for (int i = 0; i < list2.count; i++) { final.data[i] = list2.data[i]; }
	for (int i = 0; i < list1.count; i++) { final.data[i + list2.count] = list1.data[i]; }
	return final;
}

ArrayList operator-(const ArrayList& list, int item)
{
	ArrayList final;
	final.capacity = list.capacity;
	final.count = list.count;
	final.data = new int[final.capacity]{ 0 };
	for (int i = 0; i < final.count; i++) { final.data[i] = list.data[i]; }
	final.remove(final.indexOf(item));
	return final;
}

ArrayList operator-(int item, const ArrayList& list)
{
	ArrayList final;
	final.capacity = list.capacity;
	final.count = list.count;
	final.data = new int[final.capacity]{ 0 };
	for (int i = 0; i < final.count; i++) { final.data[i] = list.data[i]; }
	final.remove(0);
	return final;
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	for (int i = 0; i < list.count; ++i)
	{
		stream << list.data[i] << " ";
	}
	return stream;
}
