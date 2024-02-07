#include "AllNecessaryHeaders.h"

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<int, long long> score;
        long long max_score = 0;
        for (int i = 0; i < edges.size(); ++i)
        {
            int src = i;
            int dst = edges[i];
            score[dst] += src;
            max_score = max(max_score, score[dst]);
        }
        int res = INT_MAX;
        for (const auto &pair : score)
        {
            if (pair.second == max_score)
            {
                res = min(res, pair.first);
            }
        }
        return res;
    }
};
