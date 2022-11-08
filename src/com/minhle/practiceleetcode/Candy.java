package com.minhle.practiceleetcode;

import java.util.Arrays;

public class Candy {
    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        Arrays.fill(candies, 1);
        while (true) {
            boolean findSomething = false;
            for (int i = 0; i < ratings.length - 1; i++) {
                if (ratings[i] < ratings[i + 1] && !(candies[i + 1] > candies[i])) {
                    candies[i+1] = candies[i] + 1;
                    findSomething = true;
                }
                else if (ratings[i] > ratings[i + 1] && !(candies[i] > candies[i + 1])) {
                    candies[i] = candies[i + 1] + 1;
                    findSomething = true;
                }
            }
            if (!findSomething) break;
        }

        int res = 0;
        for (int candy : candies) {
            res += candy;
        }
        return res;
    }
}
