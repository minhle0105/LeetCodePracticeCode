#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int current_sum = 0;
        int right_pointer = 0;
        int left_pointer = 0;
        // [left_pointer, right_pointer)
        while (right_pointer < nums.size())
        {
            current_sum += nums.at(right_pointer);
            ++right_pointer;
            while (left_pointer < nums.size() && current_sum >= target)
            {
                res = min(res, right_pointer - left_pointer);
                ++left_pointer;
                current_sum -= nums.at(left_pointer - 1);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
