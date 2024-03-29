#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;

        int n = nums.size();
        for (int i = 0; i < nums.size() / 2; ++i)
        {
            res = max(res, nums[i] + nums[n - i - 1]);
        }
        return res;
    }
};
