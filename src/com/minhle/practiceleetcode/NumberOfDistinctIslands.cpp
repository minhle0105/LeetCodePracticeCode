#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        island_paths.clear();
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> cells;
        string path;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    dfs(grid, visited, cells, i, j);
                    island_paths.insert(generate_path_hashing(cells, 0, path));
                    path = "";
                    cells.clear();
                }
            }
        }
        return island_paths.size();
    }
private:
    unordered_set<string> island_paths;
    int m;
    int n;
    const vector<int> dR = {0,1,0,-1};
    const vector<int> dC = {1,0,-1,0};

    void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<pair<int, int>> &cells, int i, int j)
    {
        cells.push_back({i, j});
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k)
        {
            int next_i = i + dR[k];
            int next_j = j + dC[k];
            bool in_bound = next_i >= 0 && next_j >= 0 && next_i < m && next_j < n;
            if (in_bound && !visited[next_i][next_j] && grid[next_i][next_j] == 1)
            {
                dfs(grid, visited, cells, next_i, next_j);
            }
        }
    }
    string generate_path_hashing(const vector<pair<int, int>> &cells, int i, string &path)
    {
        if (i == cells.size())
        {
            return path;
        }
        if (i == 0)
        {
            path += "<0,0>";
        }
        else
        {
            auto current_cell = cells[i];
            auto prev_cell = cells[i - 1];
            auto diff_row = current_cell.first - prev_cell.first;
            auto diff_col = current_cell.second - prev_cell.second;
            path += "<";
            path += to_string(diff_row);
            path += ",";
            path += to_string(diff_col);
            path += ">";
        }
        return generate_path_hashing(cells, i + 1, path);
    }
};
