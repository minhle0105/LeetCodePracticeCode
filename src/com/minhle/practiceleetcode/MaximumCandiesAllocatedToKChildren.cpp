#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int right = INT_MAX;
        for (int candy : candies)
        {
            sum += candy;
            right = max(candy, right);
        }
        if (sum < k)
        {
            return 0;
        }
        int left = 1;
        while (left < right - 1)
        {
            int mid = left + ((right - left) / 2);
            if (qualified(candies, k, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return qualified(candies, k, right) ? right : left;
    }

    bool qualified(const vector<int> &candies, const long long k, const int divisor)
    {
        long long count = 0;
        for (const int &c : candies)
        {
            count += c / divisor;
            if (count >= k)
            {
                return true;
            }
        }
        return false;
    }
};
