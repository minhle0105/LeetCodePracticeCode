#include <vector>
#include <unordered_map>
#include <utility>
#include <unordered_set>

using namespace std;

class CheckSudoku
{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return check_rows(board) && check_cols(board) && check_sub_boxes(board);
    }

    bool can_place_value(const vector<vector<char>> &board, int r, int c, int k)
    {
        for (char ch : board[r])
        {
            if (ch == k + '0')
            {
                return false;
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            if (board[i][c] == k + '0')
            {
                return false;
            }
        }

        pair<int, int> top_cell_sub_box = get_sub_box_top_cell(r, c);
        for (int i = top_cell_sub_box.first; i < top_cell_sub_box.first + 3; ++i)
        {
            for (int j = top_cell_sub_box.second; j < top_cell_sub_box.second + 3; ++j)
            {
                if (board[i][j] == k + '0')
                {
                    return false;
                }
            }
        }
        return true;
    }

private:
    pair<int, int> get_sub_box_top_cell(int r, int c)
    {
        return pair<int, int>{static_cast<int>((r / 3)) * 3, static_cast<int>(c / 3) * 3};
    }

    bool check_rows(const vector<vector<char>> &board)
    {
        for (const auto &row : board)
        {
            unordered_set<char> nums;
            for (char num : row)
            {
                if (nums.find(num) != nums.end())
                {
                    return false;
                }
                nums.insert(num);
            }
        }
        return true;
    }

    bool check_cols(const vector<vector<char>> &board)
    {
        int cols = board[0].size();
        int rows = board.size();

        for (int c = 0; c < cols; ++c)
        {
            unordered_set<char> nums;
            for (int r = 0; r < rows; ++r)
            {
                if (nums.find(board[r][c]) != nums.end())
                {
                    return false;
                }
                nums.insert(board[r][c]);
            }
        }
        return true;
    }

    bool check_sub_boxes(const vector<vector<char>> &board)
    {
        for (int r = 0; r <= 6; r += 3)
        {
            int start_row = r;
            int end_row = r + 2;
            for (int c = 0; c <= 6; c += 3)
            {
                int start_col = c;
                int end_col = c + 2;
                if (!check_sub_box(board, start_row, end_row, start_col, end_col))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool check_sub_box(const vector<vector<char>> &board, int start_row, int end_row, int start_col, int end_col)
    {
        unordered_set<char> nums;
        for (int r = start_row; r <= end_row; ++r)
        {
            for (int c = start_col; c <= end_col; ++c)
            {
                char ch = board[r][c];
                if (nums.find(ch) != nums.end())
                {
                    return false;
                }
                nums.insert(ch);
            }
        }
        return true;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        CheckSudoku check;
        backtracking(board, 0, 0, check);
    }

    bool backtracking(vector<vector<char>> &board, int r, int c, CheckSudoku &check)
    {
        if (c == board[0].size())
        {
            return backtracking(board, r + 1, 0, check);
        }
        if (r == board.size())
        {
            return check.isValidSudoku(board);
        }
        if (board[r][c] != '.')
        {
            return backtracking(board, r, c + 1, check);
        }
        for (int val = 1; val < 10; ++val)
        {
            if (check.can_place_value(board, r, c, val))
            {
                board[r][c] = val + '0';
                if (backtracking(board, r, c + 1, check))
                {
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }
};
