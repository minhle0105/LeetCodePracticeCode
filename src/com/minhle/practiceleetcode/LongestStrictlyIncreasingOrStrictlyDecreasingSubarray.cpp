class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(lis(nums), lds(nums));
    }

    int lis(const vector<int> &nums)
    {
        int res = 1;
        int left = 0;
        while (left < nums.size())
        {
            int right = left;
            while (right < nums.size() - 1 && nums[right] < nums[right + 1])
            {
                ++right;
            }
            res = max(res, right - left + 1);
            left = right + 1;
        }
        return res;
    }

    int lds(const vector<int> &nums)
    {
        int res = 1;
        int left = 0;
        while (left < nums.size())
        {
            int right = left;
            while (right < nums.size() - 1 && nums[right] > nums[right + 1])
            {
                ++right;
            }
            res = max(res, right - left + 1);
            left = right + 1;
        }
        return res;
    }
};
