class Solution {
public:
    const vector<int> dR = {0, 1, 0, -1};
    const vector<int> dC = {1, 0, -1, 0};
    vector<vector<bool>> visited;
    int m;
    int n;

    int getMaximumGold(vector<vector<int>>& grid) {
        int number_of_cells_to_visit = 0;
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                backtracking(grid, i, j, 0, 0, number_of_cells_to_visit, res);
            }
        }
        return res;
    }

    void backtracking(const vector<vector<int>> &grid, int r, int c, int current_gold, int nCells, const int number_of_cells_to_visited, int &res)
    {
        if (r < 0 || c < 0 || r >= m || c >= n)
        {
            return;
        }
        if (visited[r][c] || grid[r][c] == 0)
        {
            return;
        }
        visited[r][c] = true;
        current_gold += grid[r][c];
        res = max(res, current_gold);
        ++nCells;
        for (int i = 0; i < 4; ++i)
        {
            backtracking(grid, r + dR[i], c + dC[i], current_gold, nCells, number_of_cells_to_visited, res);
        }
        --nCells;
        current_gold -= grid[r][c];
        visited[r][c] = false;
    }
};
