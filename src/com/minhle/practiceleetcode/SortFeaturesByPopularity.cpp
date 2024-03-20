class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> feature_map;
        unordered_map<string, int> counter;

        for (int i = 0; i < features.size(); ++i)
        {
            feature_map[features[i]] = i;
            counter[features[i]] = 0;
        }
        vector<string> words;
        unordered_set<string> seen;
        for (const auto &response : responses)
        {
            words = split(response);
            for (const auto &word : words)
            {
                if (feature_map.find(word) != feature_map.end() && seen.find(word) == seen.end())
                {
                    ++counter[word];
                    seen.insert(word);
                }
            }
            words.clear();
            seen.clear();
        }

        vector<pair<string, int>> pairs(counter.begin(), counter.end());
        sort(pairs.begin(), pairs.end(), [&feature_map](const pair<string, int> &p1, const pair<string, int> &p2){
            return p1.second == p2.second ? feature_map[p1.first] < feature_map[p2.first] : p1.second > p2.second;
        });

        vector<string> res;
        for (const auto &pair : pairs)
        {
            res.push_back(pair.first);
        }
        return res;
    }

    vector<string> split(const string &response)
    {
        vector<string> res;
        string word;

        for (int i = 0; i < response.size();)
        {
            int j = i;
            while (j < response.size() && response[j] != ' ')
            {
                word += response[j];
                ++j;
            }
            res.push_back(word);
            i = j + 1;
            word.clear();
        }
        return res;
    }
};
