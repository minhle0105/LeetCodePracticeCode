package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashSet;
import java.util.Set;

public class HappyNumber {
    Set<Integer> hasSeen;
    public boolean isHappy(int n) {
        hasSeen = new HashSet<>();
        return isHappyR(n);
    }
    private boolean isHappyR(int n) {
        if (n == 1) {
            return true;
        }
        int sum = 0;
        while (n != 0) {
            sum += Math.pow((n % 10), 2);
            n /= 10;
        }
        if (hasSeen.contains(sum)) {
            return false;
        }
        hasSeen.add(sum);
        return isHappyR(sum);
    }

    @Test
    void firstTest() {
        boolean expected = true;
        boolean actual = isHappy(19);
        Assertions.assertTrue(actual);
    }

    @Test
    void secondTest() {
        boolean actual = isHappy(2);
        Assertions.assertFalse(actual);
    }

    @Test
    void lastTest() {
        boolean actual = isHappy(29);
        Assertions.assertFalse(actual);
    }
}
