struct RopeTreeNode {
    int len;
    string val;
    RopeTreeNode *left;
    RopeTreeNode *right;
    RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
    RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
    RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
    RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
};

class Solution {
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        string curr;
        dfs(root, curr, k);
        return curr[k - 1];
    }
private:
    void dfs(RopeTreeNode* root, string &curr, const int k)
    {
        if (curr.size() >= k)
        {
            return;
        }
        if (!root)
        {
            return;
        }
        if (!root->val.empty())
        {
            curr += root->val;
        }
        dfs(root->left, curr, k);
        dfs(root->right, curr, k);
    }
};
