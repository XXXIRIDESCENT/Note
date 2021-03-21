#include<iostream>
using namespace std;
int pow1(int a, int b) { //快速求a^b,复杂度为log(b)
    if (b == 0) return 1;
    if (b & 1) { //b是奇数
        return a * pow(a, b - 1);
    }
    else{
        int t = pow(a, b / 2);
        return t * t;
    }
}
int pow2(int a, int b) {
    int result = 1;
    int base = a;
    while (b) {
        if (b & 1)
            result *= base;
        base *= base;
        b >>= 1;
    }
    return result;
}
int main(){
    cout << pow1(2,5) << endl;
    cout << pow2(2,5) << endl;
}