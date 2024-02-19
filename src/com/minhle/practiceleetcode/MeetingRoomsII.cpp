#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for (const auto &interval : intervals)
        {
            start.push_back(interval.front());
            end.push_back(interval.back());
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0;
        int number_of_meetings_going_on = 0;
        int i = 0;
        int j = 0;
        while (i < start.size() && j < end.size())
        {
            if (start[i] < end[j])
            {
                ++number_of_meetings_going_on;
                res = max(res, number_of_meetings_going_on);
                ++i;
            }
            else
            {
                --number_of_meetings_going_on;
                res = max(res, number_of_meetings_going_on);
                ++j;
            }
        }
        return res;
    }
};
