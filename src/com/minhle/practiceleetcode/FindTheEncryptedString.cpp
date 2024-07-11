class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res;
        res.reserve(s.size());

        int i = 0;

        while (res.size() < s.size())
        {
            int desired_position = i + k;
            if (desired_position >= s.size())
            {
                desired_position %= s.size();
            }
            res += s[desired_position];
            ++i;
        }
        return res;
    }
};
