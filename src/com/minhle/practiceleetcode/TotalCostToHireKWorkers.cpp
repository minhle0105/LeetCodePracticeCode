#include "AllNecessaryHeaders.h"

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res = 0;
        int round = 0;

        int i = 0;
        int j = max(candidates, static_cast<int>(costs.size()) - candidates);
        priority_queue<int, vector<int>, greater<int>> heap1;
        priority_queue<int, vector<int>, greater<int>> heap2;

        while (i < candidates)
        {
            heap1.push(costs[i]);
            ++i;
        }

        while (j < costs.size())
        {
            heap2.push(costs[j]);
            ++j;
        }

        i = candidates;
        j = costs.size() - candidates - 1;

        while (round < k)
        {
            if (heap2.empty() || !heap1.empty() && heap1.top() <= heap2.top())
            {
                res += heap1.top();
                heap1.pop();
                if (i <= j)
                {
                    heap1.push(costs[i]);
                    ++i;
                }
            }
            else
            {
                res += heap2.top();
                heap2.pop();
                if (i <= j)
                {
                    heap2.push(costs[j]);
                    --j;
                }
            }
            ++round;
        }
        return res;
    }
};

