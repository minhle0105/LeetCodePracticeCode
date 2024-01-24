#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> d(n, 0);
        set<pair<int, int>> edges;
        for (const auto &road : roads)
        {
            ++d[road.front()];
            ++d[road.back()];
            edges.insert({road.front(), road.back()});
        }
        int res = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (edges.find({i, j}) != edges.end() || edges.find({j, i}) != edges.end())
                {
                    res = max(res, d[i] + d[j] - 1);
                }
                else
                {
                    res = max(res, d[i] + d[j]);
                }
            }
        }
        return res;
    }
};
