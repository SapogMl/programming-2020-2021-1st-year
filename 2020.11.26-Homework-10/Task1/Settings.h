#pragma once

int** initMatrix(int n);

void clear(int n, int** matrix);

void printMatrix(int n, int** matrix);

/*1  2  3  4  5  6
  2  3  4  5  6  7
  3  4  5  6  7  8
  4  5  6  7  8  9
  5  6  7  8  9 10
  6  7  8  9 10 11 */
void diagSymm(int n);

/*11 10  9  8  7  6
  10  9  8  7  6  5
   9  8  7  6  5  4
   8  7  6  5  4  3
   7  6  5  4  3  2
   6  5  4  3  2  1*/
void diagSymmBackwards(int n);

/*1 2 3 4 5 6
  1 2 3 4 5 6
  1 2 3 4 5 6
  1 2 3 4 5 6
  1 2 3 4 5 6
  1 2 3 4 5 6*/
void lines(int n);

/*1 1 1 1 1 1
  1 2 2 2 2 2
  1 2 3 3 3 3
  1 2 3 4 4 4
  1 2 3 4 5 5
  1 2 3 4 5 6*/
void oneToN(int n);

/* 1  2  3  4  5  6
  20 21 22 23 24  7
  19 32 33 34 25  8
  18 31 36 35 26  9
  17 30 29 28 27 10
  16 15 14 13 12 11*/
void spiral(int n);