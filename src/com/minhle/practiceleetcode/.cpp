class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i)
        {
            string odd_spread = spread(i, i, s);
            if (odd_spread.size() > res.size())
            {
                res = odd_spread;
            }
            string even_spread = spread(i, i + 1, s);
            if (even_spread.size() > res.size())
            {
                res = even_spread;
            }
        }
        return res;
    }

    string spread(int i, int j, const string &s)
    {
        int left = i;
        int right = j;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
