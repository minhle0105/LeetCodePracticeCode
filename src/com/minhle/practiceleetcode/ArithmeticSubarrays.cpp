#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        vector<int> copy;
        for (int i = 0; i < l.size(); ++i)
        {
            int left = l[i];
            int right = r[i];
            for (int j = left; j <= right; ++j)
            {
                copy.push_back(nums[j]);
            }
            res.push_back(isArithmeticArray(copy));
            copy.clear();
        }
        return res;
    }

    bool isArithmeticArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] != nums[1] - nums[0])
            {
                return false;
            }
        }
        return true;
    }
};
