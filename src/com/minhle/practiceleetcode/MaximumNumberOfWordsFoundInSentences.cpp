class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for (const auto &sentence : sentences)
        {
            res = max(res, count_words(sentence));
        }
        return res;
    }

    int count_words(const string &sentence)
    {
        int res = 0;

        int i = 0;
        while (i < sentence.size())
        {
            int j = i;
            while (j < sentence.size() && sentence[j] != ' ')
            {
                ++j;
            }
            ++res;
            while (j < sentence.size() && sentence[j] == ' ')
            {
                ++j;
            }
            i = j;
        }

        return res;
    }
};
