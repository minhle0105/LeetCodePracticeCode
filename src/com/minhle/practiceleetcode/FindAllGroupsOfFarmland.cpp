class Solution {
public:
    const vector<int> dR = {0, 0, 1, -1};
    const vector<int> dC = {1, -1, 0, 0};
    int m;
    int n;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (land[i][j] == 0)
                {
                    continue;
                }
                vector<pair<int, int>> cells;
                dfs(land, i, j, cells);
                sort(cells.begin(), cells.end());
                auto top_left = cells.front();
                auto bottom_right = cells.back();

                res.push_back({top_left.first, top_left.second, bottom_right.first, bottom_right.second});
                cells.clear();
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &land, int r, int c, vector<pair<int, int>> &cells)
    {
        if (r < 0 || c < 0 || r >= m || c >= n || land[r][c] == 0)
        {
            return;
        }
        land[r][c] = 0;
        cells.push_back({r, c});
        for (int i = 0; i < 4; ++i)
        {
            dfs(land, r + dR[i], c + dC[i], cells);
        }
    }
};
