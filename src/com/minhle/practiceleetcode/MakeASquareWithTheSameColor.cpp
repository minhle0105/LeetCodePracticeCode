class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        vector<vector<int>> grid_(3, vector<int>(3, 0));
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (grid[i][j] == 'W')
                {
                    grid_[i][j] = 1;
                }
            }
        }
        return check(grid_, {0, 0}) ||
               check(grid_, {0, 1}) ||
               check(grid_, {1, 0}) || 
               check(grid_, {1, 1});
    }

    bool check(const vector<vector<int>> &grid, const pair<int, int> &top_left)
    {
        unordered_map<int, int> counter;
        int x = top_left.first;
        int y = top_left.second;
        ++counter[grid[x][y]];
        ++counter[grid[x][y + 1]];
        ++counter[grid[x + 1][y]];
        ++counter[grid[x + 1][y + 1]];
        return (counter[0] == 3 && counter[1] == 1) || 
               (counter[0] == 1 && counter[1] == 3) || 
               (counter[0] == 4 && counter[1] == 0) || 
               (counter[0] == 0 && counter[1] == 4);
    }
};
