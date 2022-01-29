package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;

public class FloodFill {

    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int m = image.length;
        int n = image[0].length;
        int[][] distance = new int[m][n];
        int[][] visited = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] != image[sr][sc]) {
                    visited[i][j] = 1;
                }
                distance[i][j] = image[i][j];
            }
        }
        visited[sr][sc] = 1;
        distance[sr][sc] = newColor;

        bfs(new int[]{sr, sc}, distance, visited, m, n);
        return distance;
    }
    private void bfs(int[] startPoint, int[][] distance, int[][] visited, int m, int n) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startPoint[0]);
        queue.add(startPoint[1]);
        visited[startPoint[0]][startPoint[1]] = 1;
        while (!queue.isEmpty()) {
            int thisX = queue.remove();
            int thisY = queue.remove();
            for (int i = 0; i < 4; i++) {
                int nextX = thisX + dR[i];
                int nextY = thisY + dC[i];
                boolean isInBound = nextX >= 0 && nextX < m && nextY >= 0 && nextY < n;
                if (isInBound) {
                    if (visited[nextX][nextY] == 0) {
                        visited[nextX][nextY] = 1;
                        queue.add(nextX);
                        queue.add(nextY);
                        distance[nextX][nextY] = distance[startPoint[0]][startPoint[1]];
                    }
                }
            }
        }
    }
}
