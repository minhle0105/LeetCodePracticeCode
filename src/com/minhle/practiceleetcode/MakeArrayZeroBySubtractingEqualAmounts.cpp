#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        while (true)
        {
            int smallest = INT_MAX;
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] == 0)
                {
                    continue;
                }
                smallest = min(smallest, nums[i]);
            }
            int count_zeros = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] == 0)
                {
                    ++count_zeros;
                    continue;
                }
                nums[i] -= smallest;
            }
            if (count_zeros == nums.size())
            {
                break;
            }
            ++res;
        }
        return res;
    }
};

