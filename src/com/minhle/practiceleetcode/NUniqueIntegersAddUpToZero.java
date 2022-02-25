package com.minhle.practiceleetcode;

public class NUniqueIntegersAddUpToZero {
    public int[] sumZero(int n) {
        int[] results = new int[n];
        if (n % 2 == 0) {
            int i1 = 0;
            int i2 = n - 1;
            int s1 = 1;
            int s2 = -1;
            while (i1 < i2) {
                results[i1++] = s1++;
                results[i2--] = s2--;
            }
        }
        else {
            results[n / 2] = 0;
            int count = 1;
            int i1 = n / 2 + 1;
            int i2 = n / 2 - 1;
            int s1 = 1;
            int s2 = -1;
            while (count < n) {
                results[i1++] = s1 ++;
                results[i2--] = s2 --;
                count += 2;
            }
        }
        return results;
    }
}
