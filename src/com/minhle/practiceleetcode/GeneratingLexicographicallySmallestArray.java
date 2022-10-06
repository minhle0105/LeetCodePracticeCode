package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class GeneratingLexicographicallySmallestArray {
    private int[] generateSmallestArray(int[] array, int l, int r) {
        int[] cr = new int[array.length];
        int[] br = new int[array.length];
        br[0] = l;
        cr[0] = br[0] - array[0];
        for (int i = 1; i < array.length; i++) {
            int latestDifference = cr[i - 1];
            int startNextPosition = latestDifference + array[i] + 1;
            while (startNextPosition <= r && startNextPosition < br[i - 1]) {
                startNextPosition++;
            }
            br[i] = startNextPosition;
            cr[i] = br[i] - array[i];
        }
        return br;
    }

    @Test
    void test1() {
        int[] arr = {1,2,1,2};
        int l = 1;
        int r = 10;
        int[] expected = {1,3,3,5};
        Assertions.assertArrayEquals(expected, generateSmallestArray(arr, l, r));
    }
}
