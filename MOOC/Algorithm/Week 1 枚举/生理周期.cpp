#include <iostream>
using namespace std;
int main()
{
	int p, e, i, d, c = 0;
	cin >> p >> e >> i >> d;
	while (p != -1)
	{
		c++;
		int k = d + 1;
		while ((k - p) % 23) k++;
		while ((k - e) % 28) k += 23;
		while ((k - i) % 33) k += 23 * 28;
		cout << "Case " << c << ": the next triple peak occurs in " << k - d << " days.\n";
		cin >> p >> e >> i >> d;
	}
}
