#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        parents.resize(m, vector<pair<int, int>>(n, {-1, -1}));
        size.resize(m, vector<int>(n, 1));
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    if (i - 1 >= 0 && grid[i - 1][j] == '1')
                    {
                        if (union_set({i, j}, {i - 1, j}))
                        {
                            --res;
                        }
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == '1')
                    {
                        if (union_set({i, j}, {i, j - 1}))
                        {
                            --res;
                        }
                    }
                }
            }
        }
        return res;
    }

private:
    vector<vector<pair<int, int>>> parents;
    vector<vector<int>> size;

    pair<int, int> find(const pair<int, int> &cell)
    {
        if (parents[cell.first][cell.second] == make_pair(-1, -1))
        {
            return cell;
        }
        parents[cell.first][cell.second] = find(parents[cell.first][cell.second]);
        return parents[cell.first][cell.second];
    }

    bool union_set(const pair<int, int> &a, const pair<int, int> &b)
    {
        auto lead_a = find(a);
        auto lead_b = find(b);
        if (lead_a == lead_b)
        {
            return false;
        }
        if (size[lead_a.first][lead_a.second] > size[lead_b.first][lead_b.second])
        {
            parents[lead_b.first][lead_b.second] = lead_a;
            size[lead_a.first][lead_a.second] += size[lead_b.first][lead_b.second];
        }
        else
        {
            parents[lead_a.first][lead_a.second] = lead_b;
            size[lead_b.first][lead_b.second] += size[lead_a.first][lead_a.second];
        }
        return true;
    }
};
