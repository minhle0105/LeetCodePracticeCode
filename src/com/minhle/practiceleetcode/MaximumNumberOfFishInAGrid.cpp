class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0 || visited[i][j])
                {
                    continue;
                }
                int score = 0;
                dfs(grid, i, j, score, visited);
                res = max(res, score);
            }
        }
        return res;
    }
private:
    const vector<int> dR = {0, 0, 1, -1};
    const vector<int> dC = {1, -1, 0, 0};
    int m = 0;
    int n = 0;

    void dfs(const vector<vector<int>> &grid, int r, int c, int &score, vector<vector<bool>> &visited)
    {
        if (r < 0 || c < 0 || r >= m || c >= n)
        {
            return;
        }    
        if (grid[r][c] == 0 || visited[r][c])
        {
            return;
        }
        score += grid[r][c];
        visited[r][c] = true;
        for (int i = 0; i < 4; ++i)
        {
            dfs(grid, r + dR[i], c + dC[i], score, visited);
        }
    }
};
