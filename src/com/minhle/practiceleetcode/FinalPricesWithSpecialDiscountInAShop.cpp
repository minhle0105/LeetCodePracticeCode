#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size(), 0);
        stack<pair<int, int>> mono_stack;

        for (int i = 0; i < prices.size(); ++i)
        {
            while (!mono_stack.empty() && prices[i] <= mono_stack.top().first)
            {
                res[mono_stack.top().second] = mono_stack.top().first - prices[i];
                mono_stack.pop();
            }
            mono_stack.push({prices[i], i});
        }
        while (!mono_stack.empty())
        {
            auto pos = mono_stack.top().second;
            res[pos] = prices[pos];
            mono_stack.pop();
        }
        return res;
    }
};
