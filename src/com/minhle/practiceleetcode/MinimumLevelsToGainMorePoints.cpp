class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        vector<int> prefix_sum = {0};
        for (int score : possible)
        {
            prefix_sum.push_back(prefix_sum.back() + (score == 0 ? -1 : 1));
        }

        for (int i = 1; i < prefix_sum.size() - 1; ++i)
        {
            if (prefix_sum[i] > prefix_sum.back() - prefix_sum[i])
            {
                return i;
            }
        }
        return -1;
    }
};
