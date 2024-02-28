#include "AllNecessaryHeaders.h"

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        int N = nums.size();
        vector<double> prefix_sum;
        prefix_sum.reserve(nums.size() + 1);
        prefix_sum.push_back(0);
        for (int num : nums)
            prefix_sum.push_back(num + prefix_sum.back());

        vector<double> dp(N);
        for (int i = 0; i < N; ++i)
        {
            dp[i] = (prefix_sum.back() - prefix_sum[i]) / (N - i);
        }

        for (int nPart = 1; nPart < K; ++nPart)
        {
            for (int i = 0; i < nums.size() - 1; ++i)
            {
                for (int j = i + 1; j < nums.size(); ++j)
                {
                    auto first_half_avg = static_cast<double>((prefix_sum[j] - prefix_sum[i])) / (j - i);
                    auto second_half_avg = dp[j];
                    dp[i] = max(dp[i], first_half_avg + second_half_avg);
                }
            }
        }
        return dp.front();
    }
};

