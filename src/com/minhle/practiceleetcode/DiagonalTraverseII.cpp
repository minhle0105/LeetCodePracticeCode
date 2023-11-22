#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> groups;
        for (int row = nums.size() - 1; row >= 0; --row)
        {
            for (int col = 0; col < nums[row].size(); ++col)
            {
                groups[row + col].push_back(nums[row][col]);
            }
        }

        vector<int> res;
        int group = 0;
        while (groups.find(group) != groups.end())
        {
            for (int num : groups[group])
            {
                res.push_back(num);
            }
            ++group;
        }
        return res;
    }
};
