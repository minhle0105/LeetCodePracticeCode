#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_point = 0;

        while (buy_point < prices.size())
        {
            while (buy_point < prices.size() - 1 && prices[buy_point] >= prices[buy_point + 1])
            {
                ++buy_point;
            }
            if (buy_point == prices.size() - 1)
            {
                break;
            }
            int sell_point = buy_point + 1;
            while (sell_point < prices.size() - 1 && prices[sell_point] <= prices[sell_point + 1])
            {
                ++sell_point;
            }
            max_profit += (prices[sell_point] - prices[buy_point]);
            buy_point = sell_point;
        }
        return max_profit;
    }
};
