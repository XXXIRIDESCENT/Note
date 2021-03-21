#include<iostream>
using namespace std;
void QuickSort(int a[], int x, int y) {
    if (x >= y) return;
    int i = x, j = y, k = a[x];
    while (i < j) {
        while (i < j && a[j] >= k)
            j--;
        swap(a[i], a[j]);
        while (i < j && a[i] < k)
            i++;
        swap(a[i], a[j]);
    }
    QuickSort(a, x, i - 1);
    QuickSort(a, i + 1, y);
}

void QuickSort1(int a[], int x, int y) { //更优方案
    if (x >= y) return;
    int i = x, j = y, k = a[x];
    while (i < j) {
        while (i < j && a[j] >= k)
            j--;
        if(i < j) a[i++] = a[j]; //swap(a[i], a[j]);
        while (i < j && a[i] < k)
            i++;
        if(i < j) a[j--] = a[i]; //swap(a[i], a[j]);
    }
    a[i] = k;
    QuickSort1(a, x, i - 1);
    QuickSort1(a, i + 1, y);
}

int main() {
    int a[] = { 2,93,43,23,8,0,30,77,35,50 };
    QuickSort(a, 0, 9);
    for (int i = 0;i < 10;i++)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}