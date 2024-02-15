class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<pair<int, int>, int> dp;
        int res = INT_MAX;
        for (int c = 0; c < matrix[0].size(); ++c)
        {
            res = min(res, recursion(matrix, 0, c, dp));
        }
        return res;
    }

    int recursion(const vector<vector<int>> &matrix, int r, int c, map<pair<int, int>, int> &dp)
    {
        if (r == matrix.size() - 1)
        {
            dp[{r, c}] = matrix[r][c];
            return dp[{r,c}];
        }
        if (dp.find({r, c}) != dp.end())
        {
            return dp[{r,c}];
        }
        int min_sum = INT_MAX;
        for (int i = -1; i <= 1; ++i)
        {
            int next_c = c + i;
            if (next_c >= 0 && next_c < matrix[r].size())
            {
                min_sum = min(min_sum, recursion(matrix, r + 1, next_c, dp));
            }
        }
        dp[{r,c}] = matrix[r][c];
        dp[{r,c}] += min_sum == INT_MAX ? 0 : min_sum;
        return dp[{r,c}];
    }
};
