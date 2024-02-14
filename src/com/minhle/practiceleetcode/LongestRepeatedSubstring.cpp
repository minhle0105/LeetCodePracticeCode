#include "AllNecessaryHeaders.h"

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int left = 2;
        int right = s.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (existSubstring(s, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (existSubstring(s, right))
        {
            return right;
        }
        return existSubstring(s, left) ? left : 0;
    }

    bool existSubstring(const string &s, int len)
    {
        int n = static_cast<int>(s.size());
        unordered_set<string> seen;
        for (int i = 0; i <= n - len; ++i)
        {
            string sub = s.substr(i, len);
            if (seen.find(sub) != seen.end())
            {
                return true;
            }
            seen.insert(sub);
        }
        return false;
    }
};
