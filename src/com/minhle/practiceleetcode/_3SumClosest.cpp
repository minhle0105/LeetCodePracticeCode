#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int diff = INT_MAX;
        int i = 0;
        while (i < nums.size())
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int curr_sum = nums.at(i) + nums.at(left) + nums.at(right);
                int new_diff = abs(target - curr_sum);
                if (new_diff == 0)
                {
                    return curr_sum;
                }
                if (new_diff < diff)
                {
                    diff = new_diff;
                    res = curr_sum;
                }
                if (curr_sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
            ++i;
        }
        return res;
    }
};
