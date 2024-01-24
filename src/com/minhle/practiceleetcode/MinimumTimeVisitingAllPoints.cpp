#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if (points.size() == 1)
        {
            return 1;
        }
        int res = 0;
        for (int i = 0; i < points.size() - 1; ++i)
        {
            auto point1_x = points[i][0];
            auto point1_y = points[i][1];
            auto point2_x = points[i + 1][0];
            auto point2_y = points[i + 1][1];
            res += max(abs(point2_x - point1_x), abs(point2_y - point1_y));
        }
        return res;
    }
};
