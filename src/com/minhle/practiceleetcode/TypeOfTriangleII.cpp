#include "AllNecessaryHeaders.h"

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (!is_triangle(nums))
        {
            return "none";
        }
        unordered_set<int> sides;
        for (int num : nums)
        {
            sides.insert(num);
        }
        if (sides.size() == 1)
        {
            return "equilateral";
        }
        return sides.size() == 2 ? "isosceles" : "scalene";
    }

    bool is_triangle(const vector<int> &nums)
    {
        return nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1];
    }
};
