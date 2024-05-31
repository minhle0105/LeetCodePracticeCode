class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> parities;
        parities.reserve(nums.size());
        for (int num : nums)
        {
            parities.push_back(num % 2);
        }

        vector<pair<int, int>> special_chunks;
        int i = 0;
        while (i < parities.size())
        {
            int j = i + 1;
            while (j < parities.size() && parities[j] != parities[j - 1])
            {
                ++j;
            }
            special_chunks.push_back({i, j - 1});
            i = j;
        }

        vector<bool> res;
        res.reserve(queries.size());
        for (const auto &query : queries)
        {
            int start = query[0];
            int end = query[1];
            int pos = binary_search(special_chunks, start);
            res.push_back(end <= special_chunks[pos].second);
        }

        return res;
    }

    int binary_search(const vector<pair<int, int>> &special_chunks, int target)
    {
        int left = 0;
        int right = special_chunks.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (special_chunks[mid].first <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return special_chunks[right].first <= target ? right : left;
    }
};
