#include "AllNecessaryHeaders.h"

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        vector<int> lis_length(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        int max_lis_length = 0;
        int res = 0;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int lis_length_from_here = 1;
            int count_from_here = 1;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] < nums[j])
                {
                    if (lis_length[j] + 1 > lis_length_from_here)
                    {
                        lis_length_from_here = lis_length[j] + 1;
                        count_from_here = count[j];
                    }
                    else if (lis_length[j] + 1 == lis_length_from_here)
                    {
                        count_from_here += count[j];
                    }
                }
            }
            if (lis_length_from_here > max_lis_length)
            {
                max_lis_length = lis_length_from_here;
                res = count_from_here;
            }
            else if (lis_length_from_here == max_lis_length)
            {
                res += count_from_here;
            }
            lis_length[i] = lis_length_from_here;
            count[i] = count_from_here;
        }
        return res;
    }
};
