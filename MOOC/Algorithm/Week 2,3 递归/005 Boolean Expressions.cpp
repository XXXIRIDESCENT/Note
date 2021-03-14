#include<iostream>
#include<cstring>
using namespace std;
char s[10000];
int i, sum = 1;
bool f();
char ch() {
	while (s[i++] == ' ');
	return s[i - 1];
}
bool v() {
	char c = ch();
	if (c == '(') return f();
	if (c == '!') return !v();
	if (c == 'V') return true;
	if (c == 'F') return false;
}
bool f() {
	bool b = v();
	for (char c = ch();i < strlen(s);c = ch()) {
		if (c == ')') break;
		if (c == '|') b = v() || b;
		if (c == '&') b = v() && b;
	}
	return b;
}
int main() {
	while (cin.getline(s, 10000)) {
		i = 0;
		printf("Expression %d: %c\n",sum++,(f() ? 'V' : 'F'));
		memset(s, 0, 10000);
	}
}
