#include <vector>

using namespace std;

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int res = 0;
        int current_sum = 0;
        for (int i = 0; i < k; ++i)
        {
            current_sum += calories.at(i);
        }
        res += evaluate(lower, upper, current_sum);
        for (int i = 1; i + k <= calories.size(); ++i)
        {
            current_sum -= calories.at(i - 1);
            current_sum += calories.at(i + k - 1);
            res += evaluate(lower, upper, current_sum);
        }
        return res;
    }

    int evaluate(int lower, int upper, int current)
    {
        if (current < lower)
        {
            return -1;
        }
        return current > upper ? 1 : 0;
    }
};
