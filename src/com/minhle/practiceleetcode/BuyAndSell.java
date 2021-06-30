package com.minhle.practiceleetcode;


public class BuyAndSell {
    public static int solution(int[] prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (Integer i : prices) {
            if (i < minPrice) {
                minPrice = i;
            }
            else if (maxProfit < i - minPrice) {
                maxProfit = i - minPrice;
            }
        }
        return maxProfit;
    }
}
