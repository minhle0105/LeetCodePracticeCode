#include "AllNecessaryHeaders.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(s.size(), vector<int>(n, 0));
        recursion(s, 0, n - 1, dp);
        return dp[0][n - 1];
    }

    int recursion(const string &s, int start, int end, vector<vector<int>> &dp)
    {
        if (start > end)
        {
            return 0;
        }
        if (start == end)
        {
            dp[start][end] = 1;
            return 1;
        }
        if (dp[start][end] != 0)
        {
            return dp[start][end];
        }
        if (s[start] == s[end])
        {
            dp[start][end] = 2 + recursion(s, start + 1, end - 1, dp);
        }
        else
        {
            dp[start][end] = max(recursion(s, start + 1, end, dp), recursion(s, start, end - 1, dp));
        }
        return dp[start][end];
    }
};
