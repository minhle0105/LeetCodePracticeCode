class Solution {
public:
    string truncateSentence(string s, int k) {
        auto words = split(s, k);
        string res;
        for (const auto &word : words)
        {
            res += word;
            res += " ";
        }
        res.pop_back();
        return res;
    }

    vector<string> split(const string &sentence, int k)
    {
        vector<string> words;

        int i = 0;
        while (i < sentence.size() && words.size() < k)
        {
            int j = i;
            while (j < sentence.size() && sentence[j] != ' ')
            {
                ++j;
            }
            words.push_back(sentence.substr(i, j - i));
            while (j < sentence.size() && sentence[j] == ' ')
            {
                ++j;
            }
            i = j;
        }

        return words;
    }
};
