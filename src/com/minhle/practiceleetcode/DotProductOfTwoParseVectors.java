package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class DotProductOfTwoParseVectors {
    Map<Integer, Integer> map;

    DotProductOfTwoParseVectors(int[] nums) {
        this.map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                this.map.put(i, nums[i]);
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    public int dotProduct(DotProductOfTwoParseVectors vec) {
        int dotProduct = 0;
        for (Integer index : vec.map.keySet()) {
            if (this.map.containsKey(index)) {
                dotProduct += this.map.get(index) * vec.map.get(index);
            }
        }
        return dotProduct;
    }
}
