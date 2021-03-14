#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
   char str[7];
   cin >> str;
   {
       int len = strlen(str);
       do
       {
           cout << str << endl;
       } while (next_permutation(str, str + len));
   }
   cout << endl;
}
