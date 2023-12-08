#include "AllNecessaryHeaders.h"

class Solution {
public:
    string reformat(string s) {
        vector<char> digits;
        vector<char> chars;
        for (char c : s)
        {
            if (isdigit(c))
            {
                digits.push_back(c);
            }
            else
            {
                chars.push_back(c);
            }
        }
        int i = 0;
        int j = 0;
        string res;
        if (abs(static_cast<int>(chars.size()) - static_cast<int>(digits.size())) > 1)
        {
            return "";
        }
        if (chars.size() < digits.size())
        {
            while (i < digits.size() && j < chars.size())
            {
                res += digits[i];
                res += chars[j];
                ++i;
                ++j;
            }
            if (digits.size() - i > 1)
            {
                return "";
            }
            if (i < digits.size())
            {
                res += digits[i];
            }
        }
        else
        {
            while (i < chars.size() && j < digits.size())
            {
                res += chars[i];
                res += digits[j];
                ++i;
                ++j;
            }
            if (chars.size() - j > 1)
            {
                return "";
            }
            if (j < chars.size())
            {
                res += chars[j];
            }
        }
        return res;
    }
};
