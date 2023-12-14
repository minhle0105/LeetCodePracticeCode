#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        string curr;
        backtracking(n, k, res, curr);
        return res;
    }

    void backtracking(int n, int k, vector<int> &res, string &curr)
    {
        if (curr.size() == n)
        {
            res.push_back(stoi(curr));
            return;
        }
        if (curr.empty())
        {
            for (int i = 1; i <= 9; ++i)
            {
                curr += to_string(i);
                backtracking(n, k, res, curr);
                curr.pop_back();
            }
        }
        else
        {
            int last_digit = curr.back() - '0';
            if (last_digit + k <= 9)
            {
                curr += to_string(last_digit + k);
                backtracking(n, k, res, curr);
                curr.pop_back();
            }
            if (last_digit - k >= 0 && last_digit - k != last_digit + k)
            {
                curr += to_string(last_digit - k);
                backtracking(n, k, res, curr);
                curr.pop_back();
            }
        }
    }
};
