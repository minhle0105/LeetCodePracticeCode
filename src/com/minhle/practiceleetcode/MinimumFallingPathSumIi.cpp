class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int n = static_cast<int>(grid.size());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int c = 0; c < n; ++c)
        {
            res = min(res, recursion(grid, 0, c, n, dp));
        }
        return res;
    }
    
    int recursion(const vector<vector<int>> &grid, int r, int c, const int n, vector<vector<int>> &dp)
    {
        if (r == n - 1)
        {
            return grid[r][c];
        }
        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }

        int res = INT_MAX;

        for (int next_c = 0; next_c < n; ++next_c)
        {
            if (next_c == c)
            {
                continue;
            }
            res = min(res, recursion(grid, r + 1, next_c, n, dp));
        }
        dp[r][c] = res + grid[r][c];
        return dp[r][c];

    }
};
