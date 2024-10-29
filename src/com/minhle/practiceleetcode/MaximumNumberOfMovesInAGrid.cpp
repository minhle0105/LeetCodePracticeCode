class Solution {
public:
    int m;
    int n;
    const vector<int> dR = {-1, 0, 1};
    const vector<int> dC = {1, 1, 1};
    vector<vector<int>> dp;
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        int res = 0;
        for (int r = 0; r < m; ++r)
        {
            res = max(res, dfs(grid, r, 0));
        }
        return res;
    }

    int dfs(const vector<vector<int>> &grid, int r, int c)
    {
        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }
        vector<int> all_move_counts = {0, 0, 0};
        for (int i = 0; i < 3; ++i)
        {
            int next_r = r + dR[i];
            int next_c = c + dC[i];
            bool in_bound = next_r >= 0 && next_c >= 0 && next_r < m && next_c < n;
            if (in_bound && grid[next_r][next_c] > grid[r][c])
            {
                all_move_counts[i] = 1 + dfs(grid, next_r, next_c);
            }
        }
        dp[r][c] = *max_element(all_move_counts.begin(), all_move_counts.end());
        return dp[r][c];
    }
};
