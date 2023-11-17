#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto &row : image)
        {
            reverse_row(row);
            flip(row);
        }
        return image;
    }
    void reverse_row(vector<int> &row)
    {
        for (int i = 0; i < row.size() / 2; ++i)
        {
            int temp = row[i];
            row[i] = row[row.size() - i - 1];
            row[row.size() - i - 1] = temp;
        }
    }
    void flip(vector<int> &row)
    {
        for (int i = 0; i < row.size(); ++i)
        {
            if (row[i] == 0)
            {
                row[i] = 1;
            }
            else
            {
                row[i] = 0;
            }
        }
    }
};
