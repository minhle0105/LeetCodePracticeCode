#include <set>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> calculateBoundaries(const vector<int> &circle)
    {
        int leftMostX = circle[0] - circle[2];
        int rightMostX = circle[0] + circle[2];
        int topMostY = circle[1] + circle[2];
        int bottomMostY = circle[1] - circle[2];
        vector<int> res;
        res.push_back(leftMostX);
        res.push_back(rightMostX);
        res.push_back(topMostY);
        res.push_back(bottomMostY);
        return res;
    }

    int countLatticePoints(vector<vector<int>>& circles) {
        int leftMostX = circles[0][0] - circles[0][2];
        int rightMostX = circles[0][0] + circles[0][2];
        int topMostY = circles[0][1] + circles[0][2];
        int bottomMostY = circles[0][1] - circles[0][2];

        for (const auto &circle : circles)
        {
            vector<int> boundaries = calculateBoundaries(circle);
            leftMostX = min(leftMostX, boundaries[0]);
            rightMostX = max(rightMostX, boundaries[1]);
            topMostY = max(topMostY, boundaries[2]);
            bottomMostY = min(bottomMostY, boundaries[3]);
        }
        
        set<pair<int, int>> res;
        for (int x = leftMostX; x <= rightMostX; ++x)
        {
            for (int y = bottomMostY; y <= topMostY; ++y)
            {
                int thisX = x;
                int thisY = y;
                for (const auto &circle : circles)
                {
                    if (insideCircle(thisX, thisY, circle))
                    {
                        res.insert({thisX, thisY});
                        break;
                    }
                }
            }
        }
        return res.size();
    }

    bool insideCircle(int x, int y, const vector<int> &circle)
    {
        double distanceFromCenterToPoint = distance(x, y, circle[0], circle[1]);
        return distanceFromCenterToPoint <= (double) circle[2];
    }

    double distance(int x0, int y0, int x1, int y1)
    {
        double res = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
        return sqrt(res);
    }
};

