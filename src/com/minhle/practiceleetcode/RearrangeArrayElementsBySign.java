package com.minhle.practiceleetcode;

public class RearrangeArrayElementsBySign {
    public int[] rearrangeArray(int[] nums) {
        int index = 0;
        int posPointer = 0;
        int negPointer = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                posPointer = i;
                break;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0) {
                negPointer = i;
                break;
            }
        }
        int[] res = new int[nums.length];
        while (true) {
            try {
                res[index++] = nums[posPointer];
                res[index++] = nums[negPointer];
                posPointer++;
                negPointer++;
                while (nums[posPointer] < 0) {
                    posPointer++;
                }
                while(nums[negPointer] > 0) {
                    negPointer++;
                }
            }
            catch (Exception e) {
                break;
            }

        }
        return res;
    }
}
