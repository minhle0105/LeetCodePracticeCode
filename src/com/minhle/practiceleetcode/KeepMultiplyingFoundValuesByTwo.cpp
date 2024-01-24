#include "AllNecessaryHeaders.h"

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        for (int num : nums)
        {
            if (num == original)
            {
                return findFinalValue(nums, 2 * original);
            }
        }
        return original;
    }
};

