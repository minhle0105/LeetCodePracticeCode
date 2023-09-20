#include <vector>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i + k <= nums.size(); ++i)
        {
            res = min(res, nums.at(i + k - 1) - nums.at(i));
        }
        return res;
    }
};
