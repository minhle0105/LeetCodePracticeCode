#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left_sum(nums.size(), 0);
        vector<int> right_sum(nums.size(), 0);
        vector<int> res(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i)
        {
            left_sum.at(i) = left_sum.at(i - 1) + nums.at(i - 1);
        }
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            right_sum.at(i) = right_sum.at(i + 1) + nums.at(i + 1);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            res.at(i) = abs(left_sum.at(i) - right_sum.at(i));
        }
        return res;
    }
};
