package com.minhle.practiceleetcode;

public class ConstructTheRectangle {
    public int[] constructRectangle(int area) {
        if (area == 1) {
            return new int[]{1,1};
        }
        int[] res = new int[2];
        int l = area;
        int w = 1;
        int diff = l - w;
        while (l > w) {
            l = l - 1;
            if (area % l != 0) {
                continue;
            }
            else {
                w = area / l;
                int newDiff = l - w;
                if (newDiff < diff) {
                    diff = newDiff;
                    res[1] = l;
                    res[0] = w;
                }
            }
        }

        return res;
    }
}
