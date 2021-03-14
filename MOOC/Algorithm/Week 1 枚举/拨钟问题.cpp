#include <iostream>
using namespace std;

int a[9], c[9], times = 30;
void revolve(int x1, int x2, int x3)
{
	int x4,x5,x6,x7,x8,x9;
	x4 = (4 - (a[0] + x1 + x2) % 4) % 4;	//（a[0] + i + j) % 4为旋转后a[0]的时间，x4为a[0]转到0点所需旋转次数
	x5 = (4 - (a[1] + x1 + x2 + x3) % 4) % 4;	//a[1]->0
	x6 = (4 - (a[2] + x2 + x3) % 4) % 4;		//a[2]->0
	x7 = (4 - (a[3] + x1 + x4 + x5) % 4) % 4;	//a[3]->0
	x9 = (4 - (a[5] + x3 + x6 + x5) % 4) % 4;	//a[5]->0
	x8 = (4 - (a[7] + x5 + x7 + x9) % 4) % 4;	//a[7]->0

	if ((a[4] + x1 + x3 + x7 + x9 + x5) % 4 == 0 && //判断a[4]是否为0
		(a[6] + x4 + x8 + x7) % 4 == 0 &&	//判断a[6]
		(a[8] + x6 + x8 + x9) % 4 == 0)		//判断a[8]
	{
		int t[9] = { x1,x2,x3,x4,x5,x6,x7,x8,x9 };
		int s = 0;
		for (int i = 0;i < 9;i++)
			s += t[i];
		if (s < times)
		{
			times = s;
			for (int i = 0;i < 9;i++)
				c[i] = t[i];
		}
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
		cin >> a[i];
	for (int i = 0;i < 4;i++)
		for (int j = 0;j < 4;j++)
			for (int k = 0;k < 4;k++)
				revolve(i, j, k);
	for (int i = 0;i < 9;i++)
		while (c[i]--) 
			cout << i + 1 << " ";
} 
