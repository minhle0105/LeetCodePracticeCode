public class FindTheDistinctDifferenceArray
{
class Solution {
    public int[] distinctDifferenceArray(int[] nums) {
        int[] prefix = uniquePrefix(nums);
        int[] suffix = uniqueSuffix(nums);
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++)
        {
            res[i] = prefix[i] - suffix[i];
        }
        return res;
    }
    
    private int[] uniquePrefix(int[] nums)
    {
        Set<Integer> set = new HashSet<>();
        int[] res = new int[nums.length];
        res[0] = 1;
        set.add(nums[0]);
        for (int i = 1; i < nums.length; i++)
        {
            int num = nums[i];
            if (set.contains(num))
            {
                res[i] = set.size();
            }
            else
            {
                res[i] = set.size() + 1;
                set.add(num);
            }
        }
        return res;
    }

    private int[] uniqueSuffix(int[] nums)
    {
        Set<Integer> set = new HashSet<>();
        int[] res = new int[nums.length];
        int startIndex = nums.length - 1;
        res[startIndex] = 0;
        set.add(nums[startIndex]);
        for (int i = startIndex - 1; i >= 0; i--)
        {
            int num = nums[i];
            res[i] = set.size();
            if (!set.contains(num))
            {
                set.add(num);
            }
        }
        return res;
    }
}	
}
