package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class CountOddInRange {
    public int countOdds(int low, int high) {
        int numberOfTerms = 0;
        if (low % 2 == 0 | high % 2 == 0) {
            numberOfTerms = (((high - low)) + 1) / 2;
        }
        else {
            numberOfTerms = (((high - low)) + 1) / 2 + 1;
        }
        return numberOfTerms;
    }

    @Test
    void test1() {
        int low = 3;
        int high = 7;
        int expected = 3;
        int actual = countOdds(low, high);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int low = 8;
        int high = 10;
        int expected = 1;
        int actual = countOdds(low, high);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int low = 8;
        int high = 11;
        int expected = 2;
        int actual = countOdds(low, high);
        Assertions.assertEquals(expected, actual);
    }
}
