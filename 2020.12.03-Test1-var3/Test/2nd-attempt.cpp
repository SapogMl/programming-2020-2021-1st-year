/* 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


double Taylor(double x, int n)
{
	double add = 1;
	double calc = 1;
	double frac = 0; // дробная часть текущего calc с позиции n+1
	int i = 1;
	int pwr = 10;

	double buf = 0;
	int length = 0;

	while (frac == 0)
	{
		add *= (x / i);
		calc += add;
		buf = calc;
		frac = calc;

		while (buf > 1) // находим дробную часть calc
		{
			buf /= 10;
			length += 1;
		}
		for (int j = 0; j < n; j++)
		{
			pwr = 10;
			for (int k = 0; k < length; i++)
			{
				pwr *= 10;
			}
			while (frac > (pwr / 10))
			{
				frac -= pwr;
			}
			length -= 1;
		}

		pwr = 10;
		for (int k = 0; k < n; k++) { pwr *= 10;  }
		frac *= pwr;
		int whole = frac;
		frac -= whole;

		if (frac != 0)
		{
			frac /= pwr;
			calc -= frac;
		}
	}

	return calc;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	double x = 0;
	int n = 0;
	cin >> x >> n;
	cout << "Экспонента = " << exp(x) << endl;
	cout << "Приближение = " << Taylor(x, n) << endl;;
	return 0;
}
 */