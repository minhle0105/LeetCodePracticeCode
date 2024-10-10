class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(1000, vector<int>(1000, -1));
        return 1 + recursion(n, 1, 1, dp);
    }

    int recursion(int n, int current_A, int paste_length, vector<vector<int>> &dp)
    {
        if (current_A == n)
        {
            return 0;
        }
        if (current_A > n)
        {
            return 1000;
        }
        if (dp[current_A][paste_length] != -1)
        {
            return dp[current_A][paste_length];
        }
        int paste = 1 + recursion(n, current_A + paste_length, paste_length, dp);
        int copy = 2 + recursion(n, current_A * 2, current_A, dp);
        dp[current_A][paste_length] = min(paste, copy);
        return dp[current_A][paste_length];
    }
};
