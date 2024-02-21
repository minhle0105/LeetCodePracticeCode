class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int res = 1;
        for (int coin : coins)
        {
            if (coin > res)
            {
                // sequence is broken
                continue;
            }
            res += coin;
        }
        return res;
    }
};
