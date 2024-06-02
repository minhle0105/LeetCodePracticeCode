class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp;
        dp.reserve(energy.size());
        for (int e : energy)
        {
            dp.push_back(e);
        }
        int res = INT_MIN;
        for (int i = 0; i < dp.size(); ++i)
        {
            recursion(energy, dp, i, k);
            res = max(res, dp[i]);
        }
        return res;
    }

    int recursion(const vector<int> &energy, vector<int> &dp, int pos, int k)
    {
        if (pos >= energy.size())
        {
            return 0;
        }
        if (dp[pos] != energy[pos])
        {
            return dp[pos];
        }
        dp[pos] = energy[pos] + recursion(energy, dp, pos + k, k);
        return dp[pos];
    }
};
