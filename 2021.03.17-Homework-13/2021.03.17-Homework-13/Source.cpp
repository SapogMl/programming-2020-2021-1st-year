#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;


bool letter(char a);
bool digit(char a);
bool identifier(char a);
bool unsigned_integer(string a, int l);
bool multiplier(string a, int l);
int search(string a, int l, char ch);
bool term(string a, int l);
bool expression(string a, int l);



int main() {

	fstream strfile;
	strfile.open("in.txt");

	string str = "";
	char ch;

	while (strfile >> ch) {
		str.push_back(ch);
	}

	strfile.close();

	if (!expression(str, str.length())) {
		cout << "= (";
		return 0;
	}

	cout << "= )";
	return 0;
}




bool letter(char a) {
	return ('x' <= a) && (a <= 'z');
}

bool digit(char a) {
	return (a == '0') || (a == '1');
}

bool identifier(char a) {
	return letter(a);
}

bool unsigned_integer(string a, int l) {
	if (l != 0) {
		return digit(a[0]) && unsigned_integer(a.substr(1, l - 1), l - 1);
	}
	else return true; // ?
}

bool multiplier(string a, int l) {

	bool isID = ((l == 1) && (identifier(a[0])));
	bool isExpr = ((l > 2) && (expression(a.substr(1, l - 2), l - 2)));

	return unsigned_integer(a, l) || isID || isExpr;
}

int search(string a, int l, char ch) {

	int i = 0;
	while ((i < l) && (a[i] != ch)) {
		i++;
	}
	return i;
}

bool term(string a, int l) {
	if ((search(a, l, '*') != -1) && (a[0] == '(') && (a[l - 1] == ')') && ((l - 2 - search(a, l, '*')) > 0)) {
		int index = search(a, l, '*');
		return multiplier(a.substr(1, index - 1), index - 1) && term(a.substr(index + 1, l - 2 - index), l - 2 - index);
	}
	else if ((search(a, l, '+') != -1) && ((l - 1 - search(a, l, '+')) > 0)) {
		int index = search(a, l, '+');
		return multiplier(a.substr(0, index), index) && term(a.substr(index + 1, l - 1 - index), l - 1 - index);
	}
	else return multiplier(a, l);
}

bool expression(string a, int l) { 
	if (((search(a, l, '+') != -1) || (search(a, l, '-') != -1)) && ((l - 1 - search(a, l, '+')) > 0) && ((l - 1 - search(a, l, '-')) > 0)) {
		int index = ((search(a, l, '+') < search(a, l, '-')) ? (search(a, l, '+')) : (search(a, l, '-')));
		return term(a.substr(0, index), index) && expression(a.substr(index + 1, l - 1 - index), l - 1 - index);
	}
	else return term(a, l);
}