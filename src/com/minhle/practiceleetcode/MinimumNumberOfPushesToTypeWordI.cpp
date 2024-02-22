class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, vector<char>> key_map;
        for (int i = 2; i < 10; ++i)
        {
            key_map[i] = vector<char>{};
        }
        int next_key = 2;
        int res = 0;

        for (char c : word)
        {
            key_map[next_key].push_back(c);
            res += key_map[next_key].size();
            next_key = next_key == 9 ? 2 : next_key + 1;
        }

        return res;

    }
};
