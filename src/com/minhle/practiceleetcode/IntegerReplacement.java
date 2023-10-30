package com.minhle.practiceleetcode;

public class IntegerReplacement {
    public int integerReplacement(int n) {
        try {
            return replace(n, 0);
        }
        catch (StackOverflowError e) {
            return integerReplacement(n / 2) + 1;
        }
    }
    private int replace(int n, int step) {
        if (n == 1) {
            return step;
        }
        if (n % 2 == 0) {
            return replace(n / 2, step + 1);
        }
        return Math.min(replace(n - 1, step + 1), replace(n + 1, step + 1));
    }
}
