#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> sums;
        for (int num : nums)
        {
            sums[find_max_digit(num)].push(num);
        }

        int res = -1;
        for (auto &pair : sums)
        {
            if (pair.second.size() >= 2)
            {
                int a = pair.second.top();
                pair.second.pop();
                int b = pair.second.top();
                pair.second.pop();
                res = max(res, a + b);
            }
        }
        return res;
    }
    int find_max_digit(int num)
    {
        int max_digit = -1;
        while (num != 0)
        {
            max_digit = max(max_digit, num % 10);
            num /= 10;
        }
        return max_digit;
    }
};
