class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        set<vector<int>> all_quads;
        for (int i = 0; i < nums.size(); ++i)
        {
            int a = nums[i];
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int b = nums[j];
                long long half_sum = a + b;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    long long sum = half_sum + nums[left] + nums[right];
                    if (sum < target)
                    {
                        ++left;
                    }
                    else if (sum > target)
                    {
                        --right;
                    }
                    else
                    {
                        all_quads.insert({a, b, nums[left], nums[right]});
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1])
                        {
                            ++left;
                        }
                    }
                }
            }
        }
        vector<vector<int>> res(all_quads.begin(), all_quads.end());
        return res;
    }
};
