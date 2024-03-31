class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> merged(nums.size(), 0);
        merged.back() = nums.back();


        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] <= merged[i + 1])
            {
                merged[i] = merged[i + 1] + nums[i];
            }
            else
            {
                merged[i] = nums[i];
            }
        }
        return merged.front();
    }
};
