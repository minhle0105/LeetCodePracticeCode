struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr)
        {
            return false;
        }
        if (root->val == head->val)
        {
            if (compare(head, root))
            {
                return true;
            }
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool compare(ListNode *curr, TreeNode *root)
    {
        if (curr == nullptr)
        {
            return true;
        }
        if (root == nullptr || (root != nullptr && curr->val != root->val))
        {
            return false;
        }
        return curr->val == root->val && (compare(curr->next, root->left) || compare(curr->next, root->right));
    }
};
