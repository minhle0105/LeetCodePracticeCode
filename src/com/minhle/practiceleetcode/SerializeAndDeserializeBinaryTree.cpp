#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = dfs(root);
        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        next = 0;
        vector<string> values = split(data);
        return build_tree(values);
    }

private:
    int next;
    string dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "N,";
        }
        string res{to_string(root->val) + ","};
        res += dfs(root->left);
        res += dfs(root->right);
        return res;
    }

    TreeNode* build_tree(const vector<string> &values)
    {
        if (values[next] == "N")
        {
            return nullptr;
        }
        auto node = new TreeNode(stoi(values[next]));
        ++next;
        node->left = build_tree(values);
        ++next;
        node->right = build_tree(values);
        return node;
    }

    vector<string> split(const string &input)
    {
        string data;
        vector<string> res;
        for (int i = 0; i < input.size(); ++i)
        {
            if (input[i] == ',')
            {
                res.push_back(data);
                data = "";
            }
            else
            {
                data += input[i];
            }
        }
        if (!data.empty())
        {
            res.push_back(data);
        }
        return res;
    }
};
