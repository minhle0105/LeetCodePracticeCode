#include "AllNecessaryHeaders.h"

class Solution {
public:
    int scoreOfParentheses(string s) {
        if (s.size() == 2)
        {
            return 1;
        }
        int nOpens = 0;
        int break_point = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (c == '(')
            {
                ++nOpens;
            }
            else
            {
                --nOpens;
            }
            if (nOpens == 0 && i != s.size() - 1)
            {
                break_point = i;
                break;
            }
        }
        if (break_point == -1)
        {
            return 2 * scoreOfParentheses(s.substr(1, s.size() - 2));
        }
        return scoreOfParentheses(s.substr(0, break_point + 1)) + scoreOfParentheses(s.substr(break_point + 1, s.size() - break_point - 1));
    }
};
