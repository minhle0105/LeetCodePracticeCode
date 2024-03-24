class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for (int i = 0; i < mat[0].size(); ++i)
        {
            bool contains_all = true;
            for (int j = 1; j < mat.size(); ++j)
            {
                if (!binary_search(mat[j], mat[0][i]))
                {
                    contains_all = false;
                    break;
                }
            }
            if (contains_all)
            {
                return mat[0][i];
            }
        }
        return -1;
    }

    bool binary_search(const vector<int> &row, int target)
    {
        int left = 0;
        int right = row.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (row[mid] == target)
            {
                return true;
            }
            if (row[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return row[left] == target || row[right] == target;
    }
};
