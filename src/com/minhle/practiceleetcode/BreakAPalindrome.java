package com.minhle.practiceleetcode;

public class BreakAPalindrome {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() == 1) {
            return "";
        }
        char[] chars = palindrome.toCharArray();
        int countA = 0;
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] != 'a') {
                chars[i] = 'a';
                break;
            }
            else {
                countA++;
            }
        }
        if (countA == chars.length) {
            changeLastCharToB(chars);
        }
        countA = 0;
        for (char c : chars) {
            if (c == 'a') {
                countA++;
            }
        }
        if (countA == chars.length) {
            chars = palindrome.toCharArray();
            changeLastCharToB(chars);
        }
        StringBuilder res = new StringBuilder();
        for (char c : chars) {
            res.append(c);
        }
        return res.toString();
    }
    private void changeLastCharToB(char[] chars) {
        chars[chars.length - 1] = 'b';
    }
}
