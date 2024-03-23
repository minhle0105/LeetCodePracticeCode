class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> values;
        dfs(root, values);

        vector<vector<int>> res;
        res.reserve(queries.size());

        for (const auto &query : queries)
        {
            res.push_back({find_largest_smaller_than(values, query), find_smallest_larger_than(values, query)});
        }
        return res;
    }
private:
    void dfs(TreeNode* root, vector<int> &values)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, values);
        values.push_back(root->val);
        dfs(root->right, values);
    }

    int find_largest_smaller_than(const vector<int> &values, int target)
    {
        int left = 0;
        int right = values.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (values[mid] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (values[right] <= target)
        {
            return values[right];
        }
        if (values[left] <= target)
        {
            return values[left];
        }
        return -1;
    }

    int find_smallest_larger_than(const vector<int> &values, int target)
    {
        int left = 0;
        int right = values.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (values[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (values[left] >= target)
        {
            return values[left];
        }
        if (values[right] >= target)
        {
            return values[right];
        }
        return -1;
    }
};
