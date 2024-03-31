class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> counter;
        int i = 0;
        int j = 0;
        const int n = nums.size();

        while (j < n)
        {
            if (counter.find(nums[j]) == counter.end() || counter[nums[j]] < k)
            {
                ++counter[nums[j]];
                ++j;
            }
            res = max(res, j - i);
            if (j == n)
            {
                break;
            }
            while (i < j && counter[nums[j]] == k)
            {
                --counter[nums[i]];
                ++i;
            }
        }
        return res;
    }
};
