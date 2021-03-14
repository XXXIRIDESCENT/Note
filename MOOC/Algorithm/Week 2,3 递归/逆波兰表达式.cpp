#include<iostream>
using namespace std;
double f()
{
    string s;
    cin >> s;
    if (s == "+")
        return f() + f();
    else if (s == "-")
        return f() - f();
    else if (s == "*")
        return f() * f();
    else if (s == "/")
        return f() / f();
    else return atof(s.c_str());
}
int main()
{
    cout << f();
}
