class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2){
            return p1.back() < p2.back();
        });

        int res = 0;
        for (int i = 0; i < points.size();)
        {
            int j = i + 1;
            while (j < points.size() && points[j][0] <= points[i][1])
            {
                ++j;
            }
            ++res;
            i = j;
        }
        return res;
    }
};
