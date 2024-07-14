class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; ++i)
        {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a % 2 == b % 2 && a > b)
            {
                return string{s.substr(0, i) + (to_string(b) + to_string(a)) + s.substr(i + 2)};   
            }
        }
        return s;
    }
};
