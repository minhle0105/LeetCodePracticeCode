class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *res = new ListNode(-1);
        ListNode *currRes = res;
        ListNode *curr = head->next;
        int current_sum = 0;
        while (curr != nullptr)
        {
            if (curr->val != 0)
            {
                current_sum += curr->val;
            }
            else
            {
                currRes->next = new ListNode(current_sum);
                currRes = currRes->next;
                current_sum = 0;
            }
            curr = curr->next;
        }
        return res->next;
    }
};
