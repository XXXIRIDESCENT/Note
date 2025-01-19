#include <string>
using namespace std;

class Solution {
public:
    long long countNums(int len, int max)
    {
        if (len == 0)
        {
            return 1;
        }

        long long res = 0;
        for (int i = 1; i <= max && i <= len; ++i)
        {
            res += countNums(len - i, max);
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
        int n = pressedKeys.size();
        int count = 1;
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