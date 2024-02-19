#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int score = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i += 2)
        {
            int new_score = nums[i] + nums[i + 1];
            if (score == 0)
            {
                score += new_score;
            }
            else
            {
                if (new_score != score)
                {
                    return res;
                }
            }
            ++res;
        }
        return res;
    }
};
