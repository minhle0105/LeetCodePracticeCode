package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class PowerOfTwo {
    public boolean isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        }
        double n2 = n;
        while (n2 > 2) {
            n2 /= 2;
        }
        return n2==2;
    }

    @Test
    void firstTest() {
        int n = 5;
        Assertions.assertFalse(isPowerOfTwo(n));
    }
}
