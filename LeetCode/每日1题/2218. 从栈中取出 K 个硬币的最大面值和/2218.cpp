#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 参考题解改的面目全非，需要重新理解
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int pilesSize = piles.size();
        vector<vector<int>> sum(pilesSize);
        for (int i = 0; i < pilesSize; ++i)
        {
            sum[i].push_back(0);
            int size = piles[i].size();
            for (int j = 0; j < size; ++j)
            {
                sum[i].push_back(sum[i].back() + piles[i][j]);
            }
        }
        // dp[i][j]表示从前i个堆栈取j个硬币的最大价值
        vector<vector<int>> dp(pilesSize + 1, vector<int>(k + 1, 0));
        dp[1][1] = piles[0][0];
        
        for (int i = 1; i <= pilesSize; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                int m = std::min(static_cast<int>(piles[i - 1].size()), j);
                for (int p = 0; p <= m; p++) 
                {
                    dp[i][j] = max(dp[i][j], sum[i - 1][p] + dp[i - 1][j - p]);
                }
            }
        }
        return dp[pilesSize][k];
    }
};