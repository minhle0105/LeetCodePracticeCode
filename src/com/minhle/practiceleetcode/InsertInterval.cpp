class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int pivot = binary_search(intervals, newInterval[0]);
        intervals = insert(intervals, newInterval, pivot);
        vector<vector<int>> res;
        res.push_back(intervals.front());
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (res.back()[1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                int start = min(res.back()[0], intervals[i][0]);
                int end = max(res.back()[1], intervals[i][1]);
                res.pop_back();
                res.push_back({start, end});
            }
        }
        return res;
    }
private:
    int binary_search(const vector<vector<int>> &intervals, int target)
    {
        int left = 0;
        int right = intervals.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (intervals[mid][0] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (intervals[left][0] > target)
        {
            return left;
        }
        if (intervals[right][0] > target)
        {
            return right;
        }
        return intervals.size();
    }

    vector<vector<int>> insert(const vector<vector<int>> &intervals, vector<int> &new_interval, int pivot)
    {
        vector<vector<int>> res;
        for (int i = 0; i < pivot; ++i)
        {
            res.push_back(intervals[i]);
        }
        res.push_back(new_interval);
        for (int i = pivot; i < intervals.size(); ++i)
        {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
