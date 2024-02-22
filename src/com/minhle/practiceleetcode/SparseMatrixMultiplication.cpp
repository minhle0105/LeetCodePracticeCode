#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int n = mat2[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < mat1.size(); ++i)
        {
            auto row = mat1[i];
            for (int j = 0; j < mat2[0].size(); ++j)
            {
                int sum = 0;
                for (int r = 0; r < mat2.size(); ++r)
                {
                    sum += row[r] * mat2[r][j];
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};
