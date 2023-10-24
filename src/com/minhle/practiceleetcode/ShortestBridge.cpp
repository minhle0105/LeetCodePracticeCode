#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;
        set<pair<int, int>> island1;
        set<pair<int, int>> island2;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.size(); ++j)
            {
                if (grid.at(i).at(j) == 0)
                {
                    continue;
                }
                if (visited.find({i, j}) != visited.end())
                {
                    continue;
                }
                if (island1.size() == 0)
                {
                    pair<int, int> source = {i, j};
                    island1 = find_island(grid, visited, source);
                }
                else
                {
                    pair<int, int> source = {i, j};
                    island2 = find_island(grid, visited, source);
                }
            }
        }
        queue<pair<int, int>> q;
        map<pair<int, int>, int> levels;
        for (const auto &cell : island1)
        {
            q.push(cell);
            visited.insert(cell);
            levels[cell] = 1;
        }
        int res = find_shortest_distance(grid, q, levels, visited, island2);
        return res;
    }

    set<pair<int, int>> find_island(const vector<vector<int>> &grid, set<pair<int, int>> &visited, pair<int, int> &source)
    {
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push(source);
        visited.insert(source);

        set<pair<int, int>> res;
        res.insert(source);
        while (!q.empty())
        {
            pair<int, int> current_cell = q.front();
            int current_row = current_cell.first;
            int current_col = current_cell.second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int next_row = current_row + dR[i];
                int next_col = current_col + dC[i];
                bool in_bound = next_row >= 0 && next_row < n && next_col >= 0 && next_col < n;
                if (in_bound)
                {
                    if (grid.at(next_row).at(next_col) == 1)
                    {
                        if (visited.find({next_row, next_col}) == visited.end())
                        {
                            visited.insert({next_row, next_col});
                            q.push({next_row, next_col});
                            res.insert({next_row, next_col});
                        }
                    }
                }
            }
        }
        return res;
    }

    int find_shortest_distance(const vector<vector<int>> &grid, queue<pair<int, int>> &q, map<pair<int, int>, int> &levels, set<pair<int, int>> visited, const set<pair<int, int>> island2)
    {
        int n = grid.size();
        while (!q.empty())
        {
            pair<int, int> current_cell = q.front();
            int current_row = current_cell.first;
            int current_col = current_cell.second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int next_row = current_row + dR[i];
                int next_col = current_col + dC[i];
                bool in_bound = next_row >= 0 && next_row < n && next_col >= 0 && next_col < n;

                if (in_bound)
                {
                    if (island2.find({next_row, next_col}) != island2.end())
                    {
                        return levels[current_cell] - 1;
                    }
                    if (visited.find({next_row, next_col}) == visited.end() && grid.at(next_row).at(next_col) == 0)
                    {
                        q.push({next_row, next_col});
                        visited.insert({next_row, next_col});
                        levels[{next_row, next_col}] = levels[current_cell] + 1;
                    }
                }
            }
        }
        return -1;
    }
private:
    vector<int> dR = {0, 1, -1, 0};
    vector<int> dC = {1, 0, 0, -1};
};
