class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1)
        {
            return to_string(n);
        }
        const int block_size = factorial(n - 1);
        int block_id_has_k = ceil(static_cast<double>(k) / block_size);
        unordered_set<int> digits;
        vector<string> perms;
        for (int i = 1; i <= n; ++i)
        {
            if (i == block_id_has_k)
            {
                continue;
            }
            digits.insert(i);
        }
        string curr = to_string(block_id_has_k);
        int count_so_far = block_size * (block_id_has_k - 1);
        k -= count_so_far;
        generate_all_perms_in_block(n, block_id_has_k, digits, curr, perms, k);
        return perms.back();
    }
    
    void generate_all_perms_in_block(const int n, const int block, unordered_set<int> &digits, string &curr, vector<string> &perms, const int k)
    {
        if (perms.size() == k)
        {
            return;
        }
        if (digits.empty())
        {
            perms.push_back(curr);
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i != block && digits.find(i) != digits.end())
            {
                curr += to_string(i);
                digits.erase(i);
                generate_all_perms_in_block(n, block, digits, curr, perms, k);
                digits.insert(i);
                curr.pop_back();
            }
        }
    }

    int factorial(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        return n * factorial(n - 1);
    }
};
