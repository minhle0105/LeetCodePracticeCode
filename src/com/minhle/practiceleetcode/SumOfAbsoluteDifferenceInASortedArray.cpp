#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum;
        prefix_sum.reserve(n + 1);
        prefix_sum.push_back(0);
        for (int num : nums)
        {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
        vector<int> res;
        res.reserve(n);
        for (int i = 0; i < nums.size(); ++i)
        {
            int first_half = prefix_sum[n] - prefix_sum[i + 1] - (n - i - 1) * nums[i];
            int second_half = i * nums[i] - prefix_sum[i];
            res.push_back(first_half + second_half);
        }
        return res;
    }
};
