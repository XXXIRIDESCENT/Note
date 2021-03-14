#include<bits/stdc++.h>
using namespace std;
void u(string a,int x[])
{
	for (int i = 0; i < a.length(); i++)
	{
		int& t = x[a[i] - 'A'];
		if (t == 2) continue;
		if (t == 1) t = 2;
		else t = -1;
	}
}void d(string a, int x[])
{
	for (int i = 0; i < a.length(); i++)
	{
		int& t = x[a[i] - 'A'];
		if (t == 2) continue;
		if (t == -1) t = 2;
		else t = 1;
	}
}
void e(string a, int x[])
{
	for (int i = 0; i < a.length(); i++)
		x[a[i] - 'A'] = 2;
}
int main()
{
	string a[3][3];
	int n;
	cin >> n;
	while (n--)
	{
		int x[13] = { 0 };
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 0;i < 3;i++)
		{
			if (a[i][2] == "even")
			{
				e(a[i][0], x);
				e(a[i][1], x);
			}
			else if (a[i][2] == "up")
			{
				d(a[i][0], x);
				u(a[i][1], x);
			}
			else
			{
				u(a[i][0], x);
				d(a[i][1], x);
			}
		}
		for (int i = 0; i < 12; i++)
		{
			if (x[i] == -1 || x[i] == 1)
                                cout << char(i + 'A') << " is the counterfeit coin and it is " << (x[i] == -1 ? "light" : "heavy") << endl;
		}
	}
}
