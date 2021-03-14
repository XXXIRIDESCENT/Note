#include <iostream>
using namespace std;
void flip(string& a, int i) {
	a[i] = a[i] == '1' ? '0' : '1';
}
int f(string a, string& b) {
	int i = 1, l = a.length(), c = 0;
	for (; i < l; i++)
	{
		if (a[i-1] != b[i-1])
		{
			flip(a, i-1);
			flip(a, i);
			if (i + 1 < l) flip(a, i + 1);
			c++;
		}
	}
	if (a != b) return 100;
	return c;
}
int main()
{
	string a, b;
	int c1, c2, c;
	cin >> a >> b;
	c1 = f(a, b);
	flip(a, 0);
	flip(a, 1);
	c2 = f(a, b) + 1;
	c = c1 > c2 ? c2 : c1;
	if (c < 30)	cout << c;
	else cout << "impossible";
}
