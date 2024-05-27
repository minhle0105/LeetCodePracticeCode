class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if (m == 0)
        {
            return 0;
        }
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)));
        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 1)
                {
                    dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
                    dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;
                    dp[i][j][2] = (i > 0 && j > 0) ? dp[i - 1][j - 1][2] + 1 : 1;
                    dp[i][j][3] = (i > 0 && j < n - 1) ? dp[i - 1][j + 1][3] + 1 : 1;
                    res = find_max(res, dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]);
                }
            }
        }
        return res;
    }

    int find_max(int res, int a, int b, int c, int d)
    {
        return max(res, max(max(a, b), max(c, d)));
    }
};

