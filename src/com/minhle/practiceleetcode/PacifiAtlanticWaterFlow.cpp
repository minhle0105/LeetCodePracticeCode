#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.at(0).size();

        vector<vector<int>> res;
        vector<vector<int>> count_ocean_reached(m, vector<int>(n, 0));
        vector<pair<int, int>> meet_pacific;
        vector<pair<int, int>> meet_atlantic;

        for (int c = 0; c < n; ++c)
        {
            meet_pacific.emplace_back(0, c);
            meet_atlantic.emplace_back(m - 1, c);
        }
        for (int r = 1; r < m - 1; ++r)
        {
            meet_pacific.emplace_back(r, 0);
            meet_atlantic.emplace_back(r, n - 1);
        }
        // top right and bottom left cells
        meet_atlantic.emplace_back(0, n - 1);
        meet_pacific.emplace_back(m - 1, 0);

        for (const auto &pair : meet_pacific)
        {
            can_reach_ocean(heights, pair, m, n, pacific_code, count_ocean_reached);
        }

        for (const auto &pair : meet_atlantic)
        {
            can_reach_ocean(heights, pair, m, n, atlantic_code, count_ocean_reached);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (count_ocean_reached[i][j] == 3)
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

    void can_reach_ocean(const vector<vector<int>> &grid, const pair<int, int> &source, int m, int n,
                         int ocean_code, vector<vector<int>> &count_ocean_reached)
    {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push(source);

        int current_status = count_ocean_reached[source.first][source.second];
        if (ocean_code == 1)
        {
            if (current_status == 0)
            {
                count_ocean_reached[source.first][source.second] = 1;
            }
        }
        else
        {
            if (current_status == 0)
            {
                count_ocean_reached[source.first][source.second] = 2;
            }
            if (current_status == 1)
            {
                count_ocean_reached[source.first][source.second] = 3;
            }
        }
        visited[source.first][source.second] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int curr_row = curr.first;
            int curr_col = curr.second;
            for (int i = 0; i < 4; ++i)
            {
                int next_row = curr_row + dR[i];
                int next_col = curr_col + dC[i];
                bool in_bound = next_row >= 0 && next_row < m && next_col >= 0 && next_col < n;
                if (in_bound)
                {
                    if (!visited[next_row][next_col])
                    {
                        if (grid[next_row][next_col] >= grid[curr_row][curr_col])
                        {
                            q.emplace(next_row, next_col);
                            visited[next_row][next_col] = true;
                            int current_status = count_ocean_reached[next_row][next_col];
                            if (ocean_code == 1)
                            {
                                if (current_status == 0)
                                {
                                    count_ocean_reached[next_row][next_col] = 1;
                                }
                            }
                            else
                            {
                                if (current_status == 0)
                                {
                                    count_ocean_reached[next_row][next_col] = 2;
                                }
                                if (current_status == 1)
                                {
                                    count_ocean_reached[next_row][next_col] = 3;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
private:
    const vector<int> dR = {0, 1, -1, 0};
    const vector<int> dC = {1, 0, 0, -1};
    const int pacific_code = 1;
    const int atlantic_code = 2;
};
