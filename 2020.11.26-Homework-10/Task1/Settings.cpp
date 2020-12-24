#include<iostream>
#include "Settings.h"

using namespace std;

int** initMatrix(int n)
{
	int** matrix = new int* [n] { 0 };
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n] { 0 };
	}
	return matrix;
}

void clear(int n, int** matrix)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(int n, int** matrix)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%3d ", matrix[i][j]);
		}
		cout << endl;
	}
}

void diagSymm(int n)
{
	int** matrix = initMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = j + 1 + i;
		}
	}

	printMatrix(n, matrix);
	clear(n, matrix);
}

void diagSymmBackwards(int n)
{
	int** matrix = initMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[n - 1 - i][n - 1 - j] = j + 1 + i;
		}
	}

	printMatrix(n, matrix);
	clear(n, matrix);
}

void lines(int n)
{
	int** matrix = initMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = j + 1;
		}
	}

	printMatrix(n, matrix);
	clear(n, matrix);
}

void oneToN(int n)
{
	int** matrix = initMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = (i < j ? i + 1 : j + 1);
		}
	}

	printMatrix(n, matrix);
	clear(n, matrix);
}

void spiral(int n)
{
	int** matrix = initMatrix(n);
	int dir = 0;

	for (int j = 0; j < n; j++) { matrix[0][j] = j + 1;  } // заполнение первой строки - отдельно, потому что иначе рекурсивному алгоритму ниже неоткуда брать первый элемент

	for (int turn = 1; turn < 2 * n - 1; turn++) // turn - число поворотов; dir = 1) 0 - заполнение строки выше центра матрицы 2) столбца справа 3) строки снизу 4) столбца слева
	{
		dir = turn % 4;
		if (dir == 0)
		{
			for (int j = turn / 4; j < n - 1; j++) { matrix[turn / 4][j] = matrix[turn / 4][j - 1] + 1; }
		}
		if (dir == 1)
		{
			for (int i = turn / 4 + 1; i < n - turn / 4; i++) { matrix[i][n - 1 - turn / 4] = matrix[i - 1][n - 1 - turn / 4] + 1; }
		}
		if (dir == 2)
		{
			for (int j = n - 2 - turn / 4; j > -1 + turn / 4; j--) { matrix[n - 1 - turn / 4][j] = matrix[n - 1 - turn / 4][j + 1] + 1;  }
		}
		if (dir == 3)
		{
			for (int i = n - 2 - turn / 4; i > turn / 4; i--) { matrix[i][turn / 4] = matrix[i + 1][turn / 4] + 1; }
		}
	}

	printMatrix(n, matrix);
	clear(n, matrix);
}

