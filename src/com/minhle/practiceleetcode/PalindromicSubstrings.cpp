#include "AllNecessaryHeaders.h"

class Solution {
public:
    int countSubstrings(string s) {
        // expanding from center
        int res = 0;

        // for odd-length palindrome
        for (int i = 0; i < s.size(); ++i)
        {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                ++res;
                --left;
                ++right;
            }
        }

        // for even-length palindromme
        for (int i = 0; i < s.size(); ++i)
        {
            int left = i;
            int right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                ++res;
                --left;
                ++right;
            }
        }
        return res;
    }
};
