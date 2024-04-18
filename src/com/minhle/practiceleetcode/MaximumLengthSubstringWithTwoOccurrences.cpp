class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        unordered_map<char, int> counter;
        for (int i = 0; i < s.size(); ++i)
        {
            int j = i;
            while (j < s.size())
            {
                ++counter[s[j]];
                if (counter[s[j]] > 2)
                {
                    counter.clear();
                    break;
                }
                ++j;
            }
            res = max(res, j - i);
        }
        return res;
    }
};
