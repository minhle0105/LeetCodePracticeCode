#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> counter;
        unordered_map<int, int> first_positions;
        for (int i = 0; i < nums.size(); ++i)
        {
            ++counter[nums[i]];
            if (first_positions.find(nums[i]) == first_positions.end())
            {
                first_positions[nums[i]] = i;
            }
        }
        int res = 0;
        for (const auto &pair : first_positions)
        {
            int num = pair.first;
            int first_position = pair.second;
            int remaining_k = k;
            int freq = counter[num];
            int i = first_position - 1;
            while (i >= 0 && remaining_k >= num - nums[i])
            {
                remaining_k -= (num - nums[i]);
                ++freq;
                --i;
            }
            res = max(res, freq);
        }
        return res;
    }
};
