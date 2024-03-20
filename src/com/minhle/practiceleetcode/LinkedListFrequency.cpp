/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> counter;
        auto curr = head;
        while (curr)
        {
            ++counter[curr->val];
            curr = curr->next;
        }
        ListNode* res = new ListNode(-1);
        curr = res;
        for (const auto &pair : counter)
        {
            curr->next = new ListNode(pair.second);
            curr = curr->next;
        }
        return res->next;
    }
};
