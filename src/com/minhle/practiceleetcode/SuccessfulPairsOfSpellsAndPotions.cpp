class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        const int n = spells.size();
        const int m = potions.size();
        res.reserve(n);

        for (int spell : spells)
        {
            long long first_ind = binary_search(potions, success, spell);
            res.push_back((first_ind == -1) ? 0 : m - first_ind);
        }
        return res;
    }

    long long binary_search(const vector<int> &potions, const long long success, const long long spell)
    {
        int left = 0;
        int right = potions.size() - 1;

        while (left < right - 1)
        {
            long long mid = left + ((right - left) / 2);
            if (spell * potions[mid] >= success)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (potions[left] * spell >= success)
        {
            return left;
        }
        if (potions[right] * spell >= success)
        {
            return right;
        }
        return -1;
    }
};
