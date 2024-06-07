class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<char, vector<string>> groups;

        for (const auto &word : dictionary)
        {
            groups[word[0]].push_back(word);
        }   
        string res;
        vector<string> words = split(sentence);
        for (const auto &word : words)
        {
            string replaced;
            int min_length = INT_MAX;
            for (const auto &st : groups[word[0]])
            {
                if (is_prefix(st, word))
                {
                    if (st.size() < min_length)
                    {
                        replaced = st;
                        min_length = st.size();
                    }
                }
            }
            res += replaced.empty() ? word : replaced;
            res += " ";
        }
        res.pop_back();
        return res;
    }
private:
    vector<string> split(const string &sentence)
    {
        vector<string> res;

        int i = 0;
        while (i < sentence.size())
        {
            int j = i;
            while (j < sentence.size() && sentence[j] != ' ')
            {
                ++j;
            }
            res.push_back(sentence.substr(i, j - i));
            i = j + 1;
        }
        return res;
    }

    bool is_prefix(const string &s, const string &t)
    {
        if (s.size() > t.size())
        {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] != t[j])
            {
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
};
