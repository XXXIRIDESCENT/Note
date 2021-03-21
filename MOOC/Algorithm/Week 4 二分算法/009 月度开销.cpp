#include<iostream>
using namespace std;
int n, m, a[100001];
int f(int x) {
    int s = 0, c = 1;
    for (int i = 0;i < n;i++) {
        if (s + a[i] > x) {
            s = 0;
            c++;
        }
        s += a[i];
    }
    return (c <= m ? true : false);
}
int main() {
    int l = 0, r = 0;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        r += a[i];
        if (l < a[i]) l = a[i];
    }
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (f(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    system("pause");
}