#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n, f, a[10001];
double pi = acos(-1);
double v(double x) {
    return 3.14159265358979 * x * x;//修改了pi的精度，也可用pi = acos(-1);
}
bool pie(double x) {
    int i, sum = 0;
    for (i = 0;i < n;i++) {
        if (v(a[i]) >= x) {
            sum += v(a[i]) / x;
            if (sum >= f) return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> f;
    f++;
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    double r = v(a[n - 1]), l = v(1);
    while (r - l > 1e-5) {
        double mid = l + (r - l) / 2;
        if (pie(mid)) l = mid;
        else r = mid;
    }
    printf("%.3f\n", l);
    system("pause");
}

