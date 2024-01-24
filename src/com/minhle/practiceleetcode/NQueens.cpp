#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<pair<int, int>> queen_pos;
        backtracking(res, queen_pos, 0, n);
        return res;
    }

    void backtracking(vector<vector<string>> &res, vector<pair<int, int>> &queen_pos, int current_row, int n)
    {
        if (current_row == n)
        {
            res.push_back(create_board(queen_pos, n));
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            bool col_is_avail = true;
            for (const auto &cell : queen_pos)
            {
                if (cell.second == col)
                {
                    col_is_avail = false;
                    break;
                }
                if (abs(cell.first - current_row) == abs(cell.second - col))
                {
                    col_is_avail = false;
                    break;
                }
            }
            if (col_is_avail)
            {
                queen_pos.push_back({current_row, col});
                backtracking(res, queen_pos, current_row + 1, n);
                queen_pos.pop_back();
            }
        }
    }

    vector<string> create_board(const vector<pair<int, int>> &queen_pos, int n)
    {
        vector<string> board(n, string(n, '.'));
        for (const auto &cell : queen_pos)
        {
            board[cell.first][cell.second] = 'Q';
        }
        return board;
    }
};