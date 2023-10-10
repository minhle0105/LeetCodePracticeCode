#include <vector>
#include <map>

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
        int accumulated_sum = 0;
        auto curr = head;
        map<int, ListNode*> sum;
        while (curr != nullptr)
        {
            accumulated_sum += curr->val;
            if (sum.find(accumulated_sum) != sum.end())
            {
                int del_sum = accumulated_sum;
                auto del_node = sum[accumulated_sum]->next;
                while (del_node != curr)
                {
                    del_sum += del_node->val;
                    sum.erase(del_sum);
                    del_node = del_node->next;
                }
                sum[accumulated_sum]->next = curr->next;
                curr = curr->next;
            }
            else if (accumulated_sum == 0)
            {
                sum.clear();
                head = curr->next;
                curr = curr->next;
            }
            else
            {
                sum[accumulated_sum] = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};