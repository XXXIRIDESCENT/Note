#include<iostream>
using namespace std;
long long cnt = 0; //计数器
void Merge(int a[], int x, int m, int y, int tmp[]) {
    int i = 0;
    int p1 = x, p2 = m + 1;
    while (p1 <= m && p2 <= y) {
        if (a[p1] < a[p2])
            tmp[i++] = a[p1++];
        else {
            tmp[i++] = a[p2++];
            cnt += m - p1 + 1; //相比归并排序仅添加此句
        }
    }
    while (p1 <= m)
        tmp[i++] = a[p1++];
    while (p2 <= y)
        tmp[i++] = a[p2++];
    for (i = 0;i < y - x + 1;i++)
        a[x + i] = tmp[i];
}
void MergeSort(int a[], int x, int y, int tmp[]) { //复杂度O(nlogn)
    if (x < y) {
        int m = x + (y - x) / 2;
        MergeSort(a, x, m, tmp);
        MergeSort(a, m + 1, y, tmp);
        Merge(a, x, m, y, tmp);
    }
}
int main() {
    int a[100001], b[100001], n;
    cin >> n;
    for (int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    MergeSort(a, 0, n - 1, b);
    cout << cnt;
    system("pause");
}