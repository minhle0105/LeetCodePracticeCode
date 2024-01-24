#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_roll = 0;
        for (int roll : rolls)
        {
            sum_roll += roll;
        }
        int sum = mean * (rolls.size() + n) - sum_roll;
        if (sum > 6 * n || sum < 0)
        {
            return vector<int>{};
        }
        int current_value = 6;
        int current_sum = current_value * n;
        while (current_sum > sum)
        {
            --current_value;
            current_sum = current_value * n;
        }
        if (current_value == 0)
        {
            return vector<int>{};
        }

        vector<int> res(n, current_value);
        if (current_sum == sum)
        {
            return res;
        }
        while (current_sum != sum)
        {
            for (int &num : res)
            {
                if (num < 6)
                {
                    ++num;
                    ++current_sum;
                }
                if (current_sum == sum)
                {
                    return res;
                }
            }
        }
        return res;
    }
};
