class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        auto counter1 = count(word1);
        auto counter2 = count(word2);

        for (char c : word1)
        {
            if (abs(counter1[c] - counter2[c]) > 3)
            {
                return false;
            }
        }
        for (char c : word2)
        {
            if (abs(counter1[c] - counter2[c]) > 3)
            {
                return false;
            }
        }
        return true;
    }

    unordered_map<char, int> count(const string &word)
    {
        unordered_map<char, int> counter;
        for (char c : word)
        {
            ++counter[c];
        }
        return counter;
    }
};
