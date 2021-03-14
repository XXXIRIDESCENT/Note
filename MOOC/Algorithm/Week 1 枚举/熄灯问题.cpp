#include<iostream>
#include<cstring>
using namespace std;
void flip(char& a,int j)
{
	a ^= (1 << j);
}
int main()
{
	char a[5] = { 0 }, b[5];
	int n;
	cin >> n;
	for (int x = 1;x <= n;x++) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 6; j++)
			{
				int t;
				cin >> t;
				if (t) a[i] |= (1 << j);
				else a[i] &= ~(1 << j);
			}
		for (int i = 0;i < 64;i++)
		{
			b[0] = i;
			char l = a[0]; //l表示本行灯状态
			for (int j = 0;j < 5;j++)
			{
				for (int k = 0; k < 6; k++)
				{
					if ((b[j] >> k) & 1) //若b[j]的第k位为1，翻转本行三个灯的状态
					{
						if (k > 0) flip(l, k - 1);
						flip(l, k);
						if (k < 5) flip(l, k + 1);
					}
				}
				if (j < 4) {
					b[j+1] = l; //l表示本行灯经开关后剩余的亮灯（即下一行对应结果）
					l = a[j + 1] ^ b[j]; //l表示下行灯状态
				}
					
			}
			if (l == 0) break;
		}
		cout << "PUZZLE #" << x << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 6; j++) {
				cout << ((b[i] >> j) & 1);
				if (i < 5) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
