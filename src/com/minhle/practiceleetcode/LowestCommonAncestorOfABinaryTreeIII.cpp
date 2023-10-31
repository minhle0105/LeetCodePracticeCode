#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> path;
        while (p != nullptr)
        {
            path.insert(p);
            p = p->parent;
        }
        while (q != nullptr)
        {
            if (path.find(q) != path.end())
            {
                return q;
            }
            q = q->parent;
        }
        return nullptr;
    }
};
