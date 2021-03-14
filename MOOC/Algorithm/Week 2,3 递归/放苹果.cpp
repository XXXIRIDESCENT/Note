#include<iostream>
using namespace std;
int f(int m,int n) {
	if (n > m) n = m;
	if (m == 0) return 1;
	if (n == 0) return 0;
	return f(m, n - 1) + f(m - n, n); //f(m,n-1)为有盘子为空时的放法，f(m-n,n)为无盘子为空时的放法
}
int main() {
	int t, m, n;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
}
