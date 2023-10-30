class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int pivot = find_pivot(mountainArr, length);
        int search_first_half = binary_search(target, 0, pivot, mountainArr);
        if (search_first_half != -1)
        {
            return search_first_half;
        }
        int search_second_half = binary_search(target, pivot + 1, length - 1, pivot + 1, mountainArr);
        return search_second_half;
    }
    int find_pivot(MountainArray &mountainArr, int length)
    {
        int left = 0;
        int right = length - 1;
        while (left < right - 1)
        {
            int mid = left + (right - left) / 2;
            if (mid == 0)
            {
                if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                {
                    return mid;
                }
            }
            if (mountainArr.get(mid - 1) < mountainArr.get(mid))
            {
                left = mid;
            }
            if (mountainArr.get(mid - 1) > mountainArr.get(mid))
            {
                right = mid - 1;
            }
        }
        return mountainArr.get(left) > mountainArr.get(right) ? left : right; 
    }
    int binary_search(int target, int left, int right, MountainArray &mountainArr)
    {
        while (left < right - 1)
        {
            int mid = left + (right - left) / 2;
            int num_at_mid = mountainArr.get(mid);
            if (num_at_mid == target)
            {
                if (mid == 0)
                {
                    return mid;
                }
                if (mid > 0)
                {
                    if (mountainArr.get(mid - 1) != num_at_mid)
                    {
                        return mid;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
            else if (num_at_mid < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (mountainArr.get(left) == target)
        {
            return left;
        }
        if (mountainArr.get(right) == target)
        {
            return right;
        }
        return -1;
    }

    int binary_search(int target, int left, int right, int pivot, MountainArray &mountainArr)
    {
        while (left < right - 1)
        {
            int mid = left + (right - left) / 2;
            int num_at_mid = mountainArr.get(mid);
            if (num_at_mid == target)
            {
                if (mid == pivot)
                {
                    return mid;
                }
                if (mid > pivot)
                {
                    if (mountainArr.get(mid - 1) != num_at_mid)
                    {
                        return mid;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
            else if (num_at_mid < target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        if (mountainArr.get(left) == target)
        {
            return left;
        }
        if (mountainArr.get(right) == target)
        {
            return right;
        }
        return -1;
    }
};
