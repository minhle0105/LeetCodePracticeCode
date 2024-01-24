class Solution {
    public int minimumSum(int num) {
        List<Integer> digits = new ArrayList<>();
        while (num != 0)
        {
            digits.add(num % 10);
            num /= 10;
        }
        Collections.sort(digits);
        String first_num = "" + digits.get(0);
        String second_num = "" + digits.get(1);
        int res = Math.min(sum(first_num + digits.get(2), second_num + digits.get(3)), sum(first_num + digits.get(3), second_num + digits.get(2)));
        return res;
    }

    private int sum(String a, String b)
    {
        return Integer.parseInt(a) + Integer.parseInt(b);
    }
}
