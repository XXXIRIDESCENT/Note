#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // priority_queue<long long, vector<long long>, greater<long long>> pq;
        // for (int &i : nums)
        // {
        //     pq.push(i);
        // }

        // 优化：使用构造函数初始化
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        
        int count = 0;
        while (pq.top() < k && pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            pq.push(a * 2 + b);
            count++;
        }
        return count;
    }
};