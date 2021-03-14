#include<iostream>
using namespace std;
int f();
int factor() {
	int result = 0;
	char c = cin.peek();
	if (c == '(') {
		cin.get();
		result = f();
		cin.get();
	}
	else {
		cin >> result;
	}
	return result;
}
int term() {
	int result = factor();
	while (true) {
		char op = cin.peek();
		if (op == '*' || op == '/') {
			cin.get();
			if (op == '*')	result *= factor();
			else	result /= factor();
		}
		else break;
	}
	return result;
}
int f() {
	int result = term();
	while (true) {
		char op = cin.peek();
		if (op == '+' || op == '-') {
			cin.get();
			if (op == '+')	result += term();
			else	result -= term();
		}
		else break;
	}
	return result;
}
int main() {
	cout << f() << endl;
}
