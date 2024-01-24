#include "AllNecessaryHeaders.h"

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0)
        {
            return 0;
        }
        vector<int> nums(n + 1, -1);
        nums[0] = 0;
        nums[1] = 1;
        int res = max(0, 1);
        for (int i = 1; 2 <= 2 * i + 1 && 2 * i + 1 <= n; ++i)
        {
            nums[2 * i] = nums[i];
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            res = max(res, max(nums[2 * i], nums[2 * i + 1]));
        }
        return res;
    }
};
