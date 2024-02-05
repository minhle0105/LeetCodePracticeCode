#include "AllNecessaryHeaders.h"

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int res = 0;
        const int boundary = 0;
        int current_position = 0;
        for (int num : nums)
        {
            current_position += num;
            if (current_position == boundary)
            {
                ++res;
            }
        }
        return res;
    }
};
