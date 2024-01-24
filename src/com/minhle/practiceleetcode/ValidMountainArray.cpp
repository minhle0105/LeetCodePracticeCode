#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
        {
            return false;
        }
        int first_decreasing_point = -1;
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i] >= arr[i + 1])
            {
                first_decreasing_point = i;
                break;
            }
        }
        if (first_decreasing_point <= 0)
        {
            return false;
        }
        for (int i = first_decreasing_point; i < arr.size() - 1; ++i)
        {
            if (arr[i + 1] >= arr[i])
            {
                return false;
            }
        }
        return true;
    }
};
