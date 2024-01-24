#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res[i][j] = img[i][j];
            }
        }
        smooth(img, res, 0, 0, m, n);
        return res;
    }
private:
    const vector<int> dR = {0,1,-1,0,1,-1,1,-1};
    const vector<int> dC = {1,0,0,-1,1,1,-1,-1};

    void smooth(const vector<vector<int>> &img, vector<vector<int>> &res, int i, int j, int m, int n)
    {
        if (i == m)
        {
            return;
        }
        if (j == n)
        {
            smooth(img, res, i + 1, 0, m, n);
            return;
        }
        int count_cell = 1;
        int sum = res[i][j];
        for (int k = 0; k < 8; ++k)
        {
            int next_i = i + dR[k];
            int next_j = j + dC[k];
            bool in_bound = next_i >= 0 && next_j >= 0 && next_i < m && next_j < n;
            if (in_bound)
            {
                sum += img[next_i][next_j];
                ++count_cell;
            }
        }
        res[i][j] = sum / count_cell;
        smooth(img, res, i, j + 1, m, n);
    }
};
