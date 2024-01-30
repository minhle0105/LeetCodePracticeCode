#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        recursion(s, 0, dp);
        return dp[0];
    }

    int recursion(const string &s, int i, vector<int> &dp)
    {
        if (i >= s.size())
        {
            return 0;
        }
        if (i == s.size() - 1)
        {
            dp[i] = s[i] == '0' ? 0 : 1;
            return dp[i];
        }
        if (i == s.size() - 2)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                auto num = stoi(s.substr(i, 2));
                if (1 <= num && num <= 26)
                {
                    dp[i] = num % 10 == 0 ? 1 : 2;
                }
                else
                {
                    dp[i] = num % 10 == 0 ? 0 : 1;
                }
            }
            return dp[i];
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        if (s[i] == '0')
        {
            dp[i] = 0;
        }
        else
        {
            auto num1 = stoi(s.substr(i, 1));
            auto num2 = stoi(s.substr(i, 2));
            auto case1 = 1 <= num1 && num1 <= 26 ? recursion(s, i + 1, dp) : 0;
            auto case2 = 1 <= num2 && num2 <= 26 ? recursion(s, i + 2, dp) : 0;
            dp[i] = case1 + case2;
        }
        return dp[i];
    }
};
