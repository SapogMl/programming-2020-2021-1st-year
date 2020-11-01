#include<iostream>
#include<clocale>

using namespace std;

void printMenu()
{
    cout << "MENU" << endl;
    cout << "0 - Выход из программы" << endl;
    cout << "1 - Добавить в массив n случайных чисел в промежутке от a до b(n, a, b вводится с клавиатуры)" << endl;
    cout << "2 - Развернуть массив" << endl;
    cout << "3 - Поменять элементы массива местами в парах. Если число элементов нечетно, последний элемент остается на своем месте." << endl;
    cout << "4 - Циклический сдвиг вправо на 1" << endl;
    cout << "5 - Развернуть две половинки массива. n - индекс элемента, разделяющего половинки." << endl;
    cout << "6 - Вывод массива" << endl;
}

void ExpandArray(int*& arr, int& cap)
{
    int newCap = cap + 1;
    int* newArr = new int[newCap];
    for (int i = 0; i < cap; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    cap = newCap;
}

void addElement(int*& arr, int& count, int& cap, int element)
{
    if (count + 1 == cap)
    {
        ExpandArray(arr, cap);
    }
    arr[count] = element;
    count++;
}

void addRandomElements(int*& arr, int& count, int& cap, int n, int min, int max)
{
    for (int i = 0; i < n; ++i)
    {
        addElement(arr, count, cap, rand() % (max - min + 1) + min);
    }
}

void printArray(int* arr, int count)
{
    cout << "[" << count << "] {";
    for (int i = 0; i < count; ++i)
    {
        cout << arr[i] << (i == count - 1 ? "}\n" : ", ");
    }
}

void reverseArray(int* arr, int count)
{
    int t = 0;

    for (int i = 0; i < count / 2; i++)
    {
        t = arr[i];
        arr[i] = arr[count - 1 - i];
        arr[count - i - 1] = t;
    }
}

void swapPairsArray(int* arr, int count)
{
    int t = 0;

    for (int i = 0; i < (count / 2 == 0 ? count : count - 1); i += 2)
    {
        t = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = t;
    }
}

void shiftArray(int* arr, int count)
{
    int t = 0;
    t = arr[count - 1];

    for (int i = 1; i < count; i++)
    {
        arr[count - i] = arr[count - i - 1];
    }
    arr[0] = t;
}

void shiftPartsArray(int* arr, int count, int n)
{
    int t = 0;

    for (int i = 0; i < n / 2; i++)
    {
        t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }
    for (int i = n + 1; i < (count + n + 1) / 2; i++)
    {
        t = arr[i];
        arr[i] = arr[n + count - i];
        arr[n + count - i] = t;
    }
}


void processChoice(int*& arr, int& count, int& cap, int choice)
{
    switch (choice)
    {
    case 1:
    {
        cout << "Количество элементов = ";
        int n = 0;
        cin >> n;
        cout << "Промежуток (a, b) = ";
        int a = 0;
        int b = 0;
        cin >> a >> b;
        addRandomElements(arr, count, cap, n, a, b);
        break;
    }
    case 2:
    {
        reverseArray(arr, count);
        break;
    }
    case 3:
    {
        swapPairsArray(arr, count);
        break;
    }
    case 4:
    {
        shiftArray(arr, count);
        break;
    }
    case 5:
    {
        cout << "Индекс = ";
        int n = 0;
        cin >> n;
        shiftPartsArray(arr, count, n);
        break;
    }
    case 6:
    {
        printArray(arr, count);
        break;
    }
    }
}



int main()
{
    setlocale(LC_ALL, "Russian");

    int choice = 0;
    int capacity = 10;
    int count = 0;
    int* arr = new int[capacity];

    do
    {
        system("cls");
        printMenu();
        cin >> choice;
        processChoice(arr, count, capacity, choice);
        system("pause");
    } while (choice != 0);

    delete[] arr;
    return 0;
}