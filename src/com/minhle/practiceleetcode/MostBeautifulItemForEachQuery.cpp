class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](const vector<int> &i1, const vector<int> &i2){
            return i1.front() < i2.front();
        });

        vector<int> max_beauty = {items[0][1]};
        for (int i = 1; i < items.size(); ++i)
        {
            max_beauty.push_back(max(max_beauty.back(), items[i][1]));
        }
        vector<int> res;
        res.reserve(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            int last_ind = binary_search(items, queries[i]);
            if (last_ind == -1)
            {
                res.push_back(0);
            }
            else
            {
                res.push_back(max_beauty[last_ind]);
            }
        }
        return res;
    }

    int binary_search(const vector<vector<int>> &items, int target)
    {
        int left = 0;
        int right = items.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (items[mid][0] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (items[right][0] <= target)
        {
            return right;
        }
        if (items[left][0] <= target)
        {
            return left;
        }
        return -1;
    }
};
