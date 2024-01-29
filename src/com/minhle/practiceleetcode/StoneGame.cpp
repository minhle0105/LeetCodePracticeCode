#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        return play(piles, 0, piles.size() - 1, 1, dp) > 0;
    }

    int play(const vector<int> &piles, int i, int j, int alice, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != 0)
        {
            return dp[i][j];
        }
        dp[i][j] = max(piles[i] * alice + play(piles, i + 1, j, alice * (-1), dp),
                       piles[j] * alice + play(piles, i, j - 1, alice * (-1), dp));
        return dp[i][j];
    }
};
