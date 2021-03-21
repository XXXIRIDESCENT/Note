#include<iostream>
using namespace std;
void Merge(int a[], int x, int m, int y, int tmp[]) {//将a[x,m]和a[m+i,y]合并到tmp，然后再copy回a[x,m]
    int i = 0;
    int p1 = x, p2 = m + 1;
    while (p1 <= m && p2 <= y) {
        if (a[p1] < a[p2])
            tmp[i++] = a[p1++];
        else
            tmp[i++] = a[p2++];
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
    int a[] = { 13,27,19,2,8,12,2,8,30,89 };
    int b[10];
    int size = 10;
    MergeSort(a, 0, size - 1, b);
    for (int i;i < size;i++)
        cout << a[i] << " ";
    cout << endl;
}

