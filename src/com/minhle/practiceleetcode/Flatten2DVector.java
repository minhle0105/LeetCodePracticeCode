package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class Flatten2DVector {
    static class Vector2D {
        List<Integer> vector;
        int pointer = 0;

        public Vector2D(int[][] vec) {
            this.vector = new ArrayList<>();
            for (int[] v : vec) {
                for (int i : v) {
                    this.vector.add(i);
                }
            }
        }

        public int next() {
            int res = vector.get(pointer);
            pointer ++;
            return res;
        }

        public boolean hasNext() {
            return pointer < vector.size();
        }
    }
}
