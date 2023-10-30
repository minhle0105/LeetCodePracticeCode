package com.minhle.practiceleetcode;

public class RichestCustomerWealth {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = Integer.MIN_VALUE;
        for (int i = 0; i < accounts.length; i++) {
            int[] accountInfo = accounts[i];
            int wealth = 0;
            for (int j : accountInfo) {
                wealth += j;
            }
            if (wealth > maxWealth) {
                maxWealth = wealth;
            }
        }
        return maxWealth;
    }
}
