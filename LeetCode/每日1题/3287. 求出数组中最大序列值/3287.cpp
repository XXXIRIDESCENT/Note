#include <vector>
using namespace std;

// 未解决，先创建文件占位
class Solution {
public:
    int countBit(int x) {
        int res = 0;
        while (x) {
            x >>= 1;
            ++res;
        }
        return res;
    }

    int getBit(int x, int i) {
        return (x >> (i - 1)) & 1;
    }

    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        int max = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        int res = 0;
        for (int i = countBit(max); i > 0; --i) {
            
            res <<= 1;
        }
        return res;
    }
};