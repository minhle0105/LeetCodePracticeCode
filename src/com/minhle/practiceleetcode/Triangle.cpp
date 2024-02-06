#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
        return recursion(triangle, 0, 0, dp);
    }

    int recursion(const vector<vector<int>> &triangle, int i, int row, vector<vector<int>> &dp)
    {
        if (row == triangle.size())
        {
            return 0;
        }
        if (dp[i][row] != -1)
        {
            return dp[i][row];
        }
        dp[i][row] = triangle[row][i] + min(recursion(triangle, i, row + 1, dp), recursion(triangle, i + 1, row + 1, dp));
        return dp[i][row];
    }
};
