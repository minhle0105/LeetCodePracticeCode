#include "AllNecessaryHeaders.h"

class Solution {
public:
    const int MOD = pow(10, 9) + 7;

    int numberOfWays(int startPos, int endPos, int k) {
        map<pair<int, int>, int> dp;
        return recursion(endPos, startPos, k, dp);
    }

    int recursion(int end, int current_pos, int k, map<pair<int, int>, int> &dp)
    {
        if (abs(current_pos - end) > k)
        {
            return 0;
        }
        if (k == 0)
        {
            return current_pos == end ? 1 : 0;
        }

        if (dp.find({k, current_pos}) != dp.end())
        {
            return dp[{k, current_pos}];
        }

        int res = recursion(end, current_pos + 1, k - 1, dp) + recursion(end, current_pos - 1, k - 1, dp);
        dp[{k, current_pos}] = res % MOD;
        return dp[{k, current_pos}];
    }
};
