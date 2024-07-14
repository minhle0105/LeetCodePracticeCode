class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> all_nums(nums.begin(), nums.end());
        vector<int> all_values;
        auto curr = head;
        while (curr)
        {
            if (all_nums.find(curr->val) == all_nums.end())
            {
                all_values.push_back(curr->val);
            }
            curr = curr->next;
        }
        
        auto res = new ListNode(-1);
        curr = res;
        for (int value : all_values)
        {
            curr->next = new ListNode(value);
            curr = curr->next;
        }
        return res->next;
    }
};
