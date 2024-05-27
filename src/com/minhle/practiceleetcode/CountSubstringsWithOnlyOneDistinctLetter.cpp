class Solution {
public:
    int countLetters(string s) {
        int i = 0;
        int res = 0;
        while (i < s.size())
        {
            int j = i;
            while (j < s.size() && s[j] == s[i])
            {
                ++j;
            }
            int n = j - i;
            res += ((n * (n + 1)) / 2);
            i = j;
        }
        return res;
    }
};
