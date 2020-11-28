#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
    tail = head = nullptr;
    count = 0;

    Cell* temp = list.head;
    while (temp != nullptr)
    {
        addToTail(temp->data);
        temp = temp->next;
    }
}

LinkedList::~LinkedList()
{
    Cell* temp = head;
    while (temp != nullptr)
    {
        Cell* node = temp;
        temp = temp->next;
        delete node;
    }
}

bool LinkedList::indexValid(int index)
{
	if ((index < (count)) and (index >= 0))
	{
		return true;
	}
	return false;
}

int LinkedList::length()
{
    return count;
}

bool LinkedList::addToHead(int element)
{
    if (head == nullptr) 
    {
        head = tail = new Cell(element);
    }
    else
    {
        head = new Cell(element, head);
    }
    ++count;
    return true;
}

bool LinkedList::addToTail(int element)
{
    if (tail == nullptr)
    {
        head = tail = new Cell(element);
    }
    else
    {
        tail->next = new Cell(element);
        tail = tail->next;
    }
    ++count;
    return true;
}

bool LinkedList::add(int index, int element)
{
    if (index == 0)
    {
        return addToHead(element);
    }
    if (index == count)
    {
        return addToTail(element);
    }
    if (!indexValid(index))
    {
        return false;
    }

    Cell* temp = head;
    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
    }
    temp->next = new Cell(element, temp->next);
    ++count;

    return true;
}

int LinkedList::get(int index)
{
    if (!indexValid(index))
    {
        return -1;
    }
    if (index == 0)
    {
        return head->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }

    Cell* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

bool LinkedList::set(int element, int index)
{
    if (!indexValid(index))
    {
        return false;
    }
    if (index == 0)
    {
        head->data = element;
    }
    else if (index == count - 1)
    {
        tail->data = element;
    }
    else
    {
        Cell* temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        temp->data = element;
    }
    return true;
}

int& LinkedList::operator[](int index)
{
    if (head == nullptr)
    {
        addToHead(0);
        return head->data;
    }
    if (index <= 0)
    {
        return head->data;
    }
    if (index >= count)
    {
        addToTail(0);
        return tail->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }
    Cell* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

int& LinkedList::operator+=(int element)
{
    addToTail(element);
    return element;
}

int LinkedList::extractHead()
{
    Cell* head_temp = head;
    int head_data = head->data;
    head = head->next;
    delete head_temp;
    return head_data;
}

int LinkedList::extractTail()
{
    Cell* new_tail = head;
    for (int i = 0; i < count - 2; new_tail = new_tail->next, i++) {}
    int tail_data = tail->data;
    delete tail;
    tail = new_tail;
    return tail_data;
}

int LinkedList::extract(int index)
{
    if (!indexValid(index))
    {
        return -1;
    }
    if (head == nullptr)
    {
        delete[] head;
        head = NULL;
        return index;
    }

    Cell* pointer = head;
    for (int i = 0; i < index; pointer = pointer->next, i++) {}

    if (index == count) 
    {
        extractTail(); 
        return count;
    }
    if (index == 0) 
    { 
        extractHead(); 
        return 0;
    }

    for (int i = index; i < count - 1; i++)
    {
        pointer->data = pointer->next->data;
        pointer = pointer->next;
    }
    extractTail();

    return index;
}

void LinkedList::operator-=(int index)
{
    if (indexValid(index) == true)
    {
        extract(index);
    }
}

LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if (&list != this)
    {
        if (head != nullptr)
        {
            while (head != nullptr)
            {
                extractHead();
            }
        }
        count = list.count;
        head = NULL;
        for (int i = 0; i < count; add(i, get(i)), ++i);
    }
    return *this;
}

int LinkedList::indexOf(int element)
{
    Cell* temp = head;
    
    for (int i = 0; i < count; i++)
    {
        if (get(i) == element)
        {
            return i;
        }
    }
    return -1;
}

bool LinkedList::contains(int element)
{
    return (indexOf(element) == -1 ? true : false);
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
    stream << "[" << list.count << "]{";
    if (list.head == nullptr)
    {
        stream << "EMPTY";
    }
    else
    {
        Cell* temp = list.head;
        while (temp != nullptr)
        {
            stream << temp->data;
            if (temp->next != nullptr)
            {
                stream << ", ";
            }
            temp = temp->next;
        }
    }
    stream << "}";

    return stream;
}
