#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(k, vector<int>(prices.size(), 0));

        // prep -> max profit from day i to day j if we only have 1 transaction
        vector<vector<int>> prep(prices.size(), vector<int>(prices.size(), 0));

        for (int i = 0; i < prices.size(); ++i)
        {
            int current_min = prices[i];
            int max_profit = 0;
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] < current_min)
                {
                    current_min = prices[j];
                }
                else
                {
                    max_profit = max(max_profit, prices[j] - current_min);
                }
                prep[i][j] = max_profit;
            }
        }

        dp[0] = prep[0];

        for (int t = 1; t < k; ++t)
        {
            for (int day = 0; day < prices.size(); ++day)
            {
                dp[t][day] = dp[t - 1][day];
                for (int i = 0; i < day; ++i)
                {
                    dp[t][day] = max(dp[t][day], dp[t - 1][i] + prep[i + 1][day]);
                }
            }
        }
        return dp.back().back();
    }
};

