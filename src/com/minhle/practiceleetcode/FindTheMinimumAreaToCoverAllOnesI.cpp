class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int top_row = 0;
        while (top_row < m)
        {
            bool this_row_has_one = false;
            for (int col = 0; col < n; ++col)
            {
                if (grid[top_row][col] == 1)
                {
                    this_row_has_one = true;
                    break;
                }
            }
            if (this_row_has_one)
            {
                break;
            }
            ++top_row;
        }

        int bottom_row = m - 1;
        while (bottom_row >= 0)
        {
            bool this_row_has_one = false;
            for (int col = 0; col < n; ++col)
            {
                if (grid[bottom_row][col] == 1)
                {
                    this_row_has_one = true;
                    break;
                }
            }
            if (this_row_has_one)
            {
                break;
            }
            --bottom_row;
        }

        int left_col = 0;
        while (left_col < n)
        {
            bool this_col_has_one = false;
            for (int r = 0; r < m; ++r)
            {
                if (grid[r][left_col] == 1)
                {
                    this_col_has_one = true;
                    break;
                }
            }
            if (this_col_has_one)
            {
                break;
            }
            ++left_col;
        }

        int right_col = n - 1;
        while (right_col >= 0)
        {
            bool this_col_has_one = false;
            for (int r = 0; r < m; ++r)
            {
                if (grid[r][right_col] == 1)
                {
                    this_col_has_one = true;
                    break;
                }
            }
            if (this_col_has_one)
            {
                break;
            }
            --right_col;
        }

        return (bottom_row - top_row + 1) * (right_col - left_col + 1);
    }
};
