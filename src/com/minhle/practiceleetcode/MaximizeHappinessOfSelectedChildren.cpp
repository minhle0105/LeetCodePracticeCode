class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int pos = happiness.size() - 1;
        int count = 0;
        long long res = 0;

        while (count < k)
        {
            res += max(happiness[pos] - count, 0);
            --pos;
            ++count;
        }
        return res;
    }
};
