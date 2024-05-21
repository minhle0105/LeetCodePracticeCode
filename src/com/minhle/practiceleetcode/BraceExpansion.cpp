class Solution {
public:
    const char BLANK = '_';
    vector<string> expand(string s) {
        string pattern;
        unordered_map<int, vector<char>> options;
        for (int i = 0; i < s.size();)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                pattern += s[i];
                ++i;
            }
            else
            {
                pattern += BLANK;
                int current_position = pattern.size() - 1;
                while (i < s.size() && s[i] != '}')
                {
                    if ('a' <= s[i] && s[i] <= 'z')
                    {
                        options[current_position].push_back(s[i]);
                    }
                    ++i;
                }
                ++i;
            }
        }
        vector<string> res;
        backtracking(pattern, 0, options, res);
        sort(res.begin(), res.end());
        return res;
    }

    void backtracking(string &curr, int pos, unordered_map<int, vector<char>> &options, vector<string> &res)
    {
        if (pos == curr.size())
        {
            res.push_back(curr);
            return;
        }
        if (curr[pos] != BLANK)
        {
            backtracking(curr, pos + 1, options, res);
        }
        else
        {
            for (char c : options[pos])
            {
                curr[pos] = c;
                backtracking(curr, pos + 1, options, res);
                curr[pos] = BLANK;
            }
        }
    }
};
