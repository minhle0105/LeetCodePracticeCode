#include "AllNecessaryHeaders.h"

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 'X')
                {
                    bfs(board, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
private:
    vector<int> dR = {0, 0, 1, -1};
    vector<int> dC = {1, -1, 0, 0};

    void bfs(vector<vector<char>> &board, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for (int i = 0; i < 4; ++i)
            {
                int next_row = row + dR[i];
                int next_col = col + dC[i];
                bool in_bound = next_row >= 0 && next_col >= 0 && next_row < board.size() && next_col < board[0].size();
                if (in_bound)
                {
                    if (board[next_row][next_col] == 'X')
                    {
                        board[next_row][next_col] = 'O';
                        q.push({next_row, next_col});
                    }
                }
            }
        }
    }
};
