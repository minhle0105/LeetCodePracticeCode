#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
    ~Node() = default;
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return node;
        }
        unordered_map<Node*, Node*> clone_map;
        auto res = clone(node, clone_map);
        return res;
    }
private:
    Node *clone(Node *node, unordered_map<Node*, Node*> &clone_map)
    {
        if (clone_map.find(node) != clone_map.end())
        {
            return clone_map[node];
        }
        Node *cloneNode = new Node(node->val, vector<Node*>{});
        clone_map[node] = cloneNode;

        for (auto neighbor : node->neighbors)
        {
            auto clone_neighbor = clone(neighbor, clone_map);
            cloneNode->neighbors.push_back(clone_neighbor);
        }
        return cloneNode;
    }
};