#include "AllNecessaryHeaders.h"

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); ++i)
        {
            pos[nums[i]].push_back(i);
        }
        unordered_map<int, int> counter;
        for (const auto &pair : pos)
        {
            int target = pair.first;
            for (int i : pair.second)
            {
                if (i != 0 && nums[i - 1] == key)
                {
                    ++counter[target];
                }
            }
        }
        int max_count = 0;
        int target = -1;
        for (const auto &pair : counter)
        {
            if (pair.second > max_count)
            {
                max_count = pair.second;
                target = pair.first;
            }
        }
        return target;
    }
};
