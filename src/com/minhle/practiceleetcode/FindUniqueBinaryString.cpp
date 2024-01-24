#include "AllNecessaryHeaders.h"

class Solution {
public:
    string res;
    string findDifferentBinaryString(vector<string>& nums) {
        res = "";
        unordered_set<string> nums_set;
        for (string num : nums)
        {
            nums_set.insert(num);
        }
        string curr;
        backtracking(nums_set, curr, nums.size());
        return res;
    }

    void backtracking(unordered_set<string> &nums, string &curr, int n)
    {
        if (curr.size() == n)
        {
            if (nums.find(curr) == nums.end())
            {
                res = curr;
            }
            return;
        }
        if (res != "")
        {
            return;
        }
        curr += "0";
        backtracking(nums, curr, n);
        curr.pop_back();
        curr += "1";
        backtracking(nums, curr, n);
        curr.pop_back();
    }
};
