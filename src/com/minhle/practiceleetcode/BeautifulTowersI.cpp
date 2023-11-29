#include "AllNecessaryHeaders.h"

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long res = 0;
        for (int peak = 0; peak < maxHeights.size(); ++peak)
        {
            vector<int> heights(maxHeights.begin(), maxHeights.end());
            for (int j = peak - 1; j >= 0; --j)
            {
                heights[j] = min(maxHeights[j], heights[j + 1]);
            }
            for (int j = peak + 1; j < maxHeights.size(); ++j)
            {
                heights[j] = min(maxHeights[j], heights[j - 1]);
            }
            long long sum = 0;
            for (int height : heights)
            {
                sum += height;
            }
            res = max(res, sum);
        }
        return res;
    }
};
