#include <vector>
using namespace std;

// 解法同3095.cpp（暴力枚举）
// 优化逻辑
// 1.不使用二维数组存储（28.16MB -> 26.74MB），效果不明显
// 2.仅遍历一遍（3ms -> 3ms），无效果

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n + 1;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum |= nums[j];
                if (sum >= k)
                {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == n + 1 ? -1 : res;
    }
};