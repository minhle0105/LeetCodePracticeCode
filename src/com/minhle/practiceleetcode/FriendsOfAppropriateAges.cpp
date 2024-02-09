#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        sort(ages.begin(), ages.end());
        for (int x = 0; x < ages.size(); ++x)
        {
            int lower_bound = find_first_greater_than(ages, 0.5 * ages[x] + 7);
            int upper_bound = find_first_greater_than(ages, ages[x]);

            // because we want to get all ages in range [lower_bound, upper_bound)
            // res += upper_bound - lower_bound;
            // and if x is in this range, it means there is one case where x = y --> need to exclude that
            // if (lower_bound <= x && x < upper_bound)
            // {
            //     --res;
            // }
            res += max(0, upper_bound - lower_bound - 1);
        }
        return res;
    }

    int find_first_greater_than(const vector<int> &ages, double target) {
        int left = 0;
        int right = ages.size() - 1;

        while (left < right - 1) 
        {
            int mid = left + (right - left) / 2;

            if (static_cast<double>(ages[mid]) > target) 
            {
                right = mid;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        if (ages[left] > target)
        {
            return left;
        }
        return ages[right] > target ? right : ages.size();
    }
};
