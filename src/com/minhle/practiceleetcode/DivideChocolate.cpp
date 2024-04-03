class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = INT_MAX;
        int right = 0;
        vector<int> prefix_sum = {0};
        for (int num : sweetness)
        {
            left = min(num, left);
            right += num;
            prefix_sum.push_back(num + prefix_sum.back());
        }

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (can_cut(prefix_sum, k + 1, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return can_cut(prefix_sum, k + 1, left) ? left : right;
    }

    bool can_cut(const vector<int> &prefix_sum, int chunks, int min_sweetness)
    {
        int left = 0;
        int count = 0;

        while (left < prefix_sum.size())
        {
            ++count;
            left = binary_search(prefix_sum, left, min_sweetness) + 1;
        }
        return count <= chunks;

    }

    int binary_search(const vector<int> &prefix_sum, int left, int min_sweetness)
    {
        int right = prefix_sum.size() - 1;
        int anchor = prefix_sum[left];
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (prefix_sum[mid] - anchor <= min_sweetness)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return prefix_sum[right] - anchor <= min_sweetness ? right : left;
    }
};
