package com.minhle.practiceleetcode;

public class ReverseBits {
    public static int reverseBits(int n) {
        String a = Integer.toBinaryString(n);
        int numberOfZeroBitsToAdd = 32 - a.length();
        StringBuilder bits = new StringBuilder();
        for (int i = 0; i < numberOfZeroBitsToAdd; i++) {
            bits.append("0");
        }
        bits.append(a);
        bits = new StringBuilder(reverse(bits.toString()));
        return (int) Long.parseLong(bits.toString(), 2);
    }

    private static String reverse(String s) {
        char[] res = s.toCharArray();
        for (int i = 0; i < res.length / 2; i++) {
            char temp = res[i];
            res[i] = res[res.length - i - 1];
            res[res.length - i - 1] = temp;
        }
        StringBuilder rev = new StringBuilder();
        for (char c : res) {
            rev.append(c);
        }
        return rev.toString();
    }
}
