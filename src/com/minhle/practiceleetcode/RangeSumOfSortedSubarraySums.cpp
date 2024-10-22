class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefix_sums = {0};
        for (int num : nums)
        {
            prefix_sums.push_back(num + prefix_sums.back());
        }

        vector<int> all_sums;
        for (int i = 0; i < prefix_sums.size() - 1; ++i)
        {
            for (int j = i + 1; j < prefix_sums.size(); ++j)
            {
                all_sums.push_back(prefix_sums[j] - prefix_sums[i]);
            }
        }

        sort(all_sums.begin(), all_sums.end());
        int res = 0;
        const int MOD = pow(10, 9) + 7;
        for (int i = left; i <= right; ++i)
        {
            res += all_sums[i - 1];
            res %= MOD;
        }
        return res;
    }
};
