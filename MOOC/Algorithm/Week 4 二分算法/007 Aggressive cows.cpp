#include<iostream>
#include<algorithm>
using namespace std;
int n, c, a[100001];
bool cow(int x) {
    int i, t = a[0], sum = 1;
    for (i = 1;i < n;i++) {
        if (a[i] - t >= x) {
            t = a[i];
            sum++;
            if (sum == c) return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> c;
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int l = 1, r = 1e9 / c;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (cow(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << endl; //l-1或 r都可以 
    system("pause");
}
