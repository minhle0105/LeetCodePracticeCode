/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {

        unordered_set<Node*> seen;
        for (auto curr : tree)
        {
            mark_seen(curr, seen);
        }
        for (auto curr : tree)
        {
            if (seen.find(curr) == seen.end())
            {
                return curr;
            }
        }
        return nullptr;
    }

    void mark_seen(Node* curr, unordered_set<Node*> &seen)
    {
        for (auto child : curr->children)
        {
            seen.insert(child);
        }
    }
};
