#include <vector>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0];
        for (int &i : nums)
        {
            if (i == 0)
            {
                return 0;
            }
            else if (abs(i) < abs(res))
            {
                res = i;
            }
            else if (abs(i) == abs(res) && i > res)
            {
                res = i;
            }
        }
        return res;
    }
};