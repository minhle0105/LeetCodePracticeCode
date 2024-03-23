class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> all_nice_substrings;

        for (int length = 1; length <= s.size(); ++length)
        {
            for (int i = 0; i <= s.size() - length; ++i)
            {
                bool is_special = true;
                for (int j = i + 1; j < i + length; ++j)
                {
                    if (s[j] != s[j - 1])
                    {
                        is_special = false;
                        break;
                    }
                }
                if (is_special)
                {
                    ++all_nice_substrings[s.substr(i, length)];
                }
            }
        }
        
        int res = -1;
        for (const auto &pair : all_nice_substrings)
        {
            if (pair.second >= 3)
            {
                res = max(res, static_cast<int>(pair.first.size()));
            }
        }
        return res;
    }
};
