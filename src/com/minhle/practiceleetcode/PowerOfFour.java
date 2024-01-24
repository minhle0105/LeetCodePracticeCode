package com.minhle.practiceleetcode;

public class PowerOfFour {
    public boolean isPowerOfFour(int n) {
        if (n == 1) {
            return true;
        }
        double n2 = n;
        while (n2 > 4) {
            n2 /= 4;
        }
        return n2==4;
    }
}
