#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> res;
        backtrack(n * 2, curr, res);
        return res;
    }

    void backtrack(int n, string &curr, vector<string> &res)
    {
        if (curr.size() == n)
        {
            if (check_valid_parentheses(curr))
            {
                res.push_back(curr);
            }
            return;
        }
        curr += "(";
        backtrack(n, curr, res);
        curr.pop_back();
        curr += ")";
        backtrack(n, curr, res);
        curr.pop_back();
    }

    bool check_valid_parentheses(string &parentheses)
    {
        int nOpen = 0;
        for (char c : parentheses)
        {
            if (c == '(')
            {
                ++nOpen;
            }
            else
            {
                if (nOpen == 0)
                {
                    return false;
                }
                --nOpen;
            }
        }
        return nOpen == 0;
    }
};
