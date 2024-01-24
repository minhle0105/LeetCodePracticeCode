package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ArrangingCoins {
    public int arrangeCoins(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long sum = ((long) (mid) * (mid + 1)) / 2;
            if (sum == n) {
                return mid;
            }
            else if (sum < n) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left - 1;
    }

    @Test
    void firstTest() {
        int n = 5;
        int expected = 2;
        int actual = arrangeCoins(n);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int n = 8;
        int expected = 3;
        int actual = arrangeCoins(n);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void longTest() {
        int n = 1804289383;
        int expected = 60070;
        int actual = arrangeCoins(n);
        Assertions.assertEquals(expected, actual);
    }
}
