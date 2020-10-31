#include <iostream>
using namespace std;

int main() {
	int N = 0; // число, от которого берем факториал
	cin >> N;
	int factorial = N;

	for (int i = N - 1; i > 1; i--)
		factorial *= i;

	cout << factorial;

	return 0;
}
