class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        vector<long long> prefix_sum = {0};
        for (int num : nums)
        {
            prefix_sum.push_back(num + prefix_sum.back());
        }

        long long res = LLONG_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            res = max(res, max(prefix_sum[i + 1], prefix_sum.back() - prefix_sum[i]));
        }
        return res;
    }
};
