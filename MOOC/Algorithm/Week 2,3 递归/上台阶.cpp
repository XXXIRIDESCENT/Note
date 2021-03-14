#include<iostream>
using namespace std;
int c;
void f(int n) {
	if (n) {
		f(n - 1);
		if (n > 1) f(n - 2);
	}
	else c++;
}
int main() {
	int n;
	while (cin >> n) {
		c = 0;
		f(n);
		cout << c;
	}
}
