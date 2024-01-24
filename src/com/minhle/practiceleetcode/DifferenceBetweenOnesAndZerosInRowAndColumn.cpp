#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int, int> ones_by_rows;
        unordered_map<int, int> ones_by_cols;
        unordered_map<int, int> zeroes_by_rows;
        unordered_map<int, int> zeroes_by_cols;

        for (int r = 0; r < grid.size(); ++r)
        {
            int count_one = 0;
            int count_zero = 0;
            for (int c = 0; c < grid[r].size(); ++c)
            {
                if (grid[r][c] == 0)
                {
                    ++count_zero;
                }
                else
                {
                    ++count_one;
                }
            }
            ones_by_rows[r] = count_one;
            zeroes_by_rows[r] = count_zero;
        }

        for (int c = 0; c < grid[0].size(); ++c)
        {
            int count_one = 0;
            int count_zero = 0;
            for (int r = 0; r < grid.size(); ++r)
            {
                if (grid[r][c] == 0)
                {
                    ++count_zero;
                }
                else
                {
                    ++count_one;
                }
            }
            ones_by_cols[c] = count_one;
            zeroes_by_cols[c] = count_zero;
        }

        vector<vector<int>> diff(grid.size(), vector<int>(grid[0].size(), 0));
        for (int r = 0; r < diff.size(); ++r)
        {
            for (int c = 0; c < diff[r].size(); ++c)
            {
                diff[r][c] = ones_by_rows[r] + ones_by_cols[c] - zeroes_by_rows[r] - zeroes_by_cols[c];
            }
        }
        return diff;
    }
};

