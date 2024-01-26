#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxScore(string s) {
        vector<pair<int, int>> prefix_count;
        prefix_count.push_back({0, 0});
        for (int i = 0; i < s.size(); ++i)
        {
            auto prev = prefix_count.back();
            if (s[i] == '0')
            {
                prefix_count.push_back({prev.first + 1, prev.second});
            }
            else
            {
                prefix_count.push_back({prev.first, prev.second + 1});
            }
        }
        int res = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            int nZeroesLeft = prefix_count[i].first;
            int nOnesRight = prefix_count.back().second - prefix_count[i].second;
            int score = nZeroesLeft + nOnesRight;
            res = max(res, score);
        }
        return res;
    }
};
