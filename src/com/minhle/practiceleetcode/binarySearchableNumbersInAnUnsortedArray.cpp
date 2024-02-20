#include "AllNecessaryHeaders.h"

class Solution {
public:
    // basically we need to find all elements that are
    // 1. STRICTLY LESS THAN all elements to the right
    // 2. STRICTLY GREATER THAN all elements to the left
    int binarySearchableNumbers(vector<int>& nums) {
        stack<int> mono_increasing_stack;
        int max_so_far = INT_MIN;
        for (int num : nums)
        {
            while (!mono_increasing_stack.empty() && mono_increasing_stack.top() > num)
            {
                mono_increasing_stack.pop();
            }
            if (num > max_so_far)
            {
                mono_increasing_stack.push(num);
                max_so_far = num;
            }
        }
        return mono_increasing_stack.size();
    }
};
