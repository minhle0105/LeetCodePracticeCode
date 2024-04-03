class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string res{""};
        string prefix{""};
        int pos = 0;
        if (str1.size() < str2.size())
        {
            while (pos < str1.size())
            {
                prefix += str1[pos];
                if (divide(str1, prefix) && divide(str2, prefix))
                {
                    if (prefix.size() > res.size())
                    {
                        res = prefix;
                    }
                }
                ++pos;
            }
        }
        else
        {
            while (pos < str2.size())
            {
                prefix += str2[pos];
                if (divide(str1, prefix) && divide(str2, prefix))
                {
                    if (prefix.size() > res.size())
                    {
                        res = prefix;
                    }
                }
                ++pos;
            }
        }
        return res;
    }

    bool divide(const string &s, const string &t)
    {
        auto curr = t;
        while (curr.size() < s.size())
        {
            curr += t;
        }
        return curr == s;
    }
};
