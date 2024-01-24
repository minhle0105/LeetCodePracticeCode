#include "AllNecessaryHeaders.h"

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            pair<int, int> min_max = {nums[i], nums[i]};
            for (int j = i; j < nums.size(); ++j)
            {
                if (nums[j] > min_max.second)
                {
                    min_max.second = nums[j];
                }
                else if (nums[j] < min_max.first)
                {
                    min_max.first = nums[j];
                }
                res += min_max.second - min_max.first;
            }
        }
        return res;
    }
};
