#include<iostream>
#include "ArrayList.h"
using namespace std;

/*
- �������� �������, ��������� � ����������;
- ������� ������;
- ���������, �������� �� ������ ������������;
- ���������� �������� ������ �� n ���������. n>0 - ����� ������, n<0 - ����� �����;
- ���������, ����� �� ������ ����� ������������, ���� �� ���� ������� ���� �������.
*/

int main(int argc, char* argv[])
{
	ArrayList core;

	for (int i = 0; i < 10; core.add(i), i++) {}
	cout << core.toString();

	return EXIT_SUCCESS;
}