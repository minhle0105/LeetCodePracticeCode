package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class CanPlaceFlowers {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int flowerPlaced = 0;
        if (flowerbed.length == 1) {
            if (flowerbed[0] == 0) {
                flowerPlaced++;
            }
            return flowerPlaced >= n;
        }
        // try to place flower in the first slot
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            placeFlowers(flowerbed, 0);
            flowerPlaced++;
        }

        int m = flowerbed.length - 1;
        int position = 1;
        while (position < m) {
            boolean canPlaceFlower = flowerbed[position - 1] == 0 && flowerbed[position] == 0 && flowerbed[position + 1] == 0;
            if (canPlaceFlower) {
                placeFlowers(flowerbed, position);
                flowerPlaced++;
            }
            position++;
        }

        // try to place flower in the last slot
        if (flowerbed[m] == 0 && flowerbed[m - 1] == 0) {
            placeFlowers(flowerbed, m);
            flowerPlaced++;
        }
        return flowerPlaced >= n;
    }

    private void placeFlowers(int[] flowers, int position) {
        flowers[position] = 1;
    }

    @Test
    void failedTest() {
        int[] flowerbed = {1,0,0,0,1,0,0};
        int n = 2;
        Assertions.assertTrue(canPlaceFlowers(flowerbed, n));
    }
}
