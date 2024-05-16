class Solution {
public:
    int findPermutationDifference(string s, string t) {
        auto t_pos = count(t);

        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            res += abs(i - t_pos[s[i]]);
        }
        return res;
    }

    unordered_map<char, int> count(const string &word)
    {
        unordered_map<char, int> pos;
        for (int i = 0; i < word.size(); ++i)
        {
            pos[word[i]] = i;
        }
        return pos;
    }
};
