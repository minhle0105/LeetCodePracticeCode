#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size())
        {
            return false;
        }
        return two_pointers_check(s, t, 0, 0);
    }
    bool two_pointers_check(const string &s, const string &t, int i, int j)
    {
        if (i == s.size())
        {
            return true;
        }
        if (j == t.size())
        {
            return false;
        }
        if (s[i] == t[j])
        {
            return two_pointers_check(s, t, i + 1, j + 1);
        }
        return two_pointers_check(s, t, i, j + 1);
    }
};