#include "AllNecessaryHeaders.h"

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candies;
        for (int type : candyType)
        {
            candies.insert(type);
        }
        return min(candies.size(), candyType.size() / 2);
    }
};
