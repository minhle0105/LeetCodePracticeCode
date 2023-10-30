#include <vector>
#include <set>
#include <utility>
#include <queue>

class Solution {
public:
    int min_row = 100;
    int max_row = 0;
    int min_col = 100;
    int max_col = 0;
    int minArea(vector<vector<char>>& image, int x, int y) {
        int nRows = image.size();
        int nCols = image.at(0).size();
        pair<int, int> start = {x, y};
        bfs(image, start, nRows, nCols);
        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }

    void bfs(const vector<vector<char>> &grid, const pair<int, int> &start, int nRows, int nCols)
    {
        vector<int> dR = {1, 0, -1, 0};
        vector<int> dC = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push(start);
        visited.insert(start);
        min_row = min(min_row, start.first);
        max_row = max(max_row, start.first);
        min_col = min(min_col, start.second);
        max_col = max(max_col, start.second);

        while (!q.empty())
        {
            pair<int, int> current_cell = q.front();
            q.pop();
            int current_row = current_cell.first;
            int current_col = current_cell.second;
            for (int i = 0; i < 4; ++i)
            {
                int next_row = current_row + dR.at(i);
                int next_col = current_col + dC.at(i);
                bool in_bound = next_row >= 0 && next_col >= 0 && next_row < nRows && next_col < nCols;
                if (in_bound)
                {
                    if (visited.find({next_row, next_col}) == visited.end() && grid.at(next_row).at(next_col) == '1')
                    {
                        min_row = min(min_row, next_row);
                        max_row = max(max_row, next_row);
                        min_col = min(min_col, next_col);
                        max_col = max(max_col, next_col);
                        visited.insert({next_row, next_col});
                        q.emplace(next_row, next_col);

                    }
                }
            }
        }
    }
};
