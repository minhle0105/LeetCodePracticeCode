package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;
import java.util.Queue;

public class Matrix01 {

    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] distances = new int[m][n];
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    queue.add(i);
                    queue.add(j);
                    distances[i][j] = 0;
                }
                else {
                    distances[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        bfs(queue, distances, m, n);
        return distances;

    }

    private void bfs(Queue<Integer> queue, int[][] distance, int m, int n) {
        while (!queue.isEmpty()) {
            int thisX = queue.remove();
            int thisY = queue.remove();
            for (int direction = 0; direction < 4; direction++) {
                int nextX = thisX + dR[direction];
                int nextY = thisY + dC[direction];
                boolean isInBound = nextX >= 0 && nextX < m && nextY >= 0 && nextY < n;
                if (isInBound) {
                    if (distance[thisX][thisY] + 1 < distance[nextX][nextY]) {
                        queue.add(nextX);
                        queue.add(nextY);
                        distance[nextX][nextY] = distance[thisX][thisY] + 1;
                    }
                }
            }
        }
    }

    @Test
    void test1() {
        int[][] mat = {{0,0,0},{0,1,0},{1,1,1}};
        int[][] expected = {{0,0,0},{0,1,0},{1,2,1}};
        int[][] actual = updateMatrix(mat);
        Assertions.assertArrayEquals(expected, actual);
    }
}
