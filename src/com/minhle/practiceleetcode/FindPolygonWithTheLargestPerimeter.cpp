#include "AllNecessaryHeaders.h"

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<long long> prefix_sum = {0};
        for (int num : nums)
        {
            prefix_sum.push_back(num + prefix_sum.back());
        }
        long long res = -1;
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] < prefix_sum[i])
            {
                res = max(res, prefix_sum[i + 1]);
            }
        }
        return res;
    }
};
