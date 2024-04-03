class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = nums[0];
        int right = 0;
        vector<int> prefix_sum = {0};
        for (int num : nums)
        {
            left = min(left, num);
            right += num;
            prefix_sum.push_back(num + prefix_sum.back());
        }

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (can_divide(prefix_sum, k, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return can_divide(prefix_sum, k, left) ? left : right;
    }

    bool can_divide(const vector<int> &prefix_sum, int k, int threshold)
    {
        int left = 1;
        int count = 0;

        while (left < prefix_sum.size())
        {
            int next = binary_search(prefix_sum, left, threshold);
            if (next != -1)
            {
                ++count;
                left = next + 1;
            }
            else
            {
                return false;
            }
        }

        return count <= k;
    }

    int binary_search(const vector<int> &prefix_sum, int left, int threshold)
    {
        int right = prefix_sum.size() - 1;
        int anchor = prefix_sum[left - 1];

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (prefix_sum[mid] - anchor <= threshold)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (prefix_sum[right] - anchor <= threshold)
        {
            return right;
        }
        if (prefix_sum[left] - anchor <= threshold)
        {
            return left;
        }
        return -1;
    }
};
