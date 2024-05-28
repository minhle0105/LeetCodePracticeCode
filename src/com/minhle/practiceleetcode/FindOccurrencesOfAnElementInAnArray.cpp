class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> positions;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == x)
            {
                positions.push_back(i);
            }
        }

        vector<int> res;
        res.reserve(queries.size());
        for (int query : queries)
        {
            if (query > positions.size())
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(positions[query - 1]);
            }
        }
        return res;
    }
};
