package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class CheckIfOneStringSwapCanMakeStringEquals {
    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.equals(s2)) {
            return true;
        }
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (s2.indexOf(s1.charAt(i)) != -1) {
                    count++;
                }
                else {
                    return false;
                }
            }
        }
        return count == 2;
    }

    @Test
    void test1() {
        String s1 = "bank";
        String s2 = "kanb";
        Assertions.assertTrue(areAlmostEqual(s1, s2));
    }

    @Test
    void test2() {
        String s1 = "attack";
        String s2 = "defend";
        Assertions.assertFalse(areAlmostEqual(s1, s2));
    }

    @Test
    void test3() {
        String s1 = "kelb";
        String s2 = "kelb";
        Assertions.assertTrue(areAlmostEqual(s1, s2));
    }
}
