#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int n = piles.size() / 3;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += piles[i * 2 + 1];
        }
        return res;
    }
};