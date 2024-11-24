class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int count_zero = 0;
        for (int num : nums)
        {
            count_zero += (num == 0);
        }
        if (count_zero == nums.size())
        {
            return 0;
        }
        int left = 0;
        int right = queries.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (can_make_zero_array(nums, queries, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (can_make_zero_array(nums, queries, left))
        {
            return left + 1;
        }
        if (can_make_zero_array(nums, queries, right))
        {
            return right + 1;
        }
        return -1;
    }

    bool can_make_zero_array(const vector<int> &nums, const vector<vector<int>> &queries, int k)
    {
        vector<int> diff(nums.size() + 1, 0);
        for (int i = 0; i <= k; ++i)
        {
            auto query = queries[i];
            diff[query[0]] -= query[2];
            diff[query[1] + 1] += query[2];
        }

        if (nums[0] > (-1) * diff[0])
        {
            return false;
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            diff[i] += diff[i - 1];
            if (nums[i] > (-1) * diff[i])
            {
                return false;
            }   
        }
        return true;
    }
};
