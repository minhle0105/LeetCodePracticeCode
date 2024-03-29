class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_num = INT_MIN;
        for (int num : nums)
        {
            max_num = max(num, max_num);
        }

        vector<int> prefix_counts = {0};
        for (int num : nums)
        {
            prefix_counts.push_back(prefix_counts.back() + (num == max_num ? 1 : 0));
        }

        long long res = 0;
        for (int i = prefix_counts.size() - 1; i >= 0; --i)
        {
            if (prefix_counts[i] < k)
            {
                return res;
            }
            res += binary_search(prefix_counts, prefix_counts[i] - k, i);
        }
        return res;
    }
private:
    int binary_search(const vector<int> &prefix_counts, int target, int right)
    {
        int left = 0;
        
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (prefix_counts[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return prefix_counts[left] > target ? left : right;
    }
};
