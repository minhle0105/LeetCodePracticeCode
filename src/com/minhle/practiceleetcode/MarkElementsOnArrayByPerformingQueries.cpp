class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, int>> pairs;
        pairs.reserve(nums.size());
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            pairs.push_back({nums[i], i});
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            return p1.first < p2.first;
        });
        set<pair<int, int>> marked;
        vector<long long> res;
        int pointer = 0;
        res.reserve(queries.size());
        for (const auto &query : queries)
        {
            int index = query.front();
            int k = query.back();
            int removed_sum = 0;
            if (marked.find({nums[index], index}) == marked.end())
            {
                removed_sum += nums[index];
                marked.insert({nums[index], index});
            }
            int count = 0;
            while (count < k && pointer < pairs.size())
            {
                if (marked.find(pairs[pointer]) == marked.end())
                {
                    ++count;
                    marked.insert({pairs[pointer].first, pairs[pointer].second});
                    removed_sum += pairs[pointer].first;
                }
                ++pointer;
            }
            sum -= removed_sum;
            res.push_back(sum);
        }
        return res;
    }
};
