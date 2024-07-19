class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;

        vector<vector<int>> min_by_row;
        min_by_row.reserve(matrix.size());
        for (int i = 0; i < matrix.size(); ++i)
        {
            min_by_row.push_back(find_min_by_row(matrix[i], i));
        }
        for (const auto &cell : min_by_row)
        {
            int col = cell.back();
            int max_at_this_col = find_max_at_col(matrix, col);
            if (max_at_this_col == cell.front())
            {
                res.push_back(cell.front());
            }
        }
        return res;
    }

    int find_max_at_col(const vector<vector<int>> &matrix, int col)
    {
        int res = INT_MIN;
        for (int r = 0; r < matrix.size(); ++r)
        {
            res = max(res, matrix[r][col]);
        }
        return res;
    }

    vector<int> find_min_by_row(const vector<int> &row, const int row_id)
    {
        int min_num = row[0];
        int min_ind = 0;
        for (int i = 1; i < row.size(); ++i)
        {
            if (row[i] < min_num)
            {
                min_num = row[i];
                min_ind = i;
            }
        }

        return {min_num, row_id, min_ind};
    }
};
