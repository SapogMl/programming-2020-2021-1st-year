#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


double Taylor(double x, int n)
{
	double add = 1;
	double calc = 1;
	int i = 1;
	int pwr = 10;

	for (int j = 0; j < n - 1; j++)
	{
		pwr *= 10;
	}

	int tenN = pwr;
	double frac = 0;
	double tail = 0;


	while (frac == 0)
	{
		add *= (x / i);
		calc += add;
		i++;
		tenN = pwr;

		frac = calc;
		while (frac >= 1)
		{
			while (frac >= tenN)
			{
				frac -= tenN;
			}
			tenN /= 10;
		}

		if (frac != 0) 
		{
			frac *= pwr;
			tenN = pwr;

			while (frac >= 1)
			{
				while (frac >= tenN)
				{
					frac -= tenN;
				}
				tenN /= 10;
			}

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