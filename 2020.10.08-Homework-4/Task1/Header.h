#pragma once
#include<iostream>

using namespace std;

struct Header {
	int count;
	int capacity;
	int* data;
	int* list;

	Header();
	
	~Header();
				   
	/// <summary>
	/// ��������� ������� � �����
	/// </summary>
	/// <param name="element">����������� �������</param>
	/// <returns></returns>
	bool add(int element);

	void expand(int caplist);

	/// <summary>
	/// ��������� ������� � ������� index, ��� ����������� �������� ���������� �� 1 ������
	/// </summary>
	/// <param name="index">������ ������������ ��������</param>
	/// <param name="element">����������� �������</param>
	/// <returns>true, ���� ��� ������ ������, false - ���� �������� ��������</returns>
	bool addToIndex(int index, int element);

	/// <summary>
	/// ��������� ��� �������� �� ������ list � �����
	/// </summary>
	/// <param name="list">����������� ������</param>
	/// <returns>true, ���� ���������� ��������, false - ���� �� ����������</returns>
	bool addAll(int caplist);

	/// <summary>
	/// ��������� ��� �������� �� ������ list, ������� � ������� index.
	/// ��� ����������� �������� ���������� ������
	/// </summary>
	/// <param name="list">����������� ������</param>
	/// <returns>true, ���� ���������� ��������, false - ���� �� ����������</returns>
	bool addAllToIndex(int caplist, int index);

	/// <summary>
	/// ������� ��� �������� �� ������
	/// </summary>
	void clear(int* mas, int count);

	/// <summary>
	/// ���������� �� ������� � ������
	/// </summary>
	/// <param name="element">������� �������</param>
	/// <returns>true - ����������, false - �� ����������</returns>
	bool contains(int element);

	/// <summary>
	/// �������� ������� �� �������
	/// </summary>
	/// <param name="index">������ �������������� ��������</param>
	/// <returns>data[index], ���� ������ ���������, -1 - ���� ������ �����������</returns>
	int get(int index);

	/// <summary>
	/// ����� �������� � ������
	/// </summary>
	/// <param name="element">������� �������</param>
	/// <returns>������ ��������, ���� �� ������, -1 - ���� �� ������</returns>
	int indexOf(int element);

	/// <summary>
	/// �������� ������ �� �������
	/// </summary>
	/// <returns>true - ���� ������ ����, false - ���� ���� ���� �� 1 �������</returns>
	bool isEmpty();

	/// <summary>
	/// ����� ������ � ������� [count/capacity] {el1, el2, el3, ...}
	/// </summary>
	void print();

	/// <summary>
	/// �������� �������� �� ������
	/// </summary>
	/// <param name="index">������ ���������� ��������</param>
	/// <returns>true - ��� ������ ������, false - �������� ��������</returns>
	bool remove(int index);

	/// <summary>
	/// �������� ������� ��������
	/// </summary>
	/// <param name="index1">������ ������� ��������</param>
	/// <param name="index2">������ ������� ��������</param>
	/// <returns>true - ��� ������ ������, false - �������� ��������</returns>
	int swap(int index1, int index2);


};