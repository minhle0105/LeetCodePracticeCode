#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
        }
        for (const auto &pair : counter)
        {
            if (pair.second % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }
};
