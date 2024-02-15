#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> counter;
        for (char c : s)
        {
            ++counter[c];
        }
        int unique_frequency = 0;
        for (const auto &pair : counter)
        {
            if (unique_frequency == 0)
            {
                unique_frequency = pair.second;
            }
            else if (pair.second != unique_frequency)
            {
                return false;
            }
        }
        return true;
    }
};
