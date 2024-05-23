class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k_value) {
        res = 0;
        k = k_value;
        vector<int> current_subset;
        backtracking(nums, current_subset, 0);
        return res;
    }
private:
    int res;
    int k;
    void backtracking(const vector<int> &nums, vector<int> &current_subset, int pos)
    {
        for (int i = pos; i < nums.size(); ++i)
        {
            current_subset.push_back(nums[i]);
            if (!is_beautiful(current_subset))
            {
                current_subset.pop_back();
                continue;
            }
            ++res;
            backtracking(nums, current_subset, i + 1);
            current_subset.pop_back();
        }
    }

    bool is_beautiful(const vector<int> &subset)
    {
        if (subset.empty())
        {
            return false;
        }
        for (int i = 0; i < subset.size() - 1; ++i)
        {
            if (abs(subset[i] - subset.back()) == k)
            {
                return false;
            }
        }
        return true;
    }
};
