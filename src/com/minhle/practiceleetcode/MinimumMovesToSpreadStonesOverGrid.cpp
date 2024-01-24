#include "AllNecessaryHeaders.h"

class Solution {
public:
    int res;
    int minimumMoves(vector<vector<int>>& grid) {
        res = INT_MAX;
        nRows = grid.size();
        nCols = grid[0].size();

        backtracking(grid, 0, 0, 0);
        return res;
    }
private:
    int nRows;
    int nCols;
    int get_distance(const pair<int, int> &cell1, const pair<int, int> &cell2)
    {
        return abs(cell1.first - cell2.first) + abs(cell1.second - cell2.second);
    }

    void backtracking(vector<vector<int>> &grid, int i, int j, int cumulative_distance)
    {
        if (i == nRows)
        {
            res = min(res, cumulative_distance);
            return;
        }
        if (j == nCols)
        {
            backtracking(grid, i + 1, 0, cumulative_distance);
            return;
        }

        if (grid[i][j] != 0)
        {
            backtracking(grid, i, j + 1, cumulative_distance);
        }
        else
        {
            for (int r = 0; r < nRows; ++r)
            {
                for (int c = 0; c < nCols; ++c)
                {
                    if (grid[r][c] > 1)
                    {
                        ++grid[i][j];
                        --grid[r][c];
                        int distance = get_distance({i, j}, {r, c});
                        cumulative_distance += distance;
                        backtracking(grid, i, j + 1, cumulative_distance);
                        cumulative_distance -= distance;
                        ++grid[r][c];
                        --grid[i][j];
                    }
                }
            }
        }
    }
};
