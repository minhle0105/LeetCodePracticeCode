#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
        {
            return intervals.at(0).back() > intervals.at(0).front() ? vector<int>{-1} : vector<int>{0};
        }
        vector<int> res(intervals.size(), -1);
        unordered_map<int, int> start_pos;
        for (int i = 0; i < intervals.size(); ++i)
        {
            start_pos[intervals.at(i).front()] = i;
        }
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; ++i)
        {
            vector<int> interval = intervals.at(i);
            int left = i;
            int right = intervals.size() - 1;
            while (left < right - 1)
            {
                int mid = left + ((right - left) / 2);
                if (intervals.at(mid).front() >= interval.back())
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            int original_index = start_pos[intervals.at(i).front()];
            if (intervals.at(left).front() >= interval.back())
            {
                int next_interval_original_index = start_pos[intervals.at(left).front()];
                res.at(original_index) = next_interval_original_index;
            }
            else if (intervals.at(right).front() >= interval.back())
            {
                int next_interval_original_index = start_pos[intervals.at(right).front()];
                res.at(original_index) = next_interval_original_index;
            }
        }
        return res;
    }
};