#include "AllNecessaryHeaders.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            int last_updated = nums[i] + i;
            for (int j = i + 1; j <= last_updated; ++j)
            {
                if (j == nums.size())
                {
                    break;
                }
                if (dp[j] != 0)
                {
                    continue;
                }
                dp[j] = dp[i] + 1;
            }
        }
        return dp.back();
    }
};
