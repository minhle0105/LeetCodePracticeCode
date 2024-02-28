#include "AllNecessaryHeades.h"

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> diff;
        for (const auto &segment : segments)
        {
            diff[segment[0]] += segment[2];
            diff[segment[1]] -= segment[2];
        }
        vector<pair<int, long long>> colored_segments(diff.begin(), diff.end());
        vector<vector<long long>> res;

        long long color = 0;

        for (int i = 0; i < colored_segments.size() - 1; ++i)
        {
            color += colored_segments[i].second;
            if (color > 0)
            {
                int start = colored_segments[i].first;
                int end = colored_segments[i + 1].first;

                res.push_back({start, end, color});
            }
        }
        return res;
    }
};
