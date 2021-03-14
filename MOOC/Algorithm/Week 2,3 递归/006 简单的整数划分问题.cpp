//与放苹果完全相同
#include<iostream>
using namespace std;
int f(int n,int m) {
	if (m > n) m = n;
	if (n == 0 || m == 1) return 1;
	return f(n - m, m) + f(n, m - 1);
}
int main() {
	int n;
	while (cin >> n)
		cout << f(n, n) << endl;
}
