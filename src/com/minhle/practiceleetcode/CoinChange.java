package com.minhle.practiceleetcode;

import java.util.Arrays;

public class CoinChange {
    public int coinChange(int[] coins, int amount) {
        return minChange(amount, coins);
    }
    private static int minChange(int a, int[] ds) {
        if (ds.length == 0) {
            return -1;
        }
        if (a == 0) {
            return 0;
        }
        if (ds[0] > a) {
            return minChange(a, Arrays.copyOfRange(ds, 1, ds.length));
        }
        return min(specialAdd(1, minChange(a - ds[0], ds)), minChange(a, Arrays.copyOfRange(ds,1 , ds.length)));
    }

    private static int specialAdd(int a, int b) {
        if (b == -1) {
            return -1;
        }
        return a + b;
    }

    private static int min(int a, int b) {
        if (b == -1) {
            return a;
        }
        return Math.min(a, b);
    }
}
