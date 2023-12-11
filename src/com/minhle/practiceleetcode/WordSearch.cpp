#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (backtracking(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
private:
    const vector<int> dR = {0, 0, 1, -1};
    const vector<int> dC = {1, -1, 0, 0};

    bool backtracking(vector<vector<char>> &board, const string &word, int r, int c, int pos)
    {
        if (pos == word.size())
        {
            return true;
        }
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
        {
            return false;
        }
        if (word[pos] != board[r][c])
        {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        for (int i = 0; i < 4; ++i) {
            int nextR = r + dR[i];
            int nextC = c + dC[i];
            if (backtracking(board, word, nextR, nextC, pos + 1))
            {
                return true;
            }
        }

        board[r][c] = temp;
        return false;
    }
};
