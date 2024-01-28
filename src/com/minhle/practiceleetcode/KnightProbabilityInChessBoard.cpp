#include "AllNecessaryHeaders.h"

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> one_board_dp(n, vector<double>(n, -1.0));
        vector<vector<vector<double>>> dp(k + 1, one_board_dp);

        double res = 0.0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res += recursion(i, j, n, row, column, k, dp);
            }
        }
        return res;
    }

    double recursion(int current_row, int current_col,
                     const int n, const int start_row, const int start_col,
                     int remaining_moves, vector<vector<vector<double>>> &dp)
    {
        // out of bound check
        if (current_row < 0 || current_row >= n || current_col < 0 || current_col >= n)
        {
            return 0;
        }

        if (remaining_moves == 0)
        {
            // this is the case when we trace back to the beginning state, so if the cell is exactly the given
            // starting cell, it means that's the case we want --> prob = 1, else 0
            return (current_row == start_row && current_col == start_col) ? 1 : 0;
        }

        if (dp[remaining_moves][current_row][current_col] != -1)
        {
            // already calculated
            return dp[remaining_moves][current_row][current_col];
        }

        // mark calculated
        dp[remaining_moves][current_row][current_col] = 0;

        for (int i = 0; i < NUMBER_OF_DIRECTIONS; ++i)
        {
            int next_row = current_row + dR[i];
            int next_col = current_col + dC[i];
            dp[remaining_moves][current_row][current_col] += (recursion(next_row, next_col, n, start_row, start_col, remaining_moves - 1, dp) / NUMBER_OF_DIRECTIONS);
        }
        return dp[remaining_moves][current_row][current_col];
    }

private:
    const vector<int> dR = {1, 1, -1, -1, 2, 2, -2, -2};
    const vector<int> dC = {2, -2, 2, -2, 1, -1, 1, -1};
    const int NUMBER_OF_DIRECTIONS = static_cast<int>(dR.size());
};
