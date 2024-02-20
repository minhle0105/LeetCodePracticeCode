#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int, int> counter;
        for (int num : arr1)
        {
            ++counter[num];
        }
        for (int num : arr2)
        {
            if (counter.find(num) != counter.end())
            {
                int placed = 0;
                while (placed < counter[num])
                {
                    res.push_back(num);
                    ++placed;
                }
                counter.erase(num);
            }
        }
        for (const auto &pair : counter)
        {
            int placed = 0;
            while (placed < pair.second)
            {
                res.push_back(pair.first);
                ++placed;
            }
        }
        return res;
    }
};
