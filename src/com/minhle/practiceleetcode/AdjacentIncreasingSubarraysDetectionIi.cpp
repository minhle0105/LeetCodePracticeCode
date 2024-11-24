class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> endings(n + 1, 1);
        vector<int> startings(n + 1, 1);

        for (int i = 1; i < n; i++) 
        {
            if (nums[i] > nums[i - 1]) 
            {
                endings[i] = endings[i - 1] + 1;
            } 
            else 
            {
                endings[i] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) 
        {
            if (nums[i] < nums[i + 1]) 
            {
                startings[i] = startings[i + 1] + 1;
            } 
            else 
            {
                startings[i] = 1;
            }
        }

        int left = 1; 
        int right = nums.size();
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (check(nums, endings, startings, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return check(nums, endings, startings, right) ? right : left;
    }
    bool check(const vector<int>& nums, const vector<int>& endings, const vector<int>& startings, int k) {
        int n = nums.size();
        for (int i = 0; i < n - k; i++) 
        {
            if (endings[i + k - 1] >= k && startings[i + k] >= k) 
            {
                return true;
            }
        }

        return false;
    }
};
