#include <string>
#include <vector>
using namespace std;

// 使用递归的方式计算方案数会超时，因此改为数组存储已经计算过的方案数
class Solution {
public:
    vector<long long> vecFor3;
    vector<long long> vecFor4;
    long long countNums(int len, int max)
    {
        if (len == 0)
        {
            return 1;
        }

        long long res = 0;
        for (int i = 1; i <= max && i <= len; ++i)
        {
            if (max == 3)
            {
                if (vecFor3[len - i] != 0)
                {
                    res += vecFor3[len - i];
                }
                else
                {
                    res += countNums(len - i, max);
                    vecFor3[len - i] = res;
                }
            }
            else
            {
                if (vecFor4[len - i] != 0)
                {
                    res += vecFor4[len - i];
                }
                else
                {
                    res += countNums(len - i, max);
                    vecFor4[len - i] = res;
                }
            }
        }
        return res % 1000000007;
    }

    int countTexts(string pressedKeys) {

        auto getNum = [&](char c) -> int
        {
            if (c == '7' || c == '9')
            {
                return 4;
            }
            return 3;
        };

        long long res = 1;
        int count = 1;
        int n = pressedKeys.size();
        vecFor3.resize(n + 1);
        vecFor3.clear();
        vecFor4.resize(n + 1);
        vecFor4.clear();
        for (int i = 1; i < n; ++i)
        {
            if (pressedKeys[i] == pressedKeys[i - 1])
            {
                count++;
            }
            else
            {
                res *= countNums(count, getNum(pressedKeys[i - 1]));
                res %= 1000000007;
                count = 1;
            }
        }
        res *= countNums(count, getNum(pressedKeys[n - 1]));
        res %= 1000000007;
        return res;
    }
};