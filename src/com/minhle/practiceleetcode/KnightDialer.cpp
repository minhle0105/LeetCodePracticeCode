#include "AllNecessaryHeaders.h"

class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> dp(10, vector<int>(n + 1, -1));
        movements[0] = {4,6};
        movements[1] = {6,8};
        movements[2] = {7,9};
        movements[3] = {4,8};
        movements[4] = {3,9,0};
        movements[5] = {};
        movements[6] = {1,7,0};
        movements[7] = {2,6};
        movements[8] = {1,3};
        movements[9] = {2,4};
        int res = 0;
        for (int i = 0; i <= 9; ++i)
        {
            res += recursion(n, 1, i, dp);
            res %= MODULO;
        }
        return res;
    }
private:
    unordered_map<int, vector<int>> movements;
    const int MODULO = pow(10,9) + 7;

    int recursion(const int n, int step, int current_number, vector<vector<int>> &dp)
    {
        if (dp[current_number][step] != -1)
        {
            return dp[current_number][step];
        }
        if (step == n)
        {
            dp[current_number][step] = 1;
            return 1;
        }
        dp[current_number][step] = 0;
        for (int next : movements[current_number])
        {
            dp[current_number][step] += recursion(n, step + 1, next, dp);
            dp[current_number][step] %= MODULO;
        }
        dp[current_number][step] %= MODULO;
        return dp[current_number][step];
    }
};
