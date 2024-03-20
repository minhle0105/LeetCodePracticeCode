class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto curr = head;
        while (curr->next)
        {
            auto curr_next = curr->next;
            auto gcd_node = new ListNode(find_gcd(curr->val, curr->next->val));
            curr->next = gcd_node;
            gcd_node->next = curr_next;
            curr = curr_next;
        }
        return head;
    }

    int find_gcd(int a, int b)
    {
        return a == 0 ? b : gcd(b % a, a);
    }
};
