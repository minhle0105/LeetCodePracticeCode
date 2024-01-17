#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> counter;
        int max_frequency = 1;
        for (int num : nums)
        {
            ++counter[num];
            max_frequency = max(max_frequency, counter[num]);
        }

        int res = 0;
        for (const auto &pair : counter)
        {
            if (pair.second == max_frequency)
            {
                res += max_frequency;
            }
        }
        return res;
    }
};
