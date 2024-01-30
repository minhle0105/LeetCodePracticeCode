#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto left_to_right = going_from_left(prices);
        auto right_to_left = going_from_right(prices);
        int res = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            res = max(res, left_to_right[i] + right_to_left[i + 1]);
        }
        res = max(res, left_to_right.back());
        return res;
    }

private:
    vector<int> going_from_left(vector<int>& prices) {
        int current_min = prices.front();
        int max_profit = 0;
        vector<int> dp;
        for (int price : prices)
        {
            if (price < current_min)
            {
                current_min = price;
            }
            else
            {
                max_profit = max(max_profit, price - current_min);
            }
            dp.push_back(max_profit);
        }
        return dp;
    }

    vector<int> going_from_right(vector<int> prices)
    {
        int current_max = prices.back();
        int max_profit = 0;
        vector<int> dp(prices.size(), 0);
        for (int i = prices.size() - 1; i >= 0; --i)
        {
            auto price = prices[i];
            if (price > current_max)
            {
                current_max = price;
            }
            else
            {
                max_profit = max(max_profit, current_max - price);
            }
            dp[i] = max_profit;
        }
        return dp;
    }
};
