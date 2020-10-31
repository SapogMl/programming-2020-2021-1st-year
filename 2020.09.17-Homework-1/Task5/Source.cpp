#include <iostream>
using namespace std;

int main() 
{
	int K = 0;
	int counter = 2; // число делителей, сразу включаем 1 и K, где K - исходное число
	cin >> K;

	for (int i = 2; i * i <= K; i++) 
	{
		if (K % i == 0)
		{
			counter += 2;
		}

		if (K == i * i)
		{
			counter--;
		}
	}
	cout << counter;

	return 0;
}
