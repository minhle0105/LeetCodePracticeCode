#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        nRows = grid.size();
        nCols = grid[0].size();

        vector<vector<int>> total_distance(nRows, vector<int>(nCols, 0));
        int coefficient = 0;
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nCols; ++j)
            {
                if (grid[i][j] == 1)
                {
                    bfs(grid, coefficient, {i, j}, total_distance);
                    --coefficient;
                }
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nCols; ++j)
            {
                if (grid[i][j] == coefficient)
                {
                    res = min(res, total_distance[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }

    void bfs(vector<vector<int>> &grid, int coefficient,
             const pair<int, int> &source, vector<vector<int>> &total_distance)
    {
        queue<pair<int, int>> q;
        q.push(source);
        vector<vector<int>> distances(nRows, vector<int>(nCols, 0));
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;

            for (int i = 0; i < 4; ++i)
            {
                int next_row = row + dR[i];
                int next_col = col + dC[i];
                bool in_bound = next_row >= 0 && next_row < nRows && next_col >= 0 && next_col < nCols;
                if (in_bound)
                {
                    if (grid[next_row][next_col] == coefficient)
                    {
                        --grid[next_row][next_col];
                        q.emplace(next_row, next_col);
                        distances[next_row][next_col] = distances[row][col] + 1;
                        total_distance[next_row][next_col] += distances[next_row][next_col];
                    }
                }
            }
        }
    }
private:
    const vector<int> dR = {0, 1, 0, -1};
    const vector<int> dC = {1, 0, -1, 0};
    int nRows;
    int nCols;
};
