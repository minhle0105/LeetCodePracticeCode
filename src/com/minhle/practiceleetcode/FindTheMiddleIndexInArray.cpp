#include <vector>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> left_sum(nums.size() + 1, 0);
        vector<int> right_sum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i)
        {
            left_sum.at(i) = left_sum.at(i - 1) + nums.at(i - 1);
        }
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            right_sum.at(i) = right_sum.at(i + 1) + nums.at(i);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (left_sum.at(i) == right_sum.at(i + 1))
            {
                return i;
            }
        }
        return -1;
    }
};
