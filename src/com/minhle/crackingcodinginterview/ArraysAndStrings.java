package com.minhle.crackingcodinginterview;

public class ArraysAndStrings {
    static boolean containsUniqueChar(String s) {
        if (s.length() == 0) {
            return true;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            for (int j = i + 1; j < s.length();j ++) {
                if (s.charAt(i) == s.charAt(j)) {
                    return false;
                }
            }
        }
        return true;
    }

    static boolean isPermutation(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        for (int i = 0; i < s1.length(); i++) {
            if (s2.indexOf(s1.charAt(i)) < 0) {
                return false;
            }
        }
        return true;
    }

    static String replaceString(String s, int sLength) {
        s = s.trim();
        for (int i = 0; i < s.length(); i++) {
            s = s.replace(" ", "%20");
        }
        return s;
    }

    public static void main(String[] args) {
        String s = "Mr John Smith    ";
        System.out.println(replaceString(s, s.length()));
    }
}
