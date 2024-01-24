#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        size_t n = grid.size();
        if (grid.at(0).at(0) != 0 || grid.at(n - 1).at(n - 1) != 0)
        {
            return -1;
        }

        queue<pair<int, int>> queue;
        set<pair<int, int>> visited;
        map<pair<int, int>, pair<int, int>> path;
        queue.push({n - 1, n - 1});
        visited.insert({n - 1, n - 1});
        path[{n - 1, n - 1}] = {-1, -1};

        while (!queue.empty())
        {
            pair<int, int> current_cell = queue.front();
            queue.pop();
            int current_row = current_cell.first;
            int current_col = current_cell.second;
            for (int i = 0; i < 8; ++i)
            {
                int next_row = current_row + dR[i];
                int next_col = current_col + dC[i];
                bool in_bound = next_row >= 0 && next_row < n && next_col >= 0 && next_col < n;
                if (in_bound)
                {
                    if (visited.find({next_row, next_col}) == visited.end() && grid.at(next_row).at(next_col) == 0)
                    {
                        visited.insert({next_row, next_col});
                        queue.push({next_row, next_col});
                        path[{next_row, next_col}] = {current_row, current_col};
                    }
                }
            }
        }
        if (visited.find({0, 0}) == visited.end())
        {
            return -1;
        }

        int res = 1;
        pair<int, int> current_cell = {0, 0};
        const pair<int, int> end_point = {-1, -1};
        while (path[current_cell] != end_point)
        {
            current_cell = path[current_cell];
            ++res;
        }
        return res;
    }

private:
    static constexpr int dR[8] = {0, 1, -1, 0, 1, 1, -1, -1};
    static constexpr int dC[8] = {1, 0, 0, -1, 1, -1, 1, -1};
};
