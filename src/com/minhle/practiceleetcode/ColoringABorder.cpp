#include "AllNecessaryHeaders.h"

class Solution {
public:
    const vector<int> dR = {0,1,0,-1};
    const vector<int> dC = {1,0,-1,0};
    int m;
    int n;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> cells;
        int min_row = INT_MAX;
        int min_col = INT_MAX;

        int max_row = INT_MIN;
        int max_col = INT_MIN;

        dfs(grid, row, col, min_row, min_col, max_row, max_col, visited, cells);

        for (const auto &cell : cells)
        {
            int r = cell.first;
            int c = cell.second;
            bool on_the_boundary = r == min_row || r == max_row ||
                                   c == min_col || c == max_col;
            if (on_the_boundary)
            {
                grid[r][c] = color;
                continue;
            }
            bool adjacent_to_one_external_cell = false;
            for (int i = 0; i < 4; ++i)
            {
                int next_r = r + dR[i];
                int next_c = c + dC[i];
                bool in_bound = next_r >= 0 && next_c >= 0 && next_r < m && next_c < n;
                if (in_bound && !visited[next_r][next_c])
                {
                    adjacent_to_one_external_cell = true;
                    grid[r][c] = color;
                    break;
                }
            }
        }
        return grid;
    }

    void dfs(const vector<vector<int>> &grid, int r, int c, int &min_row, int &min_col, int &max_row, int &max_col,
             vector<vector<bool>> &visited, vector<pair<int, int>> &cells)
    {
        cells.push_back({r, c});
        min_row = min(r, min_row);
        min_col = min(c, min_col);
        max_row = max(r, max_row);
        max_col = max(c, max_col);
        visited[r][c] = true;

        for (int i = 0; i < 4; ++i)
        {
            auto next_r = r + dR[i];
            auto next_c = c + dC[i];
            bool in_bound = next_r >= 0 && next_c >= 0 && next_r < m && next_c < n;
            if (in_bound)
            {
                bool same_color = grid[next_r][next_c] == grid[r][c];
                if (same_color && !visited[next_r][next_c])
                {
                    dfs(grid, next_r, next_c, min_row, min_col, max_row, max_col, visited, cells);
                }
            }
        }
    }
};