#include<iostream>
#include<clocale>
#include<ctime>

using namespace std;

void printMenu()
{
    cout << "МЕНЮ" << endl;
    cout << "0 - Выход из программы" << endl; 
    cout << "1 - Ввести несколько элементов с клавиатуры" << endl; 
    cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b (n, a, b вводится с клавиатуры)" << endl; 
    cout << "3 - Вывести массив на экран" << endl; 
    cout << "4 - Поиск индекса элемента" << endl;
    cout << "5 - Добавление массив к массиву" << endl;
    cout << "6 - Объединение массивов" << endl;
    cout << "7 - Вставка элемента в массив" << endl;
    cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
    cout << "9 - Поиск подпоследовательности" << endl;
}

int* initArray(int capacity = 10)
{
    int* result = new int[capacity + 2]{ 0 };

    *(result + 1) = capacity;
    result += 2;
    return result;
}

void deleteArray(int* arr)
{
    delete[](arr - 2);
}

void expandArray(int*& arr)
{
    int* temp = initArray(2 * (*(arr - 1)));

    for (int i = 0; i < *(arr - 1); ++i)
    {
        *(temp + i) = *(arr + i);
    }
    *(temp - 2) = *(arr - 2);
    deleteArray(arr);
    arr = temp;
}

void addElement(int*& arr, int element)
{
    if (*(arr - 2) == *(arr - 1))
    {
        expandArray(arr);
    }
    *(arr + *(arr - 2)) = element;
    ++(*(arr - 2));
}

void addRandomElements(int*& arr, int n, int min, int max)
{
    for (int i = 0; i < n; ++i)
    {
        addElement(arr, rand() % (max - min + 1) + min);
    }
}

void printArray(int* arr)
{
    cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "] {";
    for (int i = 0; i < *(arr - 2); ++i)
    {
        cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
    }
}

/// <summary>
/// Функция поиска первого вхождения элемента в массиве.
/// </summary>
/// <param name="arr">Массив с элементами</param>
/// <param name="element">Искомый элемент</param>
/// <param name="start">Место начала поиска</param>
/// <returns>индекс первого найденного элемента или -1, если элемент не найден</returns>
int search(int* arr, int element, int start = 0)
{
	int index = -1;
	int i = 0;

	while ((i < *(arr - 2)) and (index == -1))
	{
		if (element == *(arr + i))
		{
			index = i;
		}
		i++;
	}

	if (index == -1)
	{
		return -1;
	}
	else
	{
		cout << index << "\n";
	}
}

/// <summary>
/// Добавление массива элементов.
/// </summary>
/// <param name="arr">Массив, к которому добавляются элементы, расширяется только если не хватило места для элементов из добавляемого массива</param>
/// <param name="addedArr">Массив с добавляемыми элементами</param>
void add(int*& arr, int* addedArr)
{
	for (int i = 0; i < *(addedArr - 2); i++)
	{
		addElement(arr, *(addedArr + i));
	}
}

/// <summary>
/// Объединение двух массивов в один.
/// {a1, a2, a3, a4, a5} {b1, b2, b3, b4, b5, b6, b7, b8}
/// </summary>
/// <param name="a">Массив, элементы которого должны стоять на четных местах в результирующем массиве</param>
/// <param name="b">Массив, элементы которого должны стоять на нечетных местах в результирующем массиве</param>
/// <returns>
/// result[-1] = a[-2] + b[-2]
/// {a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, b6, b7, b8}
///</returns>
int* unify(int* arr1, int* arr2) /* многовато локального мусора, есть проблема с инициализированными нулями*/
{
	int* result = initArray();
	int a1 = 0; 
	int a2 = 0;
	int maximum = max(*(arr1 - 2), *(arr2 - 2));

	for (int i = 0; i < maximum; i++)
	{
		if (a1 < *(arr1 - 2)) 
		{
			addElement(result, *(arr1 + a1));
			a1++;
		}
		if (a2 < *(arr2 - 2))
		{
			addElement(result, *(arr2 + a2));
			a2++;
		}
	}

	printArray(result);
	return result - 1;

} 

/// <summary>
/// Извлечение элемента из массива. Все элементы, стоящие после него, должны быть сдвинуты на 1 влево.
/// </summary>
/// <param name="a">Массив с данными</param>
/// <param name="index">Индекс извлекаемого элемента</param>
/// <returns>элемент, стоявший под индексом index, если index был некорректен - вернуть -1</returns>
int extract(int* arr, int index)
{
	if (*(arr - 2) > index) 
	{
		for (int i = 0; i < *(arr - 2); i++)
		{
			*(arr + index + i) = *(arr + index + i + 1);
		}
		--(*(arr - 2));
		return index;
	}
	else 
	{
		return -1;
	}
}

/// <summary>
/// Вставка элемента в массив. У вставляемого элемента в итоге должен быть индекс index, все последующие элементы сдвигаются на 1 вправо.
/// </summary>
/// <param name="a">Модифицируемый массив</param>
/// <param name="index">Индекс вставленного элемента</param>
/// <param name="element">Значение элемента</param>
/// <returns>Возвращается 0, если все хорошо и индекс был корректен, 1 - если индес был некорректен</returns>
int insert(int*& arr, int index, int element)
{
	if (index < *(arr - 2))
	{
		addElement(arr, *(arr + *(arr - 2) - 1));

		for (int i = *(arr - 2); i > index; i--)
		{
			*(arr + i) = *(arr + i - 1);
		}
		*(arr + index) = element;

		return 0;
	}
	else
	{
		return -1;
	}
}

