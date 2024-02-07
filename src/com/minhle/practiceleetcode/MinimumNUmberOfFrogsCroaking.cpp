#include "AllNecessaryHeaders.h"

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        const string croak = "croak";
        unordered_map<char, int> counter;
        for (char c : croak)
        {
            counter[c] = 0;
        }

        int res = 0;
        for (char c : croakOfFrogs)
        {
            if (c == 'c')
            {
                ++counter[c];
            }
            else if (c == 'r')
            {
                ++counter[c];
                if (counter['c'] < counter[c])
                {
                    return -1;
                }
            }
            else if (c == 'o')
            {
                ++counter[c];
                if (counter['r'] < counter[c])
                {
                    return -1;
                }
            }
            else if (c == 'a')
            {
                ++counter[c];
                if (counter['o'] < counter[c])
                {
                    return -1;
                }
            }
            else
            {
                ++counter[c];
                if (counter['c'] < counter[c])
                {
                    return -1;
                }
                res = max(res, counter['c']);
                for (char c_ : croak)
                {
                    --counter[c_];
                }
            }
        }
        for (const auto &pair : counter)
        {
            if (pair.second != 0)
            {
                return -1;
            }
        }
        return res;
    }
};

