#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
       for (int a = 2; a <= n; a++)
          for (int b = 2; b < n; b++)
              for (int c = b; c < n; c++)
                  for (int d = c; d < n; d++)
                      if (a * a * a == b*b*b + c * c * c + d * d *  d)
                          cout<<"Cube = "<< a <<", Triple = ("<< b <<","<<c<<","<< d <<")\n";
}
