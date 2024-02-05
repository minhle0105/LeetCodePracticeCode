#include "AllNecessaryHeaders.h"

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> counter;
        for (char c : s)
        {
            if (counter.find(c) != counter.end())
            {
                return c;
            }
            counter.insert(c);
        }
        return ' ';
    }
};
