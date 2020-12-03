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

double integralPtDelete(double number) // вычисляет дробную часть числа
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

double Taylor(double x, int n)
{
	int i = 0; // коэффициент слагаемого в формуле Тейлора
	double calc = 0; // искомое приближение
	double compare = 0; // цифры, стоящие после n-й цифры дробной части calc

	do
	{
		calc += power(x, i) / factorial(i);
		i++;
		compare = integralPtDelete(integralPtDelete(calc) * power(10, n)); 
	} while (compare == 0);

	calc -= compare * power(0.1, n); 
	// вычитаем дробную часть calc начиная с (n+1)-й цифры
	
	return calc;
}


int main()
{
	double x = 0;
	int n = 0;
	cin >> x >> n;
	cout << "Экспонента = " << exp(x) << endl;
	cout << "Приближение = " << Taylor(x, n) << endl;;
	return 0;
}
