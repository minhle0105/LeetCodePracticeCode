class Solution {
    public int minAbsoluteDifference(List<Integer> nums, int x) {
        if(x == 0) return 0;
        
        TreeSet<Integer> set = new TreeSet<>();
        int diff = Integer.MAX_VALUE;
        for(int i = x; i < nums.size(); i++) 
        {
            set.add(nums.get(i - x));
            
            Integer low = set.lower(nums.get(i));
            if (low != null) 
            {
                diff = Math.min(diff, nums.get(i) - low);
                if (diff == 0) 
                {
                    return diff;
                }
            }
            
            Integer high = set.higher(nums.get(i) - 1);
            if (high != null) 
            {
                diff = Math.min(diff, high - nums.get(i));
                if (diff == 0) 
                {
                    return diff;
                }
            }
        }
        return diff;
    }
}
