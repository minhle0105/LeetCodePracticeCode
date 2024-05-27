class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i; j < nums.size(); ++j)
            {
                if (increasing(build_array(nums, i, j)))
                {
                    ++res;
                }
            }
        }
        return res;
    }
private:
    vector<int> build_array(const vector<int> &nums, int start, int end)
    {
        vector<int> res;
        res.reserve(nums.size() - (end - start + 1));
        for (int i = 0; i < nums.size(); ++i)
        {
            if (start <= i && i <= end)
            {
                continue;
            }
            res.push_back(nums[i]);
        }
        return res;
    }

    bool increasing(const vector<int> &nums)
    {
        if (nums.empty())
        {
            return true;
        }
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};
