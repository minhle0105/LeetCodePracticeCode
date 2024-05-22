class Solution {
public:
    vector<vector<string>> res;
    unordered_set<string> palindromes;
    vector<vector<string>> partition(string s) {
        res.clear();
        palindromes.clear();
        vector<string> curr;
        backtracking(s, 0, curr);
        return res;
    }

    void backtracking(const string &s, int pos, vector<string> &curr)
    {
        if (pos == s.size())
        {
            bool all_palindrome = true;
            for (const auto &word : curr)
            {
                if (palindromes.find(word) != palindromes.end())
                {
                    continue;
                }
                if (!is_palindrome(word))
                {
                    all_palindrome = false;
                    break;
                }
                else
                {
                    palindromes.insert(word);
                }
            }
            if (all_palindrome)
            {
                res.push_back(curr);
            }
            return;
        }

        for (int i = pos; i < s.size(); ++i)
        {
            curr.push_back(s.substr(pos, i - pos + 1));
            backtracking(s, i + 1, curr);
            curr.pop_back();
        }
    }

    bool is_palindrome(const string &word)
    {
        for (int i = 0; i <= word.size() / 2; ++i)
        {
            if (word[i] != word[word.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
