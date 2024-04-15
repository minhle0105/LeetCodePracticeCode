class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2){
            return p1.front() < p2.front();
        });

        int res = 0;
        int position = 0;

        while (position < points.size())
        {
            int left_x = points[position][0];
            int right_x = left_x + w;
            position = binary_search(points, position, right_x);
            ++res;
        }

        return res;
    }

    int binary_search(const vector<vector<int>> &points, int left, int target)
    {
        int right = points.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (points[mid][0] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (points[left][0] > target)
        {
            return left;
        }
        if (points[right][0] > target)
        {
            return right;
        }
        return points.size();
    }
};
