package com.minhle.practiceleetcode;

public class PowerOfThree {
    public boolean isPowerOfThree(int n) {
        if (n==1) {
            return true;
        }
        double n2 = n;
        while (n2 > 3) {
            n2 /= 3;
        }
        return n2==3;
    }
}
