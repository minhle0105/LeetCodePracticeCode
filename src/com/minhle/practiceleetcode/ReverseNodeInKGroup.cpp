#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
        {
            return nullptr;
        }
        int count = 1;
        auto *curr = head;
        while (count < k && curr != nullptr)
        {
            ++count;
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            return head;
        }
        auto the_res = curr->next;
        curr->next = nullptr;
        auto reversed_first_part = reverse(head);
        auto first_part_tail = reversed_first_part.front();
        auto first_part_head = reversed_first_part.back();
        first_part_tail->next = reverseKGroup(the_res, k);
        return first_part_head;
    }
    vector<ListNode*> reverse(ListNode *head)
    {
        stack<ListNode*> st;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->next;
        }
        auto *res = st.top();
        st.pop();
        curr = res;
        while (!st.empty())
        {
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return vector<ListNode*>{curr, res};
    }
};
