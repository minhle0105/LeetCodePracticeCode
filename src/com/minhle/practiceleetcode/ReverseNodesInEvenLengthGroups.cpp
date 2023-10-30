#include <stack>
#include <utility>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        auto temp = head->next;
        head->next = reverse(temp, 2);
        return head;
    }
    ListNode* reverse(ListNode* head, int group)
    {
        if (head == nullptr)
        {
            return head;
        }
        return group % 2 == 0 ? handle_even_group(head, group) : handle_odd_group(head, group);
    }

    ListNode* handle_even_group(ListNode* head, int group)
    {
        auto tail = head;
        stack<ListNode*> st;
        st.push(tail);
        while (tail != nullptr && st.size() < group)
        {
            tail = tail->next;
            if (tail != nullptr)
            {
                st.push(tail);
            }
        }
        // last group
        if (tail == nullptr)
        {
            // if group has odd number of elements -> don't reverse
            if (st.size() % 2 != 0)
            {
                return head;
            }
            // if group has even number of elements -> reverse
            return reverse(st).first;
        }
        // if not last group
        // split the rest first
        auto *the_rest = tail->next;
        // reverse the current section
        auto new_head_tail = reverse(st);
        auto new_head = new_head_tail.first;
        auto new_tail = new_head_tail.second;
        // current_section next = reverse the rest
        new_tail->next = reverse(the_rest, group + 1);
        return new_head;
    }

    ListNode* handle_odd_group(ListNode* head, int group)
    {
        auto tail = head;
        stack<ListNode*> st;
        st.push(tail);
        while (tail != nullptr && st.size() < group)
        {
            tail = tail->next;
            if (tail != nullptr)
            {
                st.push(tail);
            }
        }
        // if last group
        if (tail == nullptr)
        {
            // if group has odd number of elements --> no reverse
            if (st.size() % 2 != 0)
            {
                return head;
            }
            // if group has even number of elements -> reverse
            auto new_head = reverse(st);
            return new_head.first;
        }
        auto *the_rest = tail->next;
        tail->next = reverse(the_rest, group + 1);
        return head;
    }

    pair<ListNode*, ListNode*> reverse(stack<ListNode*> st)
    {
        auto new_head = st.top();
        auto curr = new_head;
        st.pop();
        while (!st.empty())
        {
            st.top()->next = nullptr;
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }
        return {new_head, curr};
    }
};