#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double power(double x, int n)
{
	double res = 1;
	for (int i = 0; i < n; i++)
	{
		res *= x;
	}
	return res;
}

int factorial(double inputv)
{
	if (inputv == 0)
	{
		inputv = 1;
		return inputv;
	}
	for (int i = inputv - 1; i > 0; i--)
	{
		inputv *= i;
	}
	return inputv;
}

double integralPtDelete(double number)
{
	double buf = number;
	int c = 1;
	while (buf > 10)
	{
		buf /= 10;
		c += 1;
	}

	for (int i = 0; i < c; i++)
	{
		while (number >= power(10, i))
		{
			number -= power(10, i);
		}
	}
	return number;
}

int length(double calc, int n)
{
	int uncut_tail = integralPtDelete(calc) * power(10, n);
	int i = 0;
	while ((integralPtDelete(uncut_tail) == 0) and (i < n))
	{
		uncut_tail /= 10;
		i++;
	}
	cout << i << endl;
	return i;
}

double Euler(double x, int n)
{
	double calc = 0;
	int i = 0;
	do
	{
		calc += power(x, i) / factorial(i); 
		cout << power(x, i) << " " << factorial(i) << " " << calc << endl;
		i++;
		// cout << calc << endl;
	} while (length(calc, n) != 0); // прибавляем, пока знаков после запятой не станет n или больше

	cout << power(0.1, n) << endl;
	double tail = integralPtDelete(integralPtDelete(calc) * power(10, n))*power(0.1, n);
	cout << tail << endl;
	calc -= tail; 	// отрубаем ненужный хвост, если он есть
	return(calc);
}



int main()
{
	double x = 0;
	int n = 0;
	cin >> x >> n;
	cout << exp(x) << endl;
	cout << Euler(x, n) << endl;;
	return 0;
}
