#include "AllNecessaryHeaders.cpp"

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i = 0; i < s.size() / 2; ++i)
        {
            if (s[i] == s[s.size() - i - 1])
            {
                continue;
            }
            if (s[i] < s[s.size() - i - 1])
            {
                s[s.size() - i - 1] = s[i];
            }
            else
            {
                s[i] = s[s.size() - i - 1];            
            }
        }
        return s;
    }
};
