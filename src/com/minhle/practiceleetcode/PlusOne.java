package com.minhle.practiceleetcode;

public class PlusOne {
      public int[] plusOne(int[] digits) {
            // edge case: the array contains 9 only

            for (int i = digits.length - 1; i >= 0; i--) {
                  if (digits[i] != 9) {
                        digits[i] ++;
                        return digits;
                  }
                  digits[i] = 0; // if ends with 9, for example, 889, it will become 890
                  // in the edge case, this loop will not return, the whole array will be set to 0
            }
            // edge case example, {9,9,9} -> {1,0,0,0}
            // if the loop finishes without return -> edge case hit
            int[] newDigits = new int[digits.length + 1];
            newDigits[0] = 1; // the other elements are automatically set to 0
            return newDigits;
      }
}
