class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return dfs(grid, 0, 0, 1);
    }
    
    bool dfs(const vector<vector<int>> &grid, int r, int c, int count)
    {   
        if (count == m * n)
        {
            return true;
        }

        int next_value = grid[r][c] + 1;
        for (int i = 0; i < 8; ++i)
        {
            int next_r = r + dR[i];
            int next_c = c + dC[i];
            if (next_r >= 0 && next_c >= 0 && next_r < m && next_c < n)
            {
               if (grid[next_r][next_c] == next_value)
               {
                   return dfs(grid, next_r, next_c, count + 1);
               }
            }
        }
        
        return false;
    }
private:
    const vector<int> dR = {1, 2, 2, 1, -1, -2, -1, -2};
    const vector<int> dC = {2, 1, -1, -2, -2, -1, 2, 1};
    int m = 0;
    int n = 0;
};
