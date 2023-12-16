#include "AllNecessaryHeaders.cpp"


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        parents.resize(m, vector<pair<int, int>>(n, {-1, -1}));
        size.resize(m, vector<int>(n, 1));
        vector<int> res(positions.size(), 0);
        int count = 0;
        const vector<int> dR = {0,0,1,-1};
        const vector<int> dC = {1,-1,0,0};
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (int i = 0; i < positions.size(); ++i)
        {
            auto position = positions[i];
            int r = position.front();
            int c = position.back();
            if (grid[r][c] == 1)
            {
                res[i] = count;
                continue;
            }
            grid[r][c] = 1;
            ++count;

            for (int j = 0; j < 4; ++j)
            {
                int next_r = r + dR[j];
                int next_c = c + dC[j];
                if (next_r >= 0 && next_c >= 0 && next_r < m && next_c < n && grid[next_r][next_c] == 1)
                {
                    if (union_set({r, c}, {next_r, next_c}))
                    {
                        --count;
                    }
                }
            }
            res[i] = count;
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
