#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string curr;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == word.front())
                {
                    curr += word.front();
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    visited[i][j] = true;
                    if (backtracking(board, word, curr, 1, i, j, visited))
                    {
                        return true;
                    }
                    curr.pop_back();
                }
            }
        }
        return false;
    }
private:
    const vector<int> dR = {0, 0, 1, -1};
    const vector<int> dC = {1, -1, 0, 0};

    bool backtracking(const vector<vector<char>> &board, const string &word, string &curr, int pos, int r, int c, vector<vector<bool>> &visited)
    {
        if (curr.size() == word.size())
        {
            return true;
        }
        if (r == board.size())
        {
            return false;
        }
        if (c == board[0].size())
        {
            return backtracking(board, word, curr, pos, r + 1, c, visited);
        }
        for (int i = 0; i < 4; ++i)
        {
            int next_r = r + dR[i];
            int next_c = c + dC[i];
            bool in_bound = next_r >= 0 && next_c >= 0 && next_r < board.size() && next_c < board[0].size();
            if (in_bound)
            {
                if (!visited[next_r][next_c] && board[next_r][next_c] == word[pos])
                {
                    curr += board[next_r][next_c];
                    visited[next_r][next_c] = true;
                    ++pos;
                    if (backtracking(board, word, curr, pos, next_r, next_c, visited))
                    {
                        return true;
                    }
                    --pos;
                    visited[next_r][next_c] = false;
                    curr.pop_back();
                }
            }
        }
        return false;
    }
};
