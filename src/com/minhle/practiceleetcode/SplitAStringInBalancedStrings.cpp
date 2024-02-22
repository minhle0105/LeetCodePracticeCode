class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int res = 0;
        for (char c : s)
        {
            count += c == 'L' ? 1 : -1;
            res += count == 0 ? 1 : 0;
        }
        return res;
    }
};
