#include<iostream>
#include<cmath>
using namespace std;
void f(int n)
{
    int i = 0;
    while (pow(2, i) <= n)
        i++;
    i--;
    if (i == 0) cout << "2(0)";
    else if (i == 1) cout << "2";
    else if (i == 2) cout << "2(2)";
    else
    {
        cout << "2(";
        f(i);
        cout << ")";
    }
    n -= pow(2, i);
    if (n)
    {
        cout << "+";
        f(n);
    }
}
int main() 
{
    int n;
    cin >> n;
    f(n);
}
