#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string> res;
        backtrack(n, n, curr, res);
        return res;
    }

    void backtrack(int nOpen, int nClose, string &curr, vector<string> &res)
    {
        if (nClose == 0)
        {
            res.push_back(curr);
            return;
        }
        if (nOpen > 0)
        {
            curr += "(";
            --nOpen;
            backtrack(nOpen, nClose, curr, res);
            ++nOpen;
            curr.pop_back();
        }

        // neu da hop le roi thi ko them duoc )
        if (nClose > nOpen)
        {
            curr += ")";
            --nClose;
            backtrack(nOpen, nClose, curr, res);
            ++nClose;
            curr.pop_back();
        }
    }
};
