#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        return play(piles, 0, piles.size() - 1, true, dp) > 0;
    }

    int play(const vector<int> &piles, int i, int j, bool alice, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != 0)
        {
            return dp[i][j];
        }
        pair<int, int> cases;
        if (alice)
        {
            cases.first = piles[i] + play(piles, i + 1, j, false, dp);
            cases.second = piles[j] + play(piles, i, j - 1, false, dp);
        }
        else
        {
            cases.first = piles[i] * (-1) + play(piles, i + 1, j, true, dp);
            cases.second = piles[j] * (-1) + play(piles, i, j - 1, true, dp);
        }
        dp[i][j] = max(cases.first, cases.second);
        return dp[i][j];
    }
};
