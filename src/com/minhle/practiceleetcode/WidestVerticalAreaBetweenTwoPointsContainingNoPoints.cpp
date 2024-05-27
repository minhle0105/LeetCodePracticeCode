class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2){
            return p1.front() < p2.front();
        });
        int res = 0;
        for (int i = 0; i < points.size() - 1; ++i)
        {
            res = max(res, points[i + 1][0] - points[i][0]);
        }
        return res;
    }
};
