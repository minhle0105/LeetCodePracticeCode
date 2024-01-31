#include "AllNecessaryHeaders.h"

class Solution {
public:
    unordered_map<int, int> dp;
    int numTrees(int n) {
        dp.clear();
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            build_G(i);
        }
        return dp[n];
    }

    int build_G(int n)
    {
        if (dp.find(n) != dp.end())
        {
            return dp[n];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            res += solving_F(i, n);
        }
        dp[n] = res;
        return dp[n];
    }

    int solving_F(int i, int n)
    {
        auto left = i - 1;
        auto right = n - i;
        return dp[left] * dp[right];
    }
};
