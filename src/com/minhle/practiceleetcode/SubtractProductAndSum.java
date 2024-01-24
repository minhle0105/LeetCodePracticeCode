package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class SubtractProductAndSum {
    public int subtractProductAndSum(int n) {
        int sum = getCumulativeSum(n, 0);
        int product = getCumulativeProduct(n, 1);
        return product - sum;
    }

    private int getCumulativeSum(int n, int culSum) {
        if (n == 0) {
            return culSum;
        }
        return getCumulativeSum(n / 10, culSum + n % 10);
    }

    private int getCumulativeProduct(int n, int culProd) {
        if (n == 0) {
            return culProd;
        }
        return getCumulativeProduct(n / 10, culProd * (n % 10));
    }

    @Test
    void test1() {
        int n = 234;
        int expected = 15;
        int actual = subtractProductAndSum(n);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int n = 4421;
        int expected = 21;
        int actual = subtractProductAndSum(n);
        Assertions.assertEquals(expected, actual);
    }
}
