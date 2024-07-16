class Solution {
public:
    int countValidWords(string sentence) {
        auto words = split(sentence);
        int res = 0;
        for (const auto &word : words)
        {
            if (verify_word(word))
            {
                ++res;
                cout << word << endl;
            }
            
        }
        return res;
    }
    
    vector<string> split(const string &sentence)
    {
        vector<string> res;
        int i = 0;
        while (i < sentence.size() && sentence[i] == ' ')
        {
            ++i;
        }
        while (i < sentence.size())
        {
            int j = i;
            while (j < sentence.size() && sentence[j] != ' ')
            {
                ++j;
            }
            res.push_back(sentence.substr(i, j - i));
            while (j < sentence.size() && sentence[j] == ' ')
            {
                ++j;
            }
            i = j;
        }
        return res;
    }

    bool verify_word(const string &word)
    {
        if (word == "q-,")
        {
            int a = 0;
        }
        int count_hyphen = 0;
        int count_punctuation = 0;
        for (int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if (isdigit(c) || count_hyphen > 1 || count_punctuation > 1)
            {
                return false;
            }
            if (c == '-')
            {
                if ((i > 0) && 
                    (i < word.size() - 1) && 
                    ('a' <= word[i - 1] && word[i - 1] <= 'z') && 
                    ('a' <= word[i + 1] && word[i + 1] <= 'z'))
                {
                    ++count_hyphen;
                }
                else
                {
                    return false;
                }
            }
            if (c == '!' || c == '.' || c == ',')
            {
                if (i == word.size() - 1)
                {
                    ++count_punctuation;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
