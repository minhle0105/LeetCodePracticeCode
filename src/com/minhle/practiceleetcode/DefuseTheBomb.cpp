class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(), 0);
        if (k == 0)
        {
            return res;
        }
        vector<int> prefix_sum = {0};
        for (int c : code)
        {
            prefix_sum.push_back(c + prefix_sum.back());
        }
        if (k > 0)
        {
            for (int i = 0; i < res.size(); ++i)
            {
                res[i] = 0;
                int count = 0;
                int j = i + 1;
                while (count < k && j < code.size())
                {
                    res[i] += code[j];
                    ++count;
                    ++j;
                }
                j = 0;
                while (count < k && j < code.size())
                {
                    res[i] += code[j];
                    ++count;
                    ++j;
                }
            }
        }
        else
        {
            k *= (-1);
            for (int i = 0; i < res.size(); ++i)
            {
                res[i] = 0;
                int count = 0;
                int j = i - 1;
                while (count < k && j >= 0)
                {
                    res[i] += code[j];
                    ++count;
                    --j;
                }
                j = code.size() - 1;
                while (count < k && j >= 0)
                {
                    res[i] += code[j];
                    ++count;
                    --j;
                }
            }
        }
        return res;
    }
};
