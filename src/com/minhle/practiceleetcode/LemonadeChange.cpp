#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> billCounts(3, 0);
        for (int bill : bills)
        {
            if (bill == 5)
            {
                ++billCounts[0];
            }
            else if (bill == 10)
            {
                ++billCounts[1];
                --billCounts[0];
                if (billCounts[0] < 0)
                {
                    return false;
                }
            }
            else
            {
                ++billCounts[2];
                if (billCounts[0] > 0 && billCounts[1] > 0)
                {
                    --billCounts[0];
                    --billCounts[1];
                }
                else if (billCounts[0] >= 3)
                {
                    billCounts[0] -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
;
