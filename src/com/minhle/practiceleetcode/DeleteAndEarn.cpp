#include "AllNecessaryHeaders.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> counter;
        int n = INT_MIN;
        for (int num : nums)
        {
            ++counter[num];
            n = max(n, num);
        }
        vector<int> dp(n + 1, 0);
        if (counter.find(1) != counter.end())
        {
            dp[1] = counter[1];
        }
        for (int i = 2; i < dp.size(); ++i)
        {
            if (counter.find(i) != counter.end())
            {
                dp[i] = max(i * counter[i] + dp[i - 2], dp[i - 1]);
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};

