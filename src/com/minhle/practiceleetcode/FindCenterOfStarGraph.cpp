#include "AllNecessaryHeaders.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> degrees(edges.size() + 1, 0);
        for (const auto &edge : edges)
        {
            ++degrees[edge.front() - 1];
            ++degrees[edge.back() - 1];
            if (degrees[edge.front() - 1] == edges.size())
            {
                return edge.front();
            }
            if (degrees[edge.back() - 1] == edges.size())
            {
                return edge.back();
            }
        }
        return -1;
    }
};
