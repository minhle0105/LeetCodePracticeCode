#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int &num : nums)
        {
            num = num % 2 == 0 ? 0 : 1;
        }
        return subarraySumEqualsK(nums, k);
    }
    int subarraySumEqualsK(vector<int>& nums, int k) {
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
