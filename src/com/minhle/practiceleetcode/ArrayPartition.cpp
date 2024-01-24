#include "AllNecessaryHeaders.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int num1, const int num2){
            return num1 > num2;
        });
        int res = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            res += min(nums[i], nums[i + 1]);
        }
        return res;
    }
};
