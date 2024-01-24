#include <map>

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        map<int, vector<ListNode*>> val_node_map;
        map<int, int> counter;
        ListNode* curr = head;
        while (curr != nullptr)
        {
            ++counter[curr->val];
            if(val_node_map.find(curr->val) == val_node_map.end())
            {
                val_node_map[curr->val] = vector<ListNode*>{};
            }
            val_node_map[curr->val].push_back(curr);
            curr = curr->next;
        }
        ListNode *dummy = new ListNode(-1);
        curr = dummy;
        curr->next = nullptr;
        for (const auto &pair : counter)
        {
            if (pair.second == 1)
            {
                curr->next = val_node_map[pair.first].front();
                curr->next->next = nullptr;
                curr = curr->next;
            }
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};
