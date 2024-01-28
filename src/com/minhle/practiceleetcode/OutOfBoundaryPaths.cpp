#include "AllNecessaryHeaders.h"

class Solution {
public:
    const vector<int> dR = {0,1,0,-1};
    const vector<int> dC = {1,0,-1,0};
    const int MODULO = 1000000007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        map<pair<pair<int, int>, int>, int> dp; // store the number of way to get out of bound from cell <i, j> within k steps

        recursion(m, n, maxMove, startRow, startColumn, dp);
        return dp[{{startRow, startColumn}, maxMove}];
    }

    int recursion(int m, int n, int remaining_move, int current_row, int current_col,
                  map<pair<pair<int, int>, int>, int> &dp)
    {
        if (current_row < 0 || current_col < 0 || current_row >= m || current_col >= n)
        {
            return 1;
        }

        if (remaining_move == 0)
        {
            return 0;
        }

        if (dp.find({{current_row, current_col}, remaining_move}) != dp.end())
        {
            return dp[{{current_row, current_col}, remaining_move}];
        }
        int count = 0;
        for (int i = 0; i < 4; ++i)
        {
            int next_row = current_row + dR[i];
            int next_col = current_col + dC[i];
            count += recursion(m, n, remaining_move - 1, next_row, next_col, dp);
            count %= MODULO;
        }
        dp[{{current_row, current_col}, remaining_move}] = count % MODULO;
        return dp[{{current_row, current_col}, remaining_move}];
    }
};
