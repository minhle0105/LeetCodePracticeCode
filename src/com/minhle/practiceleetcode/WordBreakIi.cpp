class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        res.clear();
        words.clear();
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        backtracking(s, 0, dictionary);
        return res;
    }

private:
    vector<string> res;
    vector<string> words;
    void backtracking(string &s, int pos, const unordered_set<string> &dictionary)
    {
        if (pos == s.size())
        {
            string sentence;
            for (const auto &word : words)
            {
                sentence += word;
                sentence += " ";
            }
            sentence.pop_back();
            res.push_back(sentence);
            return;
        }
        for (int i = pos; i < s.size(); ++i)
        {
            auto word = s.substr(pos, i - pos + 1);
            if (dictionary.find(word) != dictionary.end())
            {
                words.push_back(word);
                backtracking(s, i + 1, dictionary);
                words.pop_back();
            }
        }
    }
};
