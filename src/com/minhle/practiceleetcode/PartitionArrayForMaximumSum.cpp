class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int res = 0;
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < arr.size(); ++i)
        {
            res = max(res, recursion(arr, k, i, dp));
        }
        return res;
    }

    int recursion(const vector<int> &arr, int k, int i, vector<int> &dp)
    {
        if (i >= arr.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int max_ = 0;
        dp[i] = 0;

        for (int j = i; j < min(i + k, (int)arr.size()); ++j)
        {
            max_ = max(max_, arr[j]);
            dp[i] = max(dp[i], max_ * (j - i + 1) + recursion(arr, k, j + 1, dp));
        }
        return dp[i];
    }
};
