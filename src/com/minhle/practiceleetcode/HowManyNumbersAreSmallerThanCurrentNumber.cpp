#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy_nums;
        copy(nums.begin(), nums.end(), back_inserter(copy_nums));
        sort(copy_nums.begin(), copy_nums.end());
        unordered_map<int, int> map_res;
        for (int i = 0; i < copy_nums.size(); ++i)
        {
            if (map_res.find(copy_nums[i]) == map_res.end())
            {
                map_res[copy_nums[i]] = i;
            }
        }
        vector<int> res;
        for (int num : nums)
        {
            res.push_back(map_res[num]);
        }
        return res;
    }
};
