#include <vector>
#include <utility>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int nRows = board.size();
        int nCols = board.at(0).size();

        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nCols; ++j)
            {
                pair<int, int> source = {i, j};
                bfs(board, source, nRows, nCols);
            }
        }
    }

    void bfs(vector<vector<char>> &board, const pair<int, int> &source, int nRows, int nCols)
    {
        if (board.at(source.first).at(source.second) == 'X')
        {
            return;
        }
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        visited.insert(source);
        q.push(source);
        bool has_cell_on_edge = source.first == 0 || source.second == 0 || source.first == nRows - 1 || source.second == nCols - 1;
        if (has_cell_on_edge)
        {
            return;
        }
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            int row = curr.first;
            int col = curr.second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int next_row = row + dR[i];
                int next_col = col + dC[i];
                bool in_bound = next_row >= 0 && next_row < nRows && next_col >= 0 && next_col < nCols;
                char c = board.at(next_row).at(next_col);
                if (in_bound && board.at(next_row).at(next_col) == 'O')
                {
                    if (visited.find({next_row, next_col}) == visited.end())
                    {
                        if (next_row == 0 || next_col == 0 || next_row == nRows - 1 || next_col == nCols - 1)
                        {
                            has_cell_on_edge = true;
                            return;
                        }
                        visited.insert({next_row, next_col});
                        q.push({next_row, next_col});
                    }
                }
            }
        }
        for (const auto &cell : visited)
        {
            board.at(cell.first).at(cell.second) = 'X';
        }
    }

private:
    vector<int> dR = {1, 0, -1, 0};
    vector<int> dC = {0, 1, 0, -1};
};