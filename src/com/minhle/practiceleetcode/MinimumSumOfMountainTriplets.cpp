#include <vector>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (nums[j] > nums[i] && nums[j] > nums[k])
                    {
                        res = min(res, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
