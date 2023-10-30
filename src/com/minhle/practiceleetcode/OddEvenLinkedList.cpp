class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        auto *oddHead = head;
        auto *evenHead = head->next;
        auto *odd = oddHead;
        auto *even = evenHead;
        while (odd != nullptr && even != nullptr && odd->next != nullptr && even->next != nullptr)
        {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenHead;
        return oddHead;
    }
};
