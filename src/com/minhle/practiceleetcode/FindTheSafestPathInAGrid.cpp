class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
                else
                {
                    grid[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            for (int s = 0; s < size; ++s)
            {
                auto cell = q.front();
                q.pop();
                int r = cell.first;
                int c = cell.second;

                for (int i = 0; i < 4; ++i)
                {
                    int next_r = r + dR[i];
                    int next_c = c + dC[i];
                    bool in_bound = next_r >= 0 && next_c >= 0 && next_r < n && next_c < n;
                    if (in_bound)
                    {
                        if (grid[next_r][next_c] == -1)
                        {
                            grid[next_r][next_c] = grid[r][c] + 1;
                            q.push({next_r, next_c});
                        }
                    }
                }
            }
        }
        int left = 0;
        int right = abs(n - 1) + abs(n - 1);

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (path_exist(grid, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return path_exist(grid, right) ? right : left;
    }
private:
    int n;
    const vector<int> dR = {0, 1, 0, -1};
    const vector<int> dC = {1, 0, -1, 0};

    bool path_exist(const vector<vector<int>> &grid, int threshold)
    {
        if (grid[0][0] < threshold || grid[n - 1][n - 1] < threshold)
        {
            return false;
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        return dfs(grid, visited, 0, 0, threshold);
    }

    bool dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c, int threshold)
    {
        if (r == n - 1 && c == n - 1)
        {
            return true;
        }
        if (r < 0 || c < 0 || r >= n || c >= n)
        {
            return false;
        }
        if (visited[r][c] || grid[r][c] < threshold)
        {
            return false;
        }

        visited[r][c] = true;
        for (int i = 0; i < 4; ++i)
        {
            if (dfs(grid, visited, r + dR[i], c + dC[i], threshold))
            {
                return true;
            }
        }
        return false;
    }
};

