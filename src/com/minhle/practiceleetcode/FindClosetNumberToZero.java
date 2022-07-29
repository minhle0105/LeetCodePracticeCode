public class FindClosetNumberToZero {
    public int findClosestNumber(int[] nums) {
        int minAbs = Math.abs(nums[0]);
        for (int num : nums) {
            minAbs = Math.min(Math.abs(num), minAbs);
        }
        int res = Integer.MIN_VALUE;
        for (int num : nums) {
            if (Math.abs(num) == minAbs) {
                res = Math.max(num, res);
            }
        }
        return res;
    }
}
