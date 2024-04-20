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
                int max_r = i;
                int max_c = j;
                dfs(land, i, j, max_r, max_c);
                res.push_back({i, j, max_r, max_c});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &land, int r, int c, int &max_r, int &max_c)
    {
        if (r < 0 || c < 0 || r >= m || c >= n || land[r][c] == 0)
        {
            return;
        }
        land[r][c] = 0;
        max_r = max(max_r, r);
        max_c = max(max_c, c);
        for (int i = 0; i < 4; ++i)
        {
            dfs(land, r + dR[i], c + dC[i], max_r, max_c);
        }
    }
};