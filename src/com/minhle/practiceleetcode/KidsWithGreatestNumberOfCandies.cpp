#include <vector>

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = INT_MIN;
        for (int candy : candies)
        {
            maxCandies = max(candy, maxCandies);
        }
        vector<bool> res;
        res.reserve(candies.size());
        for (int candy : candies)
        {
            int newCandy = candy + extraCandies;
            if (newCandy >= maxCandies)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};

