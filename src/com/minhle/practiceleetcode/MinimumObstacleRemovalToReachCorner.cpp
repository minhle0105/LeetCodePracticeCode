class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        const vector<int> dR = {0, 1, 0, -1};
        const vector<int> dC = {1, 0, -1, 0};
        
        deque<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> obstacles(m, vector<int>(n, -1));

        q.push_back({0, 0});
        visited[0][0] = true;
        obstacles[0][0] = 0;

        while (!q.empty())
        {
            auto cell = q.front();
            q.pop_front();
            int r = cell.first;
            int c = cell.second;
            if (r == m - 1 && c == n - 1)
            {
                return obstacles[r][c];
            }

            for (int i = 0; i < 4; ++i)
            {
                int next_r = r + dR[i];
                int next_c = c + dC[i];
                bool in_bound = next_r >= 0 && next_r < m && next_c >= 0 && next_c < n;

                if (in_bound && !visited[next_r][next_c])
                {
                    if (grid[next_r][next_c] == 0)
                    {
                        q.push_front({next_r, next_c});
                        obstacles[next_r][next_c] = obstacles[r][c];
                    }
                    else
                    {
                        q.push_back({next_r, next_c});
                        obstacles[next_r][next_c] = obstacles[r][c] + 1;
                    }
                    visited[next_r][next_c] = true;
                }
            }
        }
        return -1;
    }
};
