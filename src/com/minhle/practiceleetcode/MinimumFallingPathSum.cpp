#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        int res = INT_MAX;
        for (int c = 0; c < matrix[0].size(); ++c)
        {
            res = min(res, recursion(matrix, 0, c, dp));
        }
        return res;
    }

    int recursion(const vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp)
    {
        if (c < 0 || c == matrix[r].size())
        {
            return INT_MAX;
        }
        if (r == matrix.size() - 1)
        {
            dp[r][c] = matrix[r][c];
            return dp[r][c];
        }
        if (dp[r][c] != INT_MIN)
        {
            return dp[r][c];
        }
        int min_sum = INT_MAX;
        for (int i = -1; i <= 1; ++i)
        {
            min_sum = min(min_sum, recursion(matrix, r + 1, c + i, dp));
        }
        dp[r][c] = matrix[r][c] + min_sum;
        return dp[r][c];
    }
};