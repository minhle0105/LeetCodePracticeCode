#include "AllNecessaryHeaders.h"

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        for (const auto &stone : stones)
        {
            parents[{stone.front(), stone.back()}] = {-1, -1};
            size[{stone.front(), stone.back()}] = 1;
        }
        int n = stones.size();
        int remaining = n;
        for (int i = 0; i < stones.size() - 1; ++i)
        {
            pair<int, int> cell_1 = {stones[i].front(), stones[i].back()};
            for (int j = i + 1; j < stones.size(); ++j)
            {
                pair<int, int> cell_2 = {stones[j].front(), stones[j].back()};
                if (cell_1.first == cell_2.first || cell_1.second == cell_2.second)
                {
                    if (join(cell_1, cell_2))
                    {
                        --remaining;
                    }
                }
            }
        }
        return n - remaining;
    }
private:
    map<pair<int, int>, pair<int, int>> parents;
    map<pair<int, int>, int> size;

    pair<int, int> find(const pair<int, int> &cell)
    {
        return parents[cell] == make_pair(-1, -1) ? cell : find(parents[cell]);
    }

    bool join(const pair<int, int> &cell_1, const pair<int, int> &cell_2)
    {
        auto lead_1 = find(cell_1);
        auto lead_2 = find(cell_2);
        if (lead_1 == lead_2)
        {
            return false;
        }
        if (size[lead_1] > size[lead_2])
        {
            parents[lead_2] = lead_1;
            size[lead_1] += size[lead_2];
        }
        else
        {
            parents[lead_1] = lead_2;
            size[lead_2] += size[lead_1];
        }
        return true;
    }
};
