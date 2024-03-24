class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long n = 0;
        for (char ch : s)
        {
            n += c == ch ? 1 : 0;
        }
        return n <= 1 ? n : ((n + 1) * n) / 2;
    }
};
