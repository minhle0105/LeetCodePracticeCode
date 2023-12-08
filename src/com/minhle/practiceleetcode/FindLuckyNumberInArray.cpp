#include "AllNecessaryHeaders.h"

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res = INT_MIN;
        unordered_map<int, int> counter;
        for (int num : arr)
        {
            ++counter[num];
        }
        for (const auto &pair : counter)
        {
            if (pair.first == pair.second)
            {
                res = max(res, pair.first);
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};
