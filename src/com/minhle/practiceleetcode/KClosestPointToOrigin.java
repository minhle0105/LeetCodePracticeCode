package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class P implements Comparable<P> {
    int x;
    int y;
    double distance;

    public P(int x, int y) {
        this.x = x;
        this.y = y;
        calculateDistance();
    }

    private void calculateDistance() {
        int a = (x - 0) * (x - 0);
        int b = (y - 0) * (y - 0);
        this.distance = Math.sqrt(a + b);
    }


    @Override
    public int compareTo(P o) {
        return Double.compare(this.distance, o.distance);
    }
}


public class KClosestPointToOrigin {
    public int[][] kClosest(int[][] points, int k) {
        List<P> pObjects = new ArrayList<>();
        for (int[] point : points) {
            int x = point[0];
            int y = point[1];
            P p = new P(x,y);
            pObjects.add(p);
        }
        Collections.sort(pObjects);
        int[][] topK = new int[k][2];
        for (int i = 0; i < k; i++) {
            int[] p = new int[]{pObjects.get(i).x, pObjects.get(i).y};
            topK[i] = p;
        }
        return topK;
    }


}
