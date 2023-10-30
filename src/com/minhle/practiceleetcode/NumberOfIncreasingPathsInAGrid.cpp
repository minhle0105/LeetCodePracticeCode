#include <vector>

using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int nRows = grid.size();
        int nCols = grid.at(0).size();

        vector<vector<int>> dp(nRows, vector<int>(nCols, -1));
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nCols; ++j)
            {
                dfs(grid, i, j, nRows, nCols, dp);
            }
        }
        int res = 0;
        for (const vector<int> &row : dp)
        {
            for (int num : row)
            {
                res += num;
                res %= modulo;
            }
        }
        return res;
    }
private:
    vector<int> dR = {1, 0, -1, 0};
    vector<int> dC = {0, 1, 0, -1};
    const long long modulo = pow(10, 9) + 7;

    int dfs(const vector<vector<int>> &grid, int r, int c, int nRows, int nCols, vector<vector<int>> &dp)
    {
        if (dp.at(r).at(c) != -1)
        {
            return dp.at(r).at(c);
        }
        int res = 1;
        for (int i = 0; i < 4; ++i)
        {
            int nextRow = r + dR[i];
            int nextCol = c + dC[i];
            bool in_bound = nextRow >= 0 && nextRow < nRows && nextCol >= 0 && nextCol < nCols;
            if (in_bound)
            {
                if (grid.at(nextRow).at(nextCol) < grid.at(r).at(c))
                {
                    res += dfs(grid, nextRow, nextCol, nRows, nCols, dp);
                    res %= modulo;
                }
            }
        }
        dp.at(r).at(c) = res;
        return res;
    }
};
