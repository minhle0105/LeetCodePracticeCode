class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const auto &word : dictionary)
        {
            abbr_map[get_abbr(word)].insert(word);
        }
    }
    
    bool isUnique(string word) {
        auto abbr = get_abbr(word);
        return (abbr_map.find(abbr) == abbr_map.end()) || 
               (abbr_map[abbr].find(word) != abbr_map[abbr].end() && abbr_map[abbr].size() == 1); 
    }
private:
    unordered_map<string, unordered_set<string>> abbr_map;

    string get_abbr(const string &word)
    {
        string abbr{word.front() + to_string(word.size() - 2) + word.back()};
        return abbr;
    }
};
