#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        recursion(matrix, 0, 0, m, n, dp);
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res = max(res, dp[i][j] * dp[i][j]);
            }
        }
        return res;
    }

    int recursion(const vector<vector<char>> &matrix, int i, int j, const int m, const int n, vector<vector<int>> &dp)
    {
        if (i == m || j == n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        auto right = recursion(matrix, i, j + 1, m, n, dp);
        auto down = recursion(matrix, i + 1, j, m, n, dp);
        auto diag = recursion(matrix, i + 1, j + 1, m, n, dp);

        if (matrix[i][j] == '1')
        {
            dp[i][j] = 1 + min_triplet(right, down, diag);
        }
        else
        {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int min_triplet(int a, int b, int c)
    {
        return min(a, min(b, c));
    }
};
