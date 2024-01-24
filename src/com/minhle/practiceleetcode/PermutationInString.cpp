#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
        {
            return false;
        }

        sort(s1.begin(), s1.end());
        return check_all_substrings(s1, s2);
    }

private:
    bool check_all_substrings(const string &s1, const string &s2)
    {
        for (int i = 0; i + s1.size() <= s2.size(); ++i)
        {
            auto substring = s2.substr(i, s1.size());
            sort(substring.begin(), substring.end());
            if (contains(s1, substring))
            {
                return true;
            }
        }
        return false;
    }

    bool contains(const string &s1, const string &s2)
    {
        for (int pos = 0; pos + s1.size() <= s2.size(); ++pos)
        {
            bool this_turn = true;
            for (int i = 0; i < s1.size(); ++i)
            {
                if (s2[pos + i] != s1[i])
                {
                    this_turn = false;
                    break;
                }
            }
            if (this_turn)
            {
                return true;
            }
        }
        return false;
    }
};