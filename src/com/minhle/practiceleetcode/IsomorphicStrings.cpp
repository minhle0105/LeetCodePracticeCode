class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t, s);
    }

    bool helper(const string &s, const string &t)
    {
        unordered_map<char, char> replaced;

        for (int i = 0; i < s.size(); ++i)
        {
            if (replaced.find(s[i]) == replaced.end())
            {
                replaced[s[i]] = t[i];
            }
            else
            {
                if (t[i] != replaced[s[i]])
                {
                    return false;
                }
            }
        }
        return true;
    }

};
