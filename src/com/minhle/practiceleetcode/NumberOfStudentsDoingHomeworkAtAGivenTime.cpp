#include "AllNecessaryHeaders.h"

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        vector<int> diff(1002, 0);
        for (int i = 0; i < startTime.size(); ++i)
        {
            int start = startTime[i];
            int end = endTime[i];
            ++diff[start];
            --diff[end + 1];
        }
        for (int i = 1; i < diff.size(); ++i)
        {
            diff[i] = diff[i - 1] + diff[i];
        }
        return diff[queryTime];
    }
};
