#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        map<pair<int, int>, int> dp;
        max_diff_score(nums, 0, nums.size() - 1, dp);
        return dp[{0, nums.size() - 1}] >= 0;
    }

    int max_diff_score(const vector<int> &nums, int i, int j, map<pair<int, int>, int> &dp)
    {
        if (i == j)
        {
            return nums[i];
        }
        if (dp.find({i, j}) != dp.end())
        {
            return dp[{i, j}];
        }
        auto take_left = nums[i] - max_diff_score(nums, i + 1, j, dp);
        auto take_right = nums[j] - max_diff_score(nums, i, j - 1, dp);
        dp[{i, j}] = max(take_left, take_right);
        // max(take_left, take_right) because from perspective of player 1, he wants to maximize the score difference
        // and from perspective of player 2, he wants to minimize the score difference
        return dp[{i, j}];
    }
};
