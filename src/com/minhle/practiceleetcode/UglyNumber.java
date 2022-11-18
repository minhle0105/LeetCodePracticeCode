package com.minhle.practiceleetcode;

public class UglyNumber {
    public boolean isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        n = divide(n, 2);
        n = divide(n, 3);
        n = divide(n, 5);
        return n == 1;
    }
    private int divide(int n, int i) {
        if (n % i != 0) {
            return n;
        }
        return divide(n / i, i);
    }
}
