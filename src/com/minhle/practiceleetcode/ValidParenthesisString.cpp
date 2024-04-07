class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return helper(s, 0, 0, dp);
    }
private:
    bool helper(const string &s, int i, int count, vector<vector<int>> &dp)
    {
        if (count < 0)
        {
            return false;
        }
        if (i == s.size())
        {
            return count == 0;
        }
        if (dp[i][count] != -1)
        {
            return dp[i][count] == 1;
        }
        dp[i][count] = 0;
        if (s[i] == '(')
        {
            dp[i][count] = dp[i][count] == 1 || helper(s, i + 1, count + 1, dp);
        }
        else if (s[i] == ')')
        {
            dp[i][count] = dp[i][count] == 1 || helper(s, i + 1, count - 1, dp);
        }
        else
        {
            dp[i][count] |= dp[i][count] == 1 ||  
                             (helper(s, i + 1, count + 1, dp) || 
                              helper(s, i + 1, count - 1, dp) || 
                              helper(s, i + 1, count, dp));
        }
        return dp[i][count];
    }
};
