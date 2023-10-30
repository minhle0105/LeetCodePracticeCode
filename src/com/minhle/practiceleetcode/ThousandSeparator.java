package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ThousandSeparator {
    public String thousandSeparator(int n) {
        StringBuilder result = new StringBuilder();
        String nToString = n + "";
        int count = 0;
        for (int i = nToString.length() - 1; i >= 0; i--) {
            if (count != 0 && count % 3 == 0) {
                result.append(".");
            }
            result.append(nToString.charAt(i));
            count++;
        }
        StringBuilder finalResult = new StringBuilder();
        for (int i = result.length() - 1; i >= 0; i--) {
            finalResult.append(result.charAt(i));
        }
        return finalResult.toString();
    }

    @Test
    void test1() {
        int n = 987;
        String expected = "987";
        String actual = thousandSeparator(n);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int n = 1234;
        String expected = "1.234";
        String actual = thousandSeparator(n);
        Assertions.assertEquals(expected, actual);
    }
}
