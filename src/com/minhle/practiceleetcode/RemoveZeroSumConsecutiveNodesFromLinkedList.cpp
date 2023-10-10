#include <vector>

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            return head->val == 0 ? nullptr : head;
        }
        vector<int> prefix_sum;
        ListNode* curr = head;
        prefix_sum.push_back(0);
        while (curr != nullptr)
        {
            prefix_sum.push_back(prefix_sum.back() + curr->val);
            if (prefix_sum.back() == 0)
            {
                return removeZeroSumSublists(curr->next);
            }
            curr = curr->next;
        }
        curr = head;
        head->next = removeZeroSumSublists(curr->next);
        return head;
    }
};