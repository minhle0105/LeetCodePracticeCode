#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> can_reach(nums.size(), false);
        can_reach.front() = true;
        int most_recently_reached = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                if (i == nums.size() - 1)
                {
                    return can_reach.back();
                }
                if (!can_reach[i + 1])
                {
                    return false;
                }
                continue;
            }

            int farthest = min(i + nums[i], static_cast<int>(nums.size()) - 1);
            for (int j = most_recently_reached + 1; j <= farthest; ++j)
            {
                can_reach[j] = true;
            }
            most_recently_reached = farthest;
            if (most_recently_reached == nums.size() - 1)
            {
                return true;
            }
        }
        return can_reach.back();
    }
};
