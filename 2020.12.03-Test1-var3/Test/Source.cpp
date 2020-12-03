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

double Euler(double x, int n)
{
	double calc = 0;
	int i = 0;
	int precision = power(10, n);
	double compare = power(10, n+1) * integralPtDelete((integralPtDelete(power(x, i) / factorial(i)))); // дробный хвост из n цифр, домноженный на 10^n

	do
	{
		calc += power(x, i) / factorial(i); 
		cout << integralPtDelete((integralPtDelete(power(x, i) / factorial(i)))) << " " << compare << " " << calc << endl;
		i++;
		compare = power(10, n + 1) * integralPtDelete((integralPtDelete(power(x, i) / factorial(i))));
	} while (compare < precision);

	if (compare > precision)
	{
		calc += power(x, i) / factorial(i);

		int cut = integralPtDelete(calc);
		int count = 0;
		while (count != n)
		{
			cout << "!";
			cut *= 10;
			count += 1;
		}
		cut = integralPtDelete(cut) * power(0.1, count);
		calc -= cut;
	}
	return calc;
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
