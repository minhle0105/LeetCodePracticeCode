class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        vector<long long> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        long long res = 0;
        int i = 0;
        for (int i = 0; i < nums.size();)
        {
            int j = i + 1;
            while (j < nums.size() && dp[j] > dp[j - 1])
            {
                ++j;
            }
            res += ((1 + dp[j - 1]) * dp[j - 1]) / 2; 
            i = j;
        }
        return res;
    }
};
