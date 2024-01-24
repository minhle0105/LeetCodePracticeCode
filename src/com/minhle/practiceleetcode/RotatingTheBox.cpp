#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int nRows = box.size();
        int nCols = box[0].size();
        vector<vector<char>> res(nCols, vector<char>(nRows, '.'));
        for (auto &row : box)
        {
            for (int i = row.size() - 1; i >= 0; --i)
            {
                if (row[i] == '#')
                {
                    int next_pos = i + 1;
                    while (next_pos < row.size() && row[next_pos] == '.')
                    {
                        ++next_pos;
                    }
                    if (next_pos - 1 != i)
                    {
                        row[next_pos - 1] = '#';
                        row[i] = '.';
                    }
                }
            }
        }
        transpose(box, res);
        return res;
    }
    void transpose(const vector<vector<char>> &original, vector<vector<char>> &new_container)
    {
        int col = new_container[0].size() - 1;
        for (const auto &row : original)
        {
            int i = 0;
            for (int r = 0; r < new_container.size(); ++r)
            {
                new_container[r][col] = row[i];
                ++i;
            }
            --col;
        }
    }
};
