class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string curr;
        backtracking(s, 0, curr, res);
        return res;
    }

    void backtracking(const string &s, int pos, string &curr, vector<string> &res)
    {
        if (curr.size() == s.size())
        {
            res.push_back(curr);
            return;
        }
        for (int i = pos; i < s.size(); ++i)
        {
            if (isdigit(s[i]))
            {
                curr += s[i];
                backtracking(s, i + 1, curr, res);
                curr.pop_back();
            }
            else
            {
                curr += tolower(s[i]);
                backtracking(s, i + 1, curr, res);
                curr.pop_back();
                curr += toupper(s[i]);
                backtracking(s, i + 1, curr, res);
                curr.pop_back();
            }
        }
    }
};
