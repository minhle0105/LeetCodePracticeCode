#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    const vector<int> dR = {0, 1, 0, -1};
    const vector<int> dC = {1, 0, -1, 0};

    map<pair<int, int>, int> cell_to_island_id;
    int island_id;
    vector<vector<pair<int, int>>> islands_grid_2;
    int res;

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        cell_to_island_id.clear();
        islands_grid_2.clear();
        island_id = 0;
        res = 0;

        int m = grid1.size();
        int n = grid1[0].size();

        vector<vector<bool>> visited_1(m, vector<bool>(n, false));
        vector<vector<bool>> visited_2(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((!visited_1[i][j]) && grid1[i][j] == 1)
                {
                    bfs(grid1, visited_1, {i, j}, true);
                    ++island_id;
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((!visited_2[i][j]) && grid2[i][j] == 1)
                {
                    bfs(grid2, visited_2, {i, j}, false);
                }
            }
        }
        countSub();
        return res;
    }

    void countSub()
    {
        for (const auto &island : islands_grid_2)
        {
            set<int> island_id;
            int cells_count = 0;
            for (const auto &cell : island)
            {
                if (cell_to_island_id.find(cell) != cell_to_island_id.end())
                {
                    island_id.insert(cell_to_island_id[cell]);
                    ++cells_count;
                }
                else
                {
                    break;
                }
            }
            if (island_id.size() == 1 && cells_count == island.size())
            {
                ++res;
            }
        }
    }

    void bfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, const pair<int, int> &source, bool island_1)
    {
        vector<pair<int, int>> cells_this_island;
        if (!island_1)
        {
            cells_this_island.push_back(source);
        }

        int nRows = grid.size();
        int nCols = grid[0].size();
        queue<pair<int, int>> q;
        q.push(source);
        visited[source.first][source.second] = true;

        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            auto row = cell.first;
            auto col = cell.second;
            if (island_1)
            {
                cell_to_island_id[cell] = island_id;
            }

            for (int i = 0; i < 4; ++i)
            {
                int next_row = row + dR[i];
                int next_col = col + dC[i];
                bool in_bound = next_row >= 0 && next_row < nRows && next_col >= 0 && next_col < nCols;
                if (in_bound && !visited[next_row][next_col] && grid[next_row][next_col] == 1)
                {
                    visited[next_row][next_col] = true;
                    q.push({next_row, next_col});
                    if (!island_1)
                    {
                        cells_this_island.push_back({next_row, next_col});
                    }
                }
            }
        }

        if (!island_1)
        {
            islands_grid_2.push_back(cells_this_island);
        }
    }
};
