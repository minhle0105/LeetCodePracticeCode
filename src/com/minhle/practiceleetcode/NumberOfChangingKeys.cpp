#include "AllNecessaryHeaders.h"

class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1] || tolower(s[i]) == tolower(s[i - 1]))
            {
                continue;
            }
            ++count;
        }
        return count;
    }
};
