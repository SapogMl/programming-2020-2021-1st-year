#include <iostream>
using namespace std;

int main() {
	int N = 0, pwr = 0; // ��������� �����, �������
	cin >> N;
	cin >> pwr;
	int final = N; // ���������

	while (pwr > 1) {
		final *= N;
		pwr -= 1;
	}

	cout << final;

	return 0;
}
