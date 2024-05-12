class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, -1));
        for (int i = 0; i < maxLocal.size(); ++i)
        {
            for (int j = 0; j < maxLocal.size(); ++j)
            {
                maxLocal[i][j] = find_max_value(grid, i + 1, j + 1);
            }
        }
        return maxLocal;
    }
private:
    int find_max_value(const vector<vector<int>> &grid, int r, int c)
    {
        int res = INT_MIN;
        for (int i = r - 1; i <= r + 1; ++i)
        {
            for (int j = c - 1; j <= c + 1; ++j)
            {
                res = max(res, grid[i][j]);
            }
        }
        return res;
    }
};
