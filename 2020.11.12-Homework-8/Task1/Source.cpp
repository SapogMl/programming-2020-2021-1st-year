/*������������������ ������ ���� �������
��������, ��� ��� ������� � ��������� ��������� ��������:
1). � ������ �������.
2). �� ������� �� 1 ��������.
3). �� ������� �� ���������� ���������.
*/

#include<iostream>
#include"LinkedList.h"

using namespace std;



int main()
{
	
	LinkedList list;

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	list[3] += 4; // �������� +=


	cout << list << endl;
	list -= 0;
	cout << list << endl;

	return EXIT_SUCCESS;

}