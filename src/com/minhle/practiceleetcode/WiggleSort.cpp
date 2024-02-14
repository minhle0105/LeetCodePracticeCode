#include "AllNecessaryHeaders.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while (left < right)
        {
            res.push_back(nums[left]);
            res.push_back(nums[right]);
            ++left;
            --right;
        }
        if (nums.size() % 2 != 0)
        {
            res.push_back(nums[left]);
    }
        nums = res;
    }
};
