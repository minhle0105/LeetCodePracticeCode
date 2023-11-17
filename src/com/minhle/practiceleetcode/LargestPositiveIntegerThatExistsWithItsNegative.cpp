#include "AllNecessaryHeaders.h"

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < nums.size() && nums[left] < 0)
        {
            while (right >= 0 && nums[right] >= 0)
            {
                if (nums[left] == nums[right] * (-1))
                {
                    return nums[right];
                }
                --right;
            }
            ++left;
            right = nums.size() - 1;
        }
        return -1;
    }
};
