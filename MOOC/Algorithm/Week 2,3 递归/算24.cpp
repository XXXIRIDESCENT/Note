#include<iostream>
using namespace std;
bool count24(double a[],int n) {
	if (n == 1) {
		return fabs(a[0] - 24) <= 1e-6;
	}
	for (int i = 0;i < n - 1;i++)
		for (int j = i + 1;j < n;j++)
		{
			double b[5];
			int m = 0;
			for (int k = 0;k < n;k++)
				if (k != i && k != j)
					b[m++] = a[k];
			b[m] = a[i] + a[j];
			if (count24(b, m + 1)) return true;
			b[m] = a[i] - a[j];
			if (count24(b, m + 1)) return true;
			b[m] = a[j] - a[i];
			if (count24(b, m + 1)) return true;
			b[m] = a[i] * a[j];
			if (count24(b, m + 1)) return true;
			if (a[j]!=0) {
				b[m] = a[i] / a[j];
				if (count24(b, m + 1)) return true;
			}
			if (a[i]!=0) {
				b[m] = a[j] / a[i];
				if (count24(b, m + 1)) return true;
			}
		}
	return false;
}
int main() {
	double a[5];   
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		if (!a[0]) break;
		cout << (count24(a,4)?"YES":"NO") << endl;
	}
}
