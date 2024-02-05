#include "AllNecessaryHeaders.h"

class Solution {
public:
    const vector<int> dR = {0,1,0,-1};
    const vector<int> dC = {1,0,-1,0};

    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> count(m, vector<int>(n, 0));
        vector<vector<int>> region_avg(m, vector<int>(n, 0));
        vector<vector<vector<pair<int, int>>>> cell_region_map(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>{}));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                check_region(image, count, m, n, {i, j}, threshold, region_avg, cell_region_map);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (count[i][j] == 0)
                {
                    count[i][j] = image[i][j];
                }
                else
                {
                    auto regions = cell_region_map[i][j];
                    int sum_avg = 0;
                    for (const auto &region : regions)
                    {
                        sum_avg += region_avg[region.first][region.second];
                    }
                    count[i][j] = sum_avg / regions.size();
                }
            }
        }
        return count;
    }

    void check_region(const vector<vector<int>> &image, vector<vector<int>> &count, int m, int n,
                      const pair<int, int> &top_left, int threshold,
                      vector<vector<int>> &region_avg, vector<vector<vector<pair<int, int>>>> &cell_region_map)
    {
        int total_cells = 0;
        for (int r = top_left.first; r < min(top_left.first + 3, m); ++r)
        {
            for (int c = top_left.second; c < min(top_left.second + 3, n); ++c)
            {
                ++total_cells;
                for (int i = 0; i < 4; ++i)
                {
                    int next_r = r + dR[i];
                    int next_c = c + dC[i];
                    bool in_bound = next_r >= top_left.first && next_c >= top_left.second && next_r < min(m, top_left.first + 3) && next_c < min(n, top_left.second + 3);
                    if (in_bound)
                    {
                        if (abs(r - next_r) + abs(c - next_c) == 1)
                        {
                            if (abs(image[r][c] - image[next_r][next_c]) > threshold)
                            {
                                return;
                            }
                        }
                    }
                }
            }
        }
        if (total_cells != 9)
        {
            return;
        }
        int sum = 0;
        for (int r = top_left.first; r < min(top_left.first + 3, m); ++r)
        {
            for (int c = top_left.second; c < min(top_left.second + 3, n); ++c)
            {
                cell_region_map[r][c].push_back(top_left);
                ++count[r][c];
                sum += image[r][c];
            }
        }
        region_avg[top_left.first][top_left.second] = sum / 9;
    }
};
