#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0;
        int right = pow(10, 6);
        while (left <= right)
        {
            int mid = (left + right) / 2;
            bool path_exists = bfs(heights, mid);
            if (path_exists)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (bfs(heights, left))
        {
            return left;
        }
        return right;
    }

    bool bfs(const vector<vector<int>> &grid, int cap)
    {
        queue<pair<int, int>> q;
        int nRows = grid.size();
        int nCols = grid.at(0).size();
        vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));
        int row_dest = nRows - 1;
        int col_dest = nCols - 1;
        q.emplace(0, 0);
        visited[0][0] = true;

        while (!q.empty())
        {
            auto curr = q.front();
            int current_row = curr.first;
            int current_col = curr.second;
            q.pop();
            if (current_row == row_dest && current_col == col_dest)
            {
                return true;
            }
            for (int i = 0; i < 4; ++i)
            {
                int next_row = current_row + dR[i];
                int next_col = current_col + dC[i];
                bool in_bound = next_row >= 0 && next_row < nRows && next_col >= 0 && next_col < nCols;
                if (in_bound)
                {
                    if (visited[next_row][next_col] == false)
                    {
                        int level_of_effort = get_level_of_effort(grid, curr, {next_row, next_col});
                        if (level_of_effort <= cap)
                        {
                            q.emplace(next_row, next_col);
                            visited[next_row][next_col] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
private:
    vector<int> dR = {1, 0, -1, 0};
    vector<int> dC = {0, 1, 0, -1};

    int get_level_of_effort(const vector<vector<int>> &grid, const pair<int, int> &cell1, const pair<int, int> &cell2)
    {
        int cell1_val = grid.at(cell1.first).at(cell1.second);
        int cell2_val = grid.at(cell2.first).at(cell2.second);
        return abs(cell1_val - cell2_val);
    }
};
