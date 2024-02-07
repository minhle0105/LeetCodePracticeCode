#include "AllNecessaryHeaders.h"

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefix_sum = {0};
        unordered_map<int, long long> ps_map;
        long long res = LLONG_MIN;

        for (const int num : nums)
        {
            prefix_sum.push_back(num + prefix_sum.back());
            int a = num - k;
            int b = num + k;
            if (ps_map.find(a) != ps_map.end())
            {
                res = max(res, prefix_sum.back() - ps_map[a] + a);
            }
            if (ps_map.find(b) != ps_map.end())
            {
                res = max(res, prefix_sum.back() - ps_map[b] + b);
            }
            ps_map[num] = ps_map.find(num) == ps_map.end() ? prefix_sum.back() :
                                                                min(ps_map[num], prefix_sum.back());;
        }
        return res == LLONG_MIN ? 0 : res;
    }
};
