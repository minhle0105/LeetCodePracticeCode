class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        
        backtracking(nums, target, 0, dp);
        return dp[0];
    }

    int backtracking(const vector<int> &nums, const int target, int current, unordered_map<int, int> &dp)
    {
        if (current == target)
        {
            return 1;
        }
        if (current > target)
        {
            return 0;
        }
        if (dp.find(current) != dp.end())
        {
            return dp[current];
        }
        dp[current] = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[current] += backtracking(nums, target, current + nums[i], dp);
        }
        return dp[current];
    }

};
