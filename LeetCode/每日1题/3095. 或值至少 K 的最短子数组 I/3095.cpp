#include <vector>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum |= nums[j];
                if (sum >= k)
                {
                    dp[i][j] = true;
                    break;
                }
            }
        }

        int ret = 51;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (dp[i][j])
                {
                    ret = min(ret, j - i + 1);
                    break;
                }
            }
        }

        return ret != 51 ? ret : -1;
    }
};