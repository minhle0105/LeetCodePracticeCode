class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, vector<int>> counter;
        for (int i = 0; i < word.size(); ++i)
        {
            counter[word[i]].push_back(i);
        }

        int res = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            char upper_ch = toupper(ch);
            if (counter.find(ch) != counter.end() && counter.find(upper_ch) != counter.end())
            {
                if (counter[ch].back() < counter[upper_ch].front())
                {
                    ++res;
                }
            }
        }
        return res;
    }
};
