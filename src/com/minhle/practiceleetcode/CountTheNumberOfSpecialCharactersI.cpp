class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> counter;
        for (char c : word)
        {
            ++counter[c];
        }
        int res = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            if (counter.find(ch) != counter.end() && counter.find(toupper(ch)) != counter.end())
            {
                ++res;
            }
        }
        return res;
    }
};
