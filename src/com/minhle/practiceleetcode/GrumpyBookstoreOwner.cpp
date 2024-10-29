class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> original = {0};
        vector<int> adjusted = {0};

        for (int i = 0; i < n; ++i)
        {
            original.push_back(customers[i] + original.back());
            if (grumpy[i] == 1)
            {
                adjusted.push_back(adjusted.back());
            }
            else
            {
                adjusted.push_back(customers[i] + adjusted.back());
            }
        }

        int res = 0;
        int i = 0;
        while (i + minutes - 1 < n)
        {
            int j = i + minutes - 1;
            int satisfy_in_this_segment = original[j + 1] - original[i];
            int satisfy_before = adjusted[i];
            int satisfy_after = adjusted.back() - adjusted[j + 1];
            res = max(res, satisfy_before + satisfy_in_this_segment + satisfy_after);
            ++i;
        }
        return res;
    }
};
