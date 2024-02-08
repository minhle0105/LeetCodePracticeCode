#include "AllNecessaryHeaders.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        int current_sum = 0;
        int res = 0;
        ++prefix_sum[current_sum];

        for (int num : nums)
        {
            current_sum += num;
            if (prefix_sum.find(current_sum - k) != prefix_sum.end())
            {
                res += prefix_sum[current_sum - k];
            }
            ++prefix_sum[current_sum];
        }
        return res;
    }
};
