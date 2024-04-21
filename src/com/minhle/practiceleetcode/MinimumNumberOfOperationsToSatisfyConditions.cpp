class Solution {
public:
    vector<vector<int>> dp;

    int minimumOperations(vector<vector<int>>& grid) {
        dp.resize(grid[0].size(), vector<int>(10, -1));

        unordered_map<int, unordered_map<int, int>> counter_by_cols;

        for (int col = 0; col < grid[0].size(); ++col)
        {
            counter_by_cols[col] = unordered_map<int, int>{};
        }

        for (int col = 0; col < grid[0].size(); ++col)
        {
            for (int row = 0; row < grid.size(); ++row)
            {
                ++counter_by_cols[col][grid[row][col]];
            }
        }

        return recursive(counter_by_cols, 0, grid.size(), -1);
    }

    int recursive(unordered_map<int, unordered_map<int, int>> &counter_by_cols, int col, const int r, int previous_col_value)
    {
        if (counter_by_cols.find(col) == counter_by_cols.end())
        {
            return 0;
        }
        if (previous_col_value != -1 && dp[col][previous_col_value] != -1)
        {
            return dp[col][previous_col_value];
        }
        int res = INT_MAX;
        for (int i = 0; i <= 9; ++i)
        {
            if (previous_col_value == i)
            {
                continue;
            }
            int count_equal_values = counter_by_cols[col][i];
            int count_diff_values = r - count_equal_values;
            res = min(res, count_diff_values + recursive(counter_by_cols, col + 1, r, i));
        }
        if (previous_col_value != -1)
        {
            dp[col][previous_col_value] = res == INT_MAX ? 0 : res;
            return dp[col][previous_col_value];
        }
        return res == INT_MAX ? 0 : res;
    }
};
