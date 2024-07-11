class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto count_x_by_matrix = get_count_by_matrix(grid, 'X');
        auto count_y_by_matrix = get_count_by_matrix(grid, 'Y');

        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res += count_x_by_matrix[i][j] == count_y_by_matrix[i][j] && count_x_by_matrix[i][j] > 0;
            }
        }
        return res;
    }

    vector<vector<int>> get_count_by_matrix(const vector<vector<char>> &grid, char target)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> count_by_row(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r)
        {
            count_by_row[r][0] = grid[r][0] == target ? 1 : 0;
            for (int c = 1; c < n; ++c)
            {
                count_by_row[r][c] = count_by_row[r][c - 1] + (grid[r][c] == target);
            }
        }

        vector<vector<int>> count_by_matrix(m, vector<int>(n, 0));

        count_by_matrix[0] = count_by_row[0];

        for (int r = 1; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                if (c == 0)
                {
                    count_by_matrix[r][c] = count_by_matrix[r - 1][c] + (grid[r][c] == target);
                }
                else
                {
                    count_by_matrix[r][c] = count_by_matrix[r - 1][c] + count_by_row[r][c];
                }
            }
        }
        return count_by_matrix;
    }
};
