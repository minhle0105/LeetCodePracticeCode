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

    public static void main(String[] args) {
        int[] arrays = {7,1,5,3,6,4};
        System.out.println(solution(arrays));
    }
}
