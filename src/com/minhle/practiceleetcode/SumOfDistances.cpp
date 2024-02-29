#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> counter;
        unordered_map<int, vector<long long>> prefix_sums;
        for (long long i = 0; i < nums.size(); ++i)
        {
            if (prefix_sums.find(nums[i]) == prefix_sums.end())
            {
                prefix_sums[nums[i]] = {0};
            }
            counter[nums[i]].push_back(i);
            prefix_sums[nums[i]].push_back(i + prefix_sums[nums[i]].back());
        }

        vector<long long> res(nums.size(), 0);

        for (const auto &pair : prefix_sums)
        {
            if (pair.second.size() == 2)
            {
                continue;
            }
            auto abs_values = helper(pair.second, counter[pair.first]);
            int i = 0;
            for (int position : counter[pair.first])
            {
                res[position] = abs_values[i];
                ++i;
            }
        }
        return res;
    }

    vector<long long> helper(const vector<long long> &prefix_sum, const vector<int> &positions)
    {
        vector<long long> abs_values(prefix_sum.size() - 1, 0);
        for (long long i = 0; i < abs_values.size(); ++i)
        {
            long long c1 = i;
            long long c2 = positions.size() - i - 1;

            long long x = positions[i];

            long long left = c1 * x - prefix_sum[i];

            long long right = prefix_sum.back() - prefix_sum[i + 1] - c2 * x;
            abs_values[i] = left + right;
        }
        return abs_values;
    }
};
