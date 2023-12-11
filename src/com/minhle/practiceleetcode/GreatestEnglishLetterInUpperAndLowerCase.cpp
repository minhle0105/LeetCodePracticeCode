#include "AllNecessaryHeaders.h"

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> chars;
        vector<pair<char, char>> pairs;
        for (char c : s)
        {
            chars.insert(c);
            if (islower(c) && chars.find(toupper(c)) != chars.end())
            {
                pairs.push_back({toupper(c), c});
            }
            else if (isupper(c) && chars.find(tolower(c)) != chars.end())
            {
                pairs.push_back({c, tolower(c)});
            }
        }
        sort(pairs.begin(), pairs.end(), [](const pair<char, char> &pair1, const pair<char, char> &pair2){
            return pair1.first > pair2.first;
        });
        return pairs.empty() ? "" : string{pairs.front().first};
    }
};

