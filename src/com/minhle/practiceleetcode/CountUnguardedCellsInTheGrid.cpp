class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const auto &wall : walls)
        {
            grid[wall[0]][wall[1]] = -1;
        }
        for (const auto &guard : guards)
        {
            grid[guard[0]][guard[1]] = -2;
        }
        for (const auto &guard : guards)
        {
            int r = guard[0];
            int c = guard[1];
            for (int i = r + 1; i < m; ++i)
            {
                if (grid[i][c] < 0)
                {
                    break;;
                }
                grid[i][c] = 1;
            }
            for (int i = r - 1; i >= 0; --i)
            {
                if (grid[i][c] < 0)
                {
                    break;
                }
                grid[i][c] = 1;
            }
            for (int i = c + 1; i < n; ++i)
            {
                if (grid[r][i] < 0)
                {
                    break;
                }
                grid[r][i] = 1;
            }
            for (int i = c - 1; i >= 0; --i)
            {
                if (grid[r][i] < 0)
                {
                    break;
                }
                grid[r][i] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res += grid[i][j] == 0;
            }
        }
        return res;
    }
};
