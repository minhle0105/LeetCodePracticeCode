class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes_by_values;
        unordered_set<TreeNode*> has_parents;
        for (const auto &description : descriptions)
        {
            int parent = description[0];
            int child = description[1];
            int direction = description[2];

            auto parent_node = nodes_by_values.find(parent) != nodes_by_values.end() ? nodes_by_values[parent] : new TreeNode(parent); 
            auto child_node = nodes_by_values.find(child) != nodes_by_values.end() ? nodes_by_values[child] : new TreeNode(child);

            if (direction == 1)
            {
                parent_node->left = child_node;
            }
            else
            {
                parent_node->right = child_node;
            }
            has_parents.insert(child_node);
            nodes_by_values[parent] = parent_node;
            nodes_by_values[child] = child_node;
        }

        for (const auto &pair : nodes_by_values)
        {
            if (has_parents.find(pair.second) == has_parents.end())
            {
                return pair.second;
            }
        }
        return nullptr;
    }
};