/// <summary>
/// Удалить последовательность элементов из массива
/// </summary>
/// <param name="a">Модифицируемый массив</param>
/// <param name="startIndex">Начало удаляемого куска</param>
/// <param name="count">Количество удаялемых элементов</param>
/// <returns>0, если все прошло хорошо, 1, если входные данные были некорректными</returns>
int deleteGroup(int* arr, int startIndex, int count)
{
	if ((*(arr + startIndex) < *(arr - 2)) and (*(arr + startIndex + count) < *(arr - 2)))
	{
		for (int i = 0; i < count - startIndex; i++)
			extract(arr, startIndex);
		return 0;
	}
	else
	{
		return 1;
	}
}

/// <summary>
/// Поиск подпоследовательности в массиве
/// </summary>
/// <param name="a">Массив, в котором ищем подпоследовательность</param>
/// <param name="b">Искомая подпоследовательность</param>
/// <returns>Индекс начала подпоследовательности или -1, если таковой нет</returns>
int subSequence(int* arr, int* b)
{
	int i = 0;
	int index = 0;

	while (i < (*(arr-2)) and (index < *(b - 2)))
	{ 
		if (arr[i] == b[index])
		{
			index++;
		}
		else
		{
			index = 0;
		}
		i++;
	}
	if (index == 0)
	{
		return -1;
	}
	else
	{
		cout << "Индекс = " << i - index << "\n";
	}
}


void processChoice(int*& arr1, int*& arr2, int choice)
{
	switch (choice)
	{
	case 1:
	{
		cout << "С каким массивом работаем (1 / 2) ? ";
		int a = 0;
		cin >> a;
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		addElement((a == 1 ? arr1 : arr2), el);
		break;
	}
	case 2:
	{
		cout << "С каким массивом работаем (1 / 2) ? ";
		int a = 0;
		cin >> a;
		cout << "Количество = ";
		int n = 0;
		cin >> n;
		cout << "Min = ";
		int min = 0;
		cin >> min;
		cout << "Max = ";
		int max = 0;
		cin >> max;
		addRandomElements((a == 1 ? arr1 : arr2), n, min, max);
		break;
	}
	case 3:
	{
		cout << "Какой массив вывести (1 / 2) ? ";
		int a = 0;
		cin >> a;
		printArray(a == 1 ? arr1 : arr2);
		break;
	}
	case 4:
	{
		cout << "В каком массиве ищем индекс (1 / 2) ? ";
		int a = 0;
		cin >> a;
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		search((a == 1 ? arr1 : arr2), el);
		break;
	}
	case 5:
	{
		int cap = 0;
		cout << "Длина добавляемого массива = ";
		cin >> cap;
		cout << "Элементы добавляемого массива: ";
		int* arr0 = initArray(cap);
		int el = 0;
		for (int i = 0; i < *(arr0 - 1); i++)
		{
			cin >> el;
			addElement(arr0, el);
		}

		cout << "К какому массиву добавляем введенный (1 / 2) ? ";
		int a = 0;
		cin >> a;
		add((a == 1 ? arr1 : arr2), arr0);
		break;
	}
	case 6:
	{
		int a = 0;
		cout << "Элементы какого массива (1 / 2) при объединении поставить на четных позициях? ";
		cin >> a;
		unify(arr1, arr2);
		break;
	}
	case 7: 
	{
		cout << "В каком массиве делаем вставку (1 / 2) ?";
		int a = 0;
		cin >> a;
		cout << "Индекс = ";
		int index = 0;
		cin >> index;
		cout << "Элемент = ";
		int el = 0;
		cin >> el;
		insert((a == 1 ? arr1 : arr2), index, el);
		break;
	}
	case 8:
	{
		cout << "Из какого массива удалить элементы (1 / 2) ? ";
		int a = 0;
		cin >> a;
		cout << "С какого элемента удаляем? ";
		int index = 0;
		cin >> index;
		cout << "Сколько элементов удаляем? ";
		int amount = 0;
		cin >> amount;
		deleteGroup((a == 1 ? arr1 : arr2), index, amount);
		break;
	}
	case 9:
	{
		int cap = 0;
		cout << "Длина подпоследовательности = "; 
		cin >> cap;
		cout << "Элементы подпоследовательности: ";
		int* b = initArray(cap);
		int el = 0;
		for (int i = 0; i < *(b - 1); i++)
		{
			cin >> el;
			addElement(b, el);
		}

		cout << "В каком массиве ищем подпоследовательность (1 / 2) ? ";
		int a = 0;
		cin >> a;
		subSequence((a == 1 ? arr1 : arr2), b);
		break;
	}
	break;
	}
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int* arr1 = initArray(10);
	int* arr2 = initArray(10);

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(arr1, arr2, choice);
		system("pause");
	} while (choice != 0);

	deleteArray(arr1);
	deleteArray(arr2);
	return EXIT_SUCCESS;
}