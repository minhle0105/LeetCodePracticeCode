package com.minhle.practiceleetcode;

public class MergeSortedArrays {
      public static void solution (int[] nums1, int m, int[] nums2, int n) {
            int current = nums1.length - 1;
            m--;
            n--;
            while (current >= 0) {
                  if (m < 0) {
                        nums1[current] = nums2[n--];
                  }
                  else if (n < 0) {
                        nums1[current] = nums1[m--];
                  }
                  else {
                        if (nums1[m] > nums2[n]) {
                              nums1[current] = nums1[m--];
                        }
                        else {
                              nums1[current] = nums2[n--];
                        }
                  }
                  current--;
            }
      }
}
