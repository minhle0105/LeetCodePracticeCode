class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &word1, const string &word2){
            return word1.size() < word2.size();
        });
        vector<int> dp(words.size(), 1);
        int res = 1;
        for (int i = 0; i < words.size() - 1; ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (can_form_word_chain(words[i], words[j]))
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                    res = max(res, dp[j]);
                }
            }
        }
        return res;
    }

    bool can_form_word_chain(const string &word1, const string &word2)
    {
        if (word1.size() != word2.size() - 1)
        {
            return false;
        }
        if (word1 == word2)
        {
            return false;
        }
        for (int i = 0; i < word2.size(); ++i)
        {
            if (word1 == (word2.substr(0, i) + word2.substr(i + 1)))
            {
                return true;
            }
        }
        return false;
    }
};
