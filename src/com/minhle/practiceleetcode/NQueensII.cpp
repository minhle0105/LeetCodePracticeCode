#include <utility>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int res;
    int totalNQueens(int n) {
        string one_row;
        for (int i = 0; i < n; ++i)
        {
            one_row += '.';
        }
        vector<string> current_board(n, one_row);
        solution(current_board, 0, n);
        return res;
    }

    bool check_board_ok(const vector<string> &current_board)
    {
        vector<pair<int, int>> queen_positions;
        for (size_t i = 0; i < current_board.size(); ++i)
        {
            for (size_t j = 0; j < current_board[i].size(); ++j)
            {
                if (current_board[i][j] == 'Q')
                {
                    queen_positions.push_back({i, j});
                }
            }
        }
        for (size_t i = 0; i < queen_positions.size() - 1; ++i)
        {
            for (size_t j = i + 1; j < queen_positions.size(); ++j)
            {
                pair<int, int> point_one = queen_positions[i];
                pair<int, int> point_two = queen_positions[j];
                bool on_same_row = point_one.first == point_two.first;
                bool on_same_col = point_one.second == point_two.second;
                bool on_same_diagonal = abs(point_one.first - point_two.first) == abs(point_one.second - point_two.second);
                if (on_same_row || on_same_col || on_same_diagonal)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void solution(vector<string> &current_board, int r, int n)
    {
        if (r == n)
        {
            if (check_board_ok(current_board))
            {
                ++res;
            }
            return;
        }
        for (int col = 0; col < n; ++col)
        {
            bool col_is_occupied = false;
            for (string row : current_board)
            {
                if (row[col] == 'Q')
                {
                    col_is_occupied = true;
                    break;
                }
            }
            if (!col_is_occupied)
            {
                current_board[r][col] = 'Q';
                solution(current_board, r + 1, n);
                current_board[r][col] = '.';
            }
        }
    }
};
