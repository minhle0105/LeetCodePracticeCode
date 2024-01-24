#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int nCols = 0;
        for (const auto &word : words)
        {
            nCols = max(nCols, static_cast<int>(word.size()));
        }
        vector<vector<char>> matrix(words.size(), vector<char>(nCols, ' '));
        for (int i = 0; i < words.size(); ++i)
        {
            for (int c = 0; c < words[i].size(); ++c)
            {
                matrix[i][c] = words[i][c];
            }
        }

        for (int i = 0; i < words.size(); ++i)
        {
            auto row = matrix[i];
            auto col = get_col(matrix, i);
            if (row != col)
            {
                return false;
            }
        }
        return true;
    }

    vector<char> get_col(const vector<vector<char>> &matrix, int col)
    {
        vector<char> res;
        for (int row = 0; row < matrix.size(); ++row)
        {
            res.push_back(matrix[row][col]);
        }
        return res;
    }

};
