class Solution {
public:
    const vector<int> dR = {0, 1, 0, -1};
    const vector<int> dC = {1, 0, -1, 0};
    map<pair<int, int>, int> regions;
    unordered_map<int, int> areas;
    vector<vector<bool>> visited;
    int res;
    int m;
    int n;

    int largestIsland(vector<vector<int>>& grid) {
        res = 0;
        m = grid.size();
        n = grid[0].size();
        regions.clear();
        areas.clear();

        visited.resize(m, vector<bool>(n, false));
        int region_id = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    bfs(grid, i, j, region_id);
                    ++region_id;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    find_max_connected_islands(grid, i, j);
                }
            }
        }
        return res;
    }

    void find_max_connected_islands(const vector<vector<int>> &grid, int i, int j)
    {
        unordered_set<int> surrounding_regions;
        for (int k = 0; k < 4; ++k)
        {
            int next_i = i + dR[k];
            int next_j = j + dC[k];
            bool in_bound = next_i >= 0 && next_j >= 0 && next_i < m && next_j < n;
            if (in_bound)
            {
                if (grid[next_i][next_j] == 1)
                {
                    surrounding_regions.insert(regions[{next_i, next_j}]);
                }
            }
        }
        int connected_area = 0;
        for (int region : surrounding_regions)
        {
            connected_area += areas[region];
        }
        res = max(res, 1 + connected_area);
    }

    void bfs(const vector<vector<int>> &grid, int r, int c, int region_id)
    {
        queue<pair<int, int>> q;
        q.push({r, c}); 
        visited[r][c] = true;
        regions[{r, c}] = region_id;
        int area = 1;

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;

            for (int i = 0; i < 4; ++i)
            {
                int next_x = x + dR[i];
                int next_y = y + dC[i];
                bool in_bound = next_x >= 0 && next_x < m && next_y >= 0 && next_y < n;
                if (in_bound && grid[next_x][next_y] == 1 && !visited[next_x][next_y])
                {
                    ++area;
                    q.push({next_x, next_y});
                    visited[next_x][next_y] = true;
                    regions[{next_x, next_y}] = region_id;
                }
            }
        }
        areas[region_id] = area;
        res = max(res, area);
    }
};
