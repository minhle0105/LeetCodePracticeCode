#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int, int> one_by_row;
        unordered_map<int, int> one_by_col;
        for (int i = 0; i < mat.size(); ++i)
        {
            int count = 0;
            for (int num : mat[i])
            {
                if (num == 1)
                {
                    ++count;
                }
            }
            one_by_row[i] = count;
        }

        for (int i = 0; i < mat[0].size(); ++i)
        {
            int count = 0;
            for (int j = 0; j < mat.size(); ++j)
            {
                if (mat[j][i] == 1)
                {
                    ++count;
                }
            }
            one_by_col[i] = count;
        }

        int res = 0;
        for (int r = 0; r < mat.size(); ++r)
        {
            for (int c = 0; c < mat[0].size(); ++c)
            {
                if (mat[r][c] == 1 && one_by_row[r] == 1 && one_by_col[c] == 1)
                {
                    ++res;
                }
            }
        }
        return res;
    }
};

