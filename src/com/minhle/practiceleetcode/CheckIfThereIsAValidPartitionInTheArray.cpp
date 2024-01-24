#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums, 0, dp);
    }

    bool dfs(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i == nums.size())
        {
            return true;
        }
        if (dp[i] != -1)
        {
            return dp[i] == 1;
        }
        if (i < nums.size() - 1 && nums[i] == nums[i + 1])
        {
            if(dfs(nums, i + 2, dp))
            {
                dp[i] = 1;
                return true;
            }
        }
        if (i < nums.size() - 2)
        {
            if ((nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) ||
                (nums[i] + 1 == nums[i + 1] && nums[i + 1] == nums[i + 2] - 1))
                {
                    if(dfs(nums, i + 3, dp))
                    {
                        dp[i] = 1;
                        return true;
                    }
                }
        }
        dp[i] = 0;
        return false;
    }
};