class Solution {
public:
    unordered_map<TreeNode*, bool> valid_cached;
    unordered_map<TreeNode*, int> nNodes_cached;
    int largestBSTSubtree(TreeNode* root) {
        if (!root)
        {
            return 0;
        }

        valid_cached.clear();
        nNodes_cached.clear();
        return is_valid_tree(root) ? 
                count_nodes(root) : max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
private:
    bool is_valid_tree(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }
        if (valid_cached.find(root) != valid_cached.end())
        {
            return valid_cached[root];
        }
        if ((find_max(root->left) >= root->val) || (find_min(root->right) <= root->val))
        {
            valid_cached[root] = false;
        }
        else
        {
            valid_cached[root] = is_valid_tree(root->left) && is_valid_tree(root->right);
        }
        return valid_cached[root];
    }

    int find_max(TreeNode* root)
    {
        if (!root)
        {
            return INT_MIN;
        }
        return max(root->val, max(find_max(root->left), find_max(root->right)));
    }

    int find_min(TreeNode* root)
    {
        if (!root)
        {
            return INT_MAX;
        }
        return min(root->val, min(find_min(root->left), find_min(root->right)));
    }

    int count_nodes(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        if (nNodes_cached.find(root) != nNodes_cached.end())
        {
            return nNodes_cached[root];
        }
        else
        {
            nNodes_cached[root] = 1 + count_nodes(root->left) + count_nodes(root->right);
        }
        return nNodes_cached[root];
    }
};
