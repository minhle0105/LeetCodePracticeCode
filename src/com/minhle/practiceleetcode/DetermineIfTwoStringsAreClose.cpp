class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
        {
            return false;
        }

        unordered_map<char, int> counter1;
        unordered_map<char, int> counter2;

        for (char c : word1)
        {
            ++counter1[c];
        }
        for (char c : word2)
        {
            ++counter2[c];
            if (counter1.find(c) == counter1.end())
            {
                return false;
            }
        }

        vector<pair<char, int>> p1(counter1.begin(), counter1.end());
        vector<pair<char, int>> p2(counter2.begin(), counter2.end());

        sort(p1.begin(), p1.end(), [](const pair<char, int> &a, const pair<char, int> &b){
            return a.second < b.second;
        });
        
        sort(p2.begin(), p2.end(), [](const pair<char, int> &a, const pair<char, int> &b){
            return a.second < b.second;
        });

        for (int i = 0; i < p1.size(); ++i)
        {
            if (p1[i].second != p2[i].second)
            {
                return false;
            }
        }

        return true;
    }
};
