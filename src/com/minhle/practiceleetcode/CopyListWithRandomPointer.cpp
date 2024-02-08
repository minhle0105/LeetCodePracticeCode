#include "AllNecessaryHeaders.h"

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;
        return clone(head, copies);
    }

    Node* clone(Node* original, unordered_map<Node*, Node*> &copies)
    {
        if (original == nullptr)
        {
            return original;
        }
        auto val = original->val;
        if (copies.find(original) != copies.end())
        {
            return copies[original];
        }
        Node* copy_head = new Node(original->val);
        copies[original] = copy_head;
        copy_head->next = clone(original->next, copies);
        copy_head->random = clone(original->random, copies);
        return copies[original];
    }
};
