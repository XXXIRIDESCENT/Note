#include<iostream>
#include<cmath>
using namespace std;

double EPS = 1e-6;
double f(double x) {
    return x * x * x - 5 * x * x + 10 * x - 80;
}
int main() {
    double x, x1 = 0, x2 = 100, y;
    x = x1 + (x2 - x1) / 2;
    y = f(x);
    while (fabs(y) > EPS) {
        if (y > 0) x2 = x;
        else x1 = x;
        x = x1 + (x2 - x1) / 2;
        y = f(x);
    }
    cout << x << endl;
}

int BinarySearch(int a[], int size, int p) {
    int L = 0;
    int R = size - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (a[mid] == p) return mid;
        else if (a[mid] > p)
            R = mid - 1;
        else L = mid + 1;
    }
    return -1;
}

int LowerBound(int a[], int size, int p) {//找到比P小的，下标最大的元素
    int L = 0;
    int R = size - 1;
    int LastPos = -1; //到目前为止的最优解
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (a[mid] >= p) R = mid - 1;
        else {
            LastPos = mid;
            L = mid + 1;
        }
    }
    return LastPos;
}
