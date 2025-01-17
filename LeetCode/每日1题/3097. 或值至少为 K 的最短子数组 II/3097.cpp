#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bits = vector<int>(32, 0);

    void add(int num) 
    {
        for (int i = 0; i < 32 && num > 0; ++i) 
        {
            bits[i] += num & 1;
            num >>= 1;
        }
    }

    void remove(int num) 
    {
        for (int i = 0; i < 32 && num > 0; ++i) 
        {
            bits[i] -= num & 1;
            num >>= 1;
        }
    }

    int get()
    {
        int res = 0;
        for (int i = 31; i >= 0; --i) 
        {
            res <<= 1;
            if (bits[i] > 0) 
            {
                res |= 1;
            }
        }
        return res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int size = nums.size();
        int res = size + 1;
        for (; right < size; ++right) 
        {
            add(nums[right]);
            if (get() >= k) 
            {
                do {
                    remove(nums[left++]);
                } while (left <= right && get() >= k);
                res = min(res, right - (left - 1) + 1);
            }
        }
        return res == size + 1 ? -1 : res;
    }
};