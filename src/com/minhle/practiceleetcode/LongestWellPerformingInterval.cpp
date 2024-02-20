class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> prefix_sum = {0};
        int res = 0;
        for (int i = 0; i < hours.size(); ++i) 
        {
            int hour = hours[i];
            if (hour > 8) 
            {
                prefix_sum.push_back(1 + prefix_sum.back());
            }
            else 
            {
                prefix_sum.push_back(-1 + prefix_sum.back());
            }
            if (prefix_sum.back() > 0)
            {
                res = i;
            }
        }
        for (int i = 1; i < prefix_sum.size(); ++i) 
        {
            for (int j = prefix_sum.size() - 1; j >= i; --j) 
            {
                if (prefix_sum[j] - prefix_sum[i - 1] > 0) 
                {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};
