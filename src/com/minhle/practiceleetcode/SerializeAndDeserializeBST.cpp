#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    int next;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs(root, res);
        res.pop_back();
        return res;
    }

    void dfs(TreeNode* root, string &curr)
    {
        if (root == nullptr)
        {
            curr += "N,";
            return;
        }
        curr += to_string(root->val) + ",";
        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        next = 0;
        vector<int> values = split(data);
        return build_tree(values, 0, INT_MAX);
    }

    TreeNode* build_tree(const vector<int> values, int low, int high)
    {
        int value = values[next];
        if (value < low || value > high)
        {
            return nullptr;
        }
        auto root = new TreeNode(value);
        ++next;
        root->left = build_tree(values, low, value - 1);
        ++next;
        root->right = build_tree(values, value + 1, high);
        return root;


    }

    vector<int> split(const string &data)
    {
        vector<int> res;
        string curr;
        for (char c : data)
        {
            if (c == ',')
            {
                if (curr == "N")
                {
                    res.push_back(-1);
                }
                else
                {
                    res.push_back(stoi(curr));
                }
                curr.clear();
            }
            else
            {
                curr += c;
            }
        }

        if (!curr.empty())
        {
            if (curr == "N")
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(stoi(curr));
            }
        }
        return res;
    }
};
