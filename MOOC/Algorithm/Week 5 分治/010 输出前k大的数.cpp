#include<iostream>
#include<algorithm>
using namespace std;
int a[100001], n, k;
void f(int x, int y) {
    int i = x, j = y, t = a[x];
    while (i < j) {
        while (i < j && a[j] >= t)
            j--;
        if (i < j) a[i++] = a[j];
        while (i < j && a[i] < t)
            i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = t;
    if (i > n - k) f(x, i - 1);
    else if (i < n - k) f(i + 1, y);
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    cin >> k;
    sort(a, a + n); //直接调用sort()就可，如下调用函数也可
    // f(0, n - 1);
    // sort(a + n - k, a + n); 
    for (int i = 1;i <= k;i++)
        cout << a[n - i] << endl;
    system("pause");
}