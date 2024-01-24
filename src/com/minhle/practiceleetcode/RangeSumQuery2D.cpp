#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int nRows = matrix.size();
        int nCols = matrix.at(0).size();
        vector<int> row(nCols + 1, 0);
        for (int i = 0; i <= nRows; ++i)
        {
            prefix_sum.push_back(row);
        }
        prefix_sum.at(1).at(1) = matrix.at(0).at(0);
        for (int i = 1; i < nCols; ++i)
        {
            prefix_sum.at(1).at(i + 1) = prefix_sum.at(1).at(i) + matrix.at(0).at(i);
        }
        for (int i = 1; i < nRows; ++i)
        {
            prefix_sum.at(i + 1).at(1) = prefix_sum.at(i).at(1) + matrix.at(i).at(0);
        }
        for (int i = 2; i <= nRows; ++i)
        {
            for (int j = 2; j <= nCols; ++j)
            {
                prefix_sum.at(i).at(j) = prefix_sum.at(i - 1).at(j) + prefix_sum.at(i).at(j - 1) + matrix.at(i - 1).at(j - 1) - prefix_sum.at(i - 1).at(j - 1);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total_sum = prefix_sum.at(row2 + 1).at(col2 + 1);
        int overlapped_sum = prefix_sum.at(row1).at(col1);
        int sum_row = prefix_sum.at(row1).at(col2 + 1);
        int sum_col = prefix_sum.at(row2 + 1).at(col1);
        return total_sum - sum_row - sum_col + overlapped_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
 
