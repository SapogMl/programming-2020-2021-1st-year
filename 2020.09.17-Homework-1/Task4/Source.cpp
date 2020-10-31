#include<iostream>
using namespace std;

bool isPrime(int n)
{
	for (int k = 2; k < n; ++k)
	{
		if (n % k == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int number = 0;
	cin >> number;

	for (int i = 2; i <= number; i++)
	{
		if (isPrime(i))
		{
			cout << i << " ";
		}
	}
	return 0;
}