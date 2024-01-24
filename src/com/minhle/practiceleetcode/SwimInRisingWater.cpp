#include <vector>
#include <set>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int left = 0;
        int right = grid.size() * grid.size();
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (dfs(grid, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return dfs(grid, left) ? left : right;
    }

    bool dfs(const vector<vector<int>> &grid, int t)
    {
        int n = grid.size();
        const vector<int> dR = {1, 0, -1, 0};
        const vector<int> dC = {0, 1, 0, -1};

        stack<pair<int, int>> stack_;
        set<pair<int, int>> visited;
        stack_.push({0, 0});
        visited.insert({0, 0});
        while (!stack_.empty())
        {
            pair<int, int> current_cell = stack_.top();
            int current_row = current_cell.first;
            int current_col = current_cell.second;
            stack_.pop();
            if (grid.at(current_row).at(current_col) <= t)
            {
                for (int i = 0; i < 4; ++i)
                {
                    int nextRow = current_row + dR.at(i);
                    int nextCol = current_col + dC.at(i);
                    bool inBound = nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < n;
                    if (inBound)
                    {
                        if (visited.find({nextRow, nextCol}) == visited.end())
                        {
                            if (grid.at(nextRow).at(nextCol) <= t)
                            {
                                stack_.push({nextRow, nextCol});
                                visited.insert({nextRow, nextCol});
                            }
                        }
                    }
                }
            }
        }
        return visited.find({n - 1, n - 1}) != visited.end();
    }
};