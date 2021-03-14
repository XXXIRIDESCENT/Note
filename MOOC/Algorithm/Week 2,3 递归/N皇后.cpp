#include<iostream>
using namespace std;
int n, c = 0, q[9];
void Q(int a)
{
    int i, j;
    if (a == n) 
    {
        for (i = 0;i < n;i++)
            cout << q[i] + 1 << " ";
        cout << endl;
    }
    else for (i = 0;i < n;i++)
    {
        for (j = 0;j < a;j++)
            if (q[j] == i || i - q[j] == a - j || i + a == j + q[j])    break;
        if (j == a)
        {
            q[a] = i;
            Q(a + 1);
        }
    }
}
int main()
{
    cin >> n;
    Q(0);
}
