#include<iostream> 
using namespace std;

void printBits(int a) {
	bool pos = (a >= 0) ? true : false; //знак
	if (!pos) { a = -a; } //знак
	int b = sizeof(a) * 8;

	for (int i = 0; i < b; i++) {
		unsigned int temp = a;
		temp = (temp << i) >> (b - 1); // сдвиг туда-обратно

		if ((i == 0) && (!pos)) { temp = 1; } //знак

		cout << temp;

		if (i % 8 == 0) { cout << " "; }
	}
	cout << endl;
}

void printBits(long a) {
	bool pos = (a >= 0) ? true : false;
	if (!pos) { a = -a; }
	int b = sizeof(a) * 8;

	for (int i = 0; i < b; i++) {
		unsigned long int temp = a;
		temp = (temp << i) >> (b - 1);

		if ((i == 0) && (!pos)) { temp = 1; }

		cout << temp;

		if (i % 8 == 0) {
			cout << " ";
		}
	}
	cout << endl;
}

void printBits(long long a) {
	bool pos = (a >= 0) ? true : false;
	if (!pos) { a = -a; }
	int b = sizeof(a) * 8;

	for (int i = 0; i < b; i++) {
		unsigned long long int temp = a;
		temp = (temp << i) >> (b - 1);

		if ((i == 0) && (!pos)) { temp = 1; }

		cout << temp;

		if (i % 8 == 0) {
			cout << " ";
		}
	}
	cout << endl;
}

void printBits(float a) { // как сократить до 32 бит?
	double d = a;
	long long ll = *((long long*)((void*)&d));
	printBits(ll);
}

void printBits(double a) {
	long long ll = *((long long*)((void*)&a)); 
	printBits(ll);
}

void printBits(long double a) {
	long long ll = *((long long*)((void*)&a)); // ссылка на (float)a -> (void)указатель на a -> (long long)указатель на а -> указатель на (long long*)a
	printBits(ll);
}

// вс€ческое оформление вывода

void menu() {
	cout << "1 - INT" << endl;
	cout << "2 - LONG" << endl;
	cout << "3 - LONG LONG" << endl;
	cout << "4 - FLOAT" << endl;
	cout << "5 - DOUBLE" << endl;
	cout << "6 - LONG DOUBLE" << endl;
}

void input(int choice) {
	switch (choice) {
	case 1:
	{
		cout << "INT = ";
		int a;
		cin >> a;
		printBits(a);
		cout << endl;
		break;
	}
	case 2:
	{
		cout << "LONG = ";
		long a;
		cin >> a;
		printBits(a);
		cout << endl;
		break;
	}
	case 3:
	{
		cout << "LONG LONG = ";
		long long a;
		cin >> a;
		printBits(a);
		cout << endl;
		break;
	}
	case 4:
	{
		cout << "FLOAT = ";
		float a;
		cin >> a;
		printBits(a);
		cout << endl;
		break;
	}
	case 5:
	{
		cout << "DOUBLE = ";
		double a;
		cin >> a;
		printBits(a);
		cout << endl;
		break;
	}
	case 6:
	{
		cout << "LONG DOUBLE = ";
		long double a;
		cin >> a;
		printBits(a);
		cout << endl;
		break;
	}
	}
}

int main() {
	int choice;

	menu();
	cin >> choice;

	while (choice != 0) {
		input(choice);
		system("PAUSE");
		system("CLS");
		menu();
		cin >> choice;
	}

	return EXIT_SUCCESS;
}







/*
1. –еализовать функции
void printBits(int); i
void printBits(long); ii
void printBits(long long); iii
void printBits(float); iv
void printBits(double); v
void printBits(long double); vi
*/
/* void determineType(long double* n_symb) {

	int* n_int = 0;
	long* n_long = 0;
	long long* n_ll = 0;
	float* n_f = 0;
	double* n_d = 0;
	long double* n_ld = 0;

	if ()
}  */

/* char* resize(char* a, size_t size) {
	char* new_char = new char[size + 1];
	for (size_t i = 0; i < size; i++) { new_char[i] = a[i]; }
	delete[] a;
	return new_char;
}

char* readNumber() {
	char* a = new char[1];
	size_t i = 0;
	cin >> a[i];

	while ((a[i] == '.') || ((a[i] <= '9') && (a[i] >= '0'))) {
		a = resize(a, i);
		i++;
		cin >> a[i];
	}

	return a;
} */

/* char* resize(char* a, int size) {
	char* new_a = new char[size];
	for (int i = 0; i < size; i++) {
		new_a[i] = a[i];
	}
	delete[] a;
	return new_a;
}

char* readNumber() {
	int size = 1;
	char* a = new char[size];
	cin >> a[size - 1];
	while ((a[size - 1] == '.') || ((a[size - 1] >= '0') && (a[size - 1] <= '9')))  {
		size++;
		a = resize(a, size);
		cin >> a[size - 1];
	}
	return a;
}

int determineType(char * mas) {
	int index = 0;
	int z_index = 1;
	long double t = 0;
	bool dot = false;
	while (*mas != NULL) {
		index++;
		if (mas[index] == '.') { dot = true; }
		else {
			if (dot == true) {
				t += mas[index] * pow(10, -z_index);
				z_index++;
			}
			else {
				t += mas[index];
			}
		}
	}
	return sizeof(t);
} */