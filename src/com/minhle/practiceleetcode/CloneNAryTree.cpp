#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (root == nullptr)
        {
            return root;
        }
        auto cloneNode = new Node(root->val);
        clone(root, cloneNode);
        return cloneNode;
    }

    void clone(Node* root, Node* cloneNode)
    {
        if (root == nullptr)
        {
            return;
        }
        vector<Node*> cloneChildren;
        for (auto child : root->children)
        {
            cloneChildren.push_back(new Node(child->val));
            clone(child, cloneChildren.back());
        }
        cloneNode->children = cloneChildren;
    }
};