#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> group_num_by_digit_sum;
        for (int num : nums)
        {
            group_num_by_digit_sum[digit_sum(num)].push(num);
        }
        int res = -1;
        for (auto &pair : group_num_by_digit_sum)
        {
            if (pair.second.size() >= 2)
            {
                int num1 = pair.second.top();
                pair.second.pop();
                int num2 = pair.second.top();
                pair.second.pop();
                res = max(res, num1 + num2);
            }
        }

        return res;
    }

    int digit_sum(int num)
    {
        int sum = 0;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
