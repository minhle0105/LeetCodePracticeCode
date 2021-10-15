package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ReverseWordInAStringIII {

    private String reverse(char[] s) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length / 2; i++) {
            char temp = s[i];
            s[i] = s[s.length - i - 1];
            s[s.length - i - 1] = temp;
        }
        for (char c : s) {
            result.append(c);
        }
        return result.toString();

    }

    public String reverseWords(String s) {
        StringBuilder result = new StringBuilder();
        String[] split = s.split(" ");
        for (String string : split) {
            String rev = reverse(string.toCharArray());
            result.append(rev).append(" ");
        }
        return result.toString().trim();
    }

    @Test
    void firstTest() {
        String s = "Let's take LeetCode contest";
        String expected = "s'teL ekat edoCteeL tsetnoc";
        String actual = reverseWords(s);
        Assertions.assertEquals(expected, actual);
    }
}
