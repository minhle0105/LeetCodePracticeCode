class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> all_substrings_in_reverse;
        for (int i = s.size() - 1; i > 0; --i)
        {
            all_substrings_in_reverse.insert(string(1, s[i]) + s[i - 1]);            
        }

        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (all_substrings_in_reverse.find(s.substr(i, 2)) != all_substrings_in_reverse.end())
            {
                return true;
            }
        }
        return false;

    }
};
