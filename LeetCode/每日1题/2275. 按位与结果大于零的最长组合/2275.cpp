#include <vector>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bit[24] = { 0 };
        for (int& candidate : candidates)
        {
            for (int i = 0; i < 24; ++i)
            {
                if (candidate & (1 << i))
                {
                    bit[i]++;
                }
            }
        }

        int max = 0;
        for (int& i : bit)
        {
            if (i > max)
            {
                max = i;
            }
        }
        return max;
    }
};