class Solution {
    public String digitSum(String s, int k) {
        if (s.length() <= k)
        {
            return s;
        }
        StringBuilder res = new StringBuilder();
        int i = 0;
        while (i < s.length())
        {
            res.append(calculate(s.substring(i, Math.min(i + k, s.length()))));
            i += k;
        }
        return digitSum(res.toString(), k);
    }

    private long calculate(String num)
    {
        long sum = 0;
        for (char c : num.toCharArray())
        {
            sum += Integer.parseInt(String.valueOf(c));
        }
        return sum;
    }
}

