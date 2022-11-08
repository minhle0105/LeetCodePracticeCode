package com.minhle.practiceleetcode;

public class NumberOfSubstringsWithOnly1s {
    public int numSub(String s) {
        int l = 0;
        long res = 0;

        while (l < s.length()) {
            while (l < s.length() && s.charAt(l) == '0') {
                l++;
            }
            if (l == s.length()) break;
            int r = l + 1;
            while (r < s.length() && s.charAt(r) == '1') {
                r++;
            }
            int n = r - l;
            for (int i = 1; i <= n; i++) {
                int value = n - i + 1;
                res += value;
            }
            l = r;
        }

        res %= (Math.pow(10,9) + 7);
        return (int) res;
    }
}
