class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> all_pairs;
        for (int i = 0; i < nums.size(); ++i)
        {
            all_pairs.push_back({i, nums[i]});
        }
        sort(all_pairs.begin(), all_pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            if (p1.second == p2.second)
            {
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        });
        long long score = 0;
        unordered_set<int> marked_indexes;
        for (const auto &pair : all_pairs)
        {
            int ind = pair.first;
            int num = pair.second;
            if (marked_indexes.find(ind) != marked_indexes.end())
            {
                continue;
            }
            score += num;
            marked_indexes.insert(ind);
            if (ind - 1 >= 0)
            {
                marked_indexes.insert(ind - 1);
            }
            if (ind + 1 < all_pairs.size())
            {
                marked_indexes.insert(ind + 1);
            }
        }
        return score;
    }
};
