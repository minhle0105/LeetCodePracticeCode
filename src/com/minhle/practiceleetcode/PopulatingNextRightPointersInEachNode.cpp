class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
        {
            return nullptr;
        }   
        root->next = nullptr;
        if (root->left == nullptr)
        {
            return root;
        }
        connectR(root);
        return root;
    }
    void connectR(Node* root)
    {
        if (root->left == nullptr)
        {
            return;
        }
        root->left->next = root->right;
        root->right->next = root->next != nullptr ? root->next->left : root->next;
        connectR(root->left);
        connectR(root->right);
    }
};
