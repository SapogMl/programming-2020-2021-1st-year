#include<iostream>
using namespace std;

template<typename T1, typename T2>
T1 sum(T1 a, T2 b) {
	return a + b;
}

template<typename T1, typename T2>
T1 diff(T1 a, T2 b) {
	return a - b;
}

template<typename T1, typename T2>
T1 mult(T1 a, T2 b) {
	return a * b;
}

template<typename T1, typename T2>
T1 div(T1 a, T2 b) {
	return a / b;
}

template<typename T1, typename T2>
T1 mod(T1 a, T2 b) {
	return (int)(a / b);
}

// коды арифметических действий
int opIndex(char op) {
	switch (op) {
	case '+': { return 0; break; }
	case '-': { return 1; break; }
	case '*': { return 2; break; }
	case '/': { return 3; break; }
	case '%': { return 4; break; }
	default: { return -1; break; }
	}
}

template<typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation) {
	T1(*ops[5])(T1, T2) { sum, diff, mult, div, mod }; 

	return ops[opIndex(operation)](a, b); 
}

// коды операндов
int NumberType(char* argv[], int index) {
	int point = 0;
	bool minus = false;

	for (int i = 0; i < strlen(argv[index]); i++) {
		if (argv[index][i] == '.') {
			if (point < 1) {
				point++;
			}
			else return -1;
		}
		if (argv[index][i] == '-') {
			if (i == 0) {
				!minus;
			}
			else return -1;
		}
		else if ((argv[index][i] > '9') || (argv[index][i] < '0')) {
			return -1;
		}
	}

	if (point == 0) {
		if (minus == 0) {
			return 1; // positive int
		}
		else return 2; // negative int
	}
	else {
		if (minus == 0) {
			return 3; // positive double
		}
		else return 4; // negative double
	}
}

/*
~RETURNS:
1 pos int
2 neg int
3 pos double
4 neg double
*/

double ToDouble(char* argv[], int index, bool sign) {
	int p_index = 0;
	
	while (argv[index][p_index] != '.') {
		p_index++;
	}
	
	double result = 0;

	for (int i = sign ? 1 : 0; i < p_index; i++) { // целая часть
		result += (argv[index][i] - 48) * pow(10, p_index - i);
	}

	for (int i = p_index + 1; i < strlen(argv[index]); i++) { // дробная часть
		result += (argv[index][i] - 48) * pow(10, -(i - p_index));
	}

	if (!sign) { return result; }
	else { return -result; }
}

int ToInt(char* argv[], int index, bool sign) {
	int result = 0;

	for (int i = (sign ? 1 : 0); i < strlen(argv[index]); i++) {
		result += (argv[index][i] - 48) * pow(10, strlen(argv[index] - i));
	}

	if (!sign) { return result; }
	else { return -result; }
}

// коды ошибок
int Error(int argc, char* argv[], int left, int right, int action) {

	if (argc != 7) {
		cout << "Ошибка: Избыток аргументов" << endl;
		return 1;
	}

	if (left == -1) {
		cout << "Ошибка: Первый операнд" << endl;
		return 1;
	}

	if (right == -1) {
		cout << "Ошибка: Второй операнд" << endl;
		return 1;
	}

	if ((action == -1) or (strlen(argv[4]) != 1)) {
		cout << "Ошибка: Некорректная операция" << endl;
		return 1;
	}

	return -1;
}

// вывод результата
void Output(double n1, double n2, char op) {

	if (n1 < 0) {
		cout << "(" << n1 << ")";
	}
	else cout << n1;

	cout << " " << op << " ";

	if (n2 < 0) {
		cout << "(" << n2 << ")";
	}
	else cout << n2;

	cout << " = " << calculate(n1, n2, op);
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");

	int opd1_type = NumberType(argv, 2);
	int opd2_type = NumberType(argv, 6);
	int opn_type = opIndex(argv[4][0]);

	if (Error(argc, argv, opd1_type, opd2_type, opn_type) != -1) {
		cout << "Общий вид корректных входных данных: calc --operand1 [число] --operator [операция] --operand2 [число], где" << endl;
		cout << "число: отрицательное/положительное, целое/с плавающей точкой," << endl;
		cout << "операция: + - * / %" << endl;
	}
	else { // note: это отвратительно, в идеале надо выкинуть положительность из NumberType
		double arg1 = 0;
		double arg2 = 0;

		if (opd1_type == 1) { arg1 = ToInt(argv, 2, false); }
		else if (opd1_type == 2) { arg1 == ToInt(argv, 2, true); }
		else if (opd1_type == 3) { arg1 == ToDouble(argv, 2, false); }
		else { arg1 == ToDouble(argv, 2, true); }

		if (opd2_type == 1) { arg2 = ToInt(argv, 6, false); }
		else if (opd2_type == 2) { arg2 == ToInt(argv, 6, true); }
		else if (opd2_type == 3) { arg2 == ToDouble(argv, 6, false); }
		else { arg2 == ToDouble(argv, 6, true); }

		char symbol = argv[4][0];

		Output(arg1, arg2, symbol);
		system("pause>nul");
	}

	return 0;
}