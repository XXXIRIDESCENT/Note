#include<iostream>
using namespace std;
int sum = 0, upperlim, n;
void test(int row, int ld, int rd)//row、ld和rd分别表示在纵列和两个对角线方向的限制条件下这一行的哪些地方不能放
{
       if (row != upperlim)
       {
              int pos = upperlim & ~(row | ld | rd);//三个参数并起来，得到该行所有的禁位
              while (pos)
              {
                      int p = pos & (~pos + 1);    //取出pos中最右边的1
                      pos -= p;
                      test(row + p, (ld + p) << 1, (rd + p) >> 1);
              }
       }
       else   sum++;
}
int main()
{
       cin >> n;
       upperlim = (1 << n) - 1;//n个1组成的二进制数
       test(0, 0, 0);
       cout << sum;
}
