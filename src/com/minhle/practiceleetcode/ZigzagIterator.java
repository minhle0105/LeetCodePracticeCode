package com.minhle.practiceleetcode;
import java.util.*;

public class ZigzagIterator {
    List<Integer> v1;
    List<Integer> v2;
    boolean isV1;
    int i1;
    int i2;

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        this.v1 = v1;
        this.v2 = v2;
        isV1 = true;
        i1 = 0;
        i2 = 0;
    }

    public int next() {
        int res;
        if (isV1) {
            if (i1 < v1.size()) {
                res = v1.get(i1);
                i1++;
            }
            else {
                res = v2.get(i2);
                i2++;
            }

        }
        else {
            if (i2 < v2.size()) {
                res = v2.get(i2);
                i2++;
            }
            else {
                res = v1.get(i1);
                i1++;
            }
        }
        isV1 = !isV1;
        return res;
    }

    public boolean hasNext() {
        return i1 < v1.size() | i2 < v2.size();
    }
}
