#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int left = 0;
        int right = 1;
        while (right < nums.size())
        {
            while (right < nums.size() && nums[right] > nums[right - 1])
            {
                ++right;
            }
            res = max(res, right - left);
            left = right;
            right = left + 1;
        }
        return res;
    }
};
