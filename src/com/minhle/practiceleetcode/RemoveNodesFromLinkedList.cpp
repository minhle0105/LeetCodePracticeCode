#include <stack>

using namespace std;

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> mono_stack;
        auto *curr = head;
        while (curr != nullptr)
        {
            while (!mono_stack.empty() && curr->val > mono_stack.top()->val)
            {
                mono_stack.pop();
            }
            mono_stack.push(curr);
            curr = curr->next;
        }
        stack<ListNode*> helper_st;
        while (!mono_stack.empty())
        {
            helper_st.push(mono_stack.top());
            mono_stack.pop();
        }
        ListNode *res = helper_st.top();
        helper_st.pop();
        curr = res;
        while (!helper_st.empty())
        {
            curr->next = helper_st.top();
            helper_st.pop();
            curr = curr->next;
        }
        return res;
    }
};
