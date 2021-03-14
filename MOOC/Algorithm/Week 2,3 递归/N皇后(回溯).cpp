#include<iostream>
#include<cmath>
using namespace std;
int main()
{    
    int n,a[9],c=0,i,k=1;
    cin>>n;
    a[k]=1;
    while(k>0)
        if(k<=n&&a[k]<=n)
        {
            for(i=1;i<k;i++)
                if(a[i]==a[k]||abs(a[i]-a[k])==k-i)    break;
            if(i==k)
            {
                k++;        //第K行的位置已经确定了，继续寻找第k+1行皇后的位置
                a[k]=1;     //从第一列开始查找
            }    
            else    a[k]++; //继续探测当前行的下一列：a[k]+1  
        }
        else
        {
            if(k>n)    c++;
            k--;      //棋子位置不符合要求，则退回前一步
            a[k]++;   //继续试探下一列位置
        }
    cout<<c;
}
