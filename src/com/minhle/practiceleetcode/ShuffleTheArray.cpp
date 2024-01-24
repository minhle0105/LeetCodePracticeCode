#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(nums.size(), 0);
        int pos = 0;
        int i = 0; 
        int j = i + n;
        while (pos < nums.size())
        {
            res[pos] = nums[i];
            ++pos;
            res[pos] = nums[j];
            ++pos;
            ++i;
            ++j;
        }
        return res;
    }
};
