#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ret = 0;
        // 使用 long long 类型来避免整数溢出，并在调用 accumulate 时使用 0LL 作为初始值，以确保累加结果是 long long 类型
        long long rightTotal = accumulate(nums.begin(), nums.end(), 0LL);
        long long leftTotal = 0;
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i)
        {
            leftTotal += nums[i];
            rightTotal -= nums[i];
            if (leftTotal >= rightTotal)
            {
                ret++;
            }
        }
        return ret;
    }
};