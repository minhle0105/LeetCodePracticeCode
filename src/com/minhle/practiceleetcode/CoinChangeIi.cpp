class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount, -1));
        return recursive(coins, amount, 0, 0, dp);
    }

    int recursive(const vector<int> &coins, const int target_amount, int current_amount, int pos, vector<vector<int>> &dp)
    {
        if (current_amount == target_amount)
        {
            return 1;
        }
        if (current_amount > target_amount || pos == coins.size())
        {
            return 0;
        }
        if (dp[pos][current_amount] != -1)
        {
            return dp[pos][current_amount];
        }
        int use_this_coin = recursive(coins, target_amount, current_amount + coins[pos], pos, dp);
        int skip_this_coin = recursive(coins, target_amount, current_amount, pos + 1, dp);
        dp[pos][current_amount] = use_this_coin + skip_this_coin;
        return dp[pos][current_amount];
    }
};
