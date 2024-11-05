class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        for (int i = 0; i < s.size() - 1; i += 2)
        {
            res += (s[i] != s[i + 1]);
        }
        return res;
    }
};
