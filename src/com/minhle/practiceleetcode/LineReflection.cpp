#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int min_x = INT_MAX;
        int max_x = INT_MIN;
        set<pair<int, int>> point_set;
        for (const auto &point : points)
        {
            min_x = min(min_x, point[0]);
            max_x = max(max_x, point[0]);
            point_set.insert({point[0], point[1]});
        }

        double mid_point = (static_cast<double>(abs(max_x - min_x))) / 2;
        double reflected_x = min_x + mid_point;
        for (const auto &point : points)
        {
            auto reflected_point = reflect_point(reflected_x, point);
            if (point_set.find(reflected_point) == point_set.end())
            {
                return false;
            }
        }
        return true;
    }

    pair<int, int> reflect_point(double reflect_x, const vector<int> &point)
    {
        double dist_x = abs(reflect_x - point[0]);
        pair<int, int> reflected_point = {-1, point[1]};
        reflected_point.first = point[0] < reflect_x ? reflect_x + dist_x : reflect_x - dist_x;
        return reflected_point;
    }
};
