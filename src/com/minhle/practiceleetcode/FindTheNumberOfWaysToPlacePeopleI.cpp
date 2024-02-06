#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), [](const vector<int> &point1, const vector<int> &point2){
            return point1.front() < point2.front();
        });
        int res = 0;

        for (int i = 0; i < points.size() - 1; ++i)
        {
            auto top_left = points[i];
            for (int j = i + 1; j < points.size(); ++j)
            {
                auto bottom_right = points[j];
                bool form_a_shape = bottom_right[0] > top_left[0] && bottom_right[1] < top_left[1];
                bool form_a_line = bottom_right[0] == top_left[0] || bottom_right[1] == top_left[1];
                if (form_a_shape || form_a_line)
                {
                    bool contains_other_points = false;
                    for (const auto &point :points)
                    {
                        if (point == top_left || point == bottom_right)
                        {
                            continue;
                        }
                        if (contains(top_left, bottom_right, point))
                        {
                            contains_other_points = true;
                            break;
                        }
                    }
                    if (!contains_other_points)
                    {
                        ++res;
                    }
                }
            }
        }
        return res;
    }

    bool contains(const vector<int> &top_left, const vector<int> &bottom_right, const vector<int> &point)
    {
        auto x2 = bottom_right.front();
        auto y2 = bottom_right.back();

        auto x0 = top_left.front();
        auto y0 = top_left.back();

        auto x1 = point.front();
        auto y1 = point.back();

        if (x0 == x1 && x1 == x2)
        {
            return min(y0, y2) <= y1 && y1 <= max(y0, y2);
        }
        if (y0 == y1 && y1 == y2)
        {
            return min(x0, x2) <= x1 && x1 <= max(x0, x2);
        }
        return x2 >= x1 && x1 >= x0 && y0 >= y1 && y1 >= y2;
    }
};
