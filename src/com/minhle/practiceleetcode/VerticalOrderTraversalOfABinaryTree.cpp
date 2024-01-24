#include <vector>
#include <map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Sorted_Node {
public:
    int value;
    int row;

    Sorted_Node(int value, int row) : value(value), row(row) {}

    bool operator<(const Sorted_Node& other) const {
        if (this->row != other.row)
        {
            return this->row < other.row;
        }
        return this->value < other.value;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        rows_to_node.clear();
        cols_to_node.clear();
        node_to_row.clear();

        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (const auto &pair : cols_to_node)
        {
            auto nodes_at_this_col = pair.second;
            vector<Sorted_Node> sorted_nodes_this_col;
            sorted_nodes_this_col.reserve(nodes_at_this_col.size());
            for (auto node : nodes_at_this_col)
            {
                sorted_nodes_this_col.emplace_back(node->val, node_to_row[node]);
            }
            sort(sorted_nodes_this_col.begin(), sorted_nodes_this_col.end());
            vector<int> this_res;
            this_res.reserve(sorted_nodes_this_col.size());
            for (auto node : sorted_nodes_this_col)
            {
                this_res.push_back(node.value);
            }
            res.push_back(this_res);
        }
        return res;

    }

    void dfs(TreeNode *root, int col, int row)
    {
        if (root == nullptr)
        {
            return;
        }
        rows_to_node[row].push_back(root);
        node_to_row[root] = row;

        cols_to_node[col].push_back(root);
        dfs(root->left, col - 1, row + 1);
        dfs(root->right, col + 1, row + 1);
    }

private:
    map<int, vector<TreeNode*>> rows_to_node;
    map<int, vector<TreeNode*>> cols_to_node;
    map<TreeNode*, int> node_to_row;
};
