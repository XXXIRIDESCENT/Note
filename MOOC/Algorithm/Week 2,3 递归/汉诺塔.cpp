#include <iostream>
using namespace std;
void H(int n, char a, char b, char c)
{
	if (n == 1)
		cout << a << "->" << c << endl;
	else
	{
		H(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		H(n - 1, b, a, c);
	}
}
int main()
{
	int n;
	cin >> n;
	H(n, 'A', 'B', 'C');
}
