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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto curr = head;
        while (curr != nullptr)
        {
            ++n;
            curr = curr->next;
        }
        vector<int> nodes_per_part = nodesEachPart(k, n);
        vector<ListNode*> res;
        split(head, 0, k, nodes_per_part, res);
        return res;
    }

private:
    void split(ListNode* head, int i, int k, const vector<int> &nodes_per_part, vector<ListNode*> &res)
    {
        if (i == nodes_per_part.size())
        {
            return;
        }
        int nodes = nodes_per_part.at(i);
        int count = 1;
        auto curr = head;
        while (count < nodes && curr != nullptr)
        {
            ++count;
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            res.push_back(head);
            split(head, i + 1, k, nodes_per_part, res);
            return;
        }
        auto temp = curr->next;
        curr->next = nullptr;
        res.push_back(head);
        split(temp, i + 1, k, nodes_per_part, res);
    }

    vector<int> nodesEachPart(int k, int n)
    {
        int mod = n % k;
        if (mod == 0)
        {
            return vector<int>(k, static_cast<int>(n / k));
        }
        int count = k * static_cast<int>(n / k);
        vector<int> res(k, count / k);
        while (count < n)
        {
            for (int i = 0; i < res.size(); ++i)
            {
                ++res.at(i);
                ++count;
                if (count == n)
                {
                    break;
                }
            }
        }
        return res;
    }
};