class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diffs(nums.size() + 1, 0);
        for (int i = 1; i < nums.size(); ++i)
        {
            diffs[i] = nums[i] - nums[i - 1];
        }
        for (const auto &query : queries)
        {
            --diffs[query[0]];
            ++diffs[query[1] + 1];
        }
        nums[0] = nums[0] + diffs[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] = nums[i - 1] + diffs[i];
        }
        for (int num : nums)
        {
            if (num > 0)
            {
                return false;
            }
        }
        return true;
    }
};

