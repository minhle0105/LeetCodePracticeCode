package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;


public class CoinChange {
    public int coinChange(int[] coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        int[] dp = new int[amount + 1];
        coinChange(coins, amount, dp);
        return dp[amount];
    }
    private int coinChange(int[] coins, int amount, int[] dp) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != 0) {
            return dp[amount];
        }
        int minVal = Integer.MAX_VALUE;
        for (int coin : coins) {
            int val = coinChange(coins, amount - coin, dp);
            if (val >= 0 && val < minVal) {
                minVal = val + 1;
            }

        }
        dp[amount] = minVal == Integer.MAX_VALUE ? - 1 : minVal;
        return dp[amount];
    }


    @Test
    void test1() {
        int[] coins = {1, 2, 5};
        int amount = 11;
        int expected = 3;
        int actual = coinChange(coins, amount);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test2() {
        int[] coins = {2};
        int amount = 3;
        int expected = -1;
        int actual = coinChange(coins, amount);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test3() {
        int[] coins = {1};
        int amount = 0;
        int expected = 0;
        int actual = coinChange(coins, amount);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test4() {
        int[] coins = {186,419,83,408};
        int amount = 6249;
        int expected = 20;
        int actual = coinChange(coins, amount);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void test5() {
        int[] coins = {2,5,10,1};
        int amount = 27;
        int expected = 4;
        int actual = coinChange(coins, amount);
        Assertions.assertEquals(expected, actual);
    }
}
