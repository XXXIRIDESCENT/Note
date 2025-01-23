#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int res = 0;
        int pos = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto succ = st.insert(s[i]);
            if (!succ.second)
            {
                res = max(int(st.size()), res);

                for (int j = pos; j < i; ++j)
                {
                    if (s[j] == s[i])
                    {
                        for (int k = pos; k <= j; ++k)
                        {
                            st.erase(s[k]);
                        }
                        pos = j + 1;
                        break;
                    }
                }
            }
        }
        return max(int(st.size()), res);
    }
};