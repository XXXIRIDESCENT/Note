#include<iostream>
using namespace std;
void f(string s,int p)
{
    if (p == s.length()) cout << s << endl;
    else for (int i = p;i < s.length();i++)
    {
        swap(s[p], s[i]);
        f(s,p+1);
    }
}
int main() 
{
    string s;
    cin >> s;
    f(s,0);
}
