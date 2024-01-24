package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class WallsAndGate {

    static final int[] dR = {-1, 1, 0, 0};
    static final int[] dC = {0, 0, -1, 1};

    public void wallsAndGates(int[][] rooms) {
        int[][] distances = new int[rooms.length][rooms[0].length];
        for (int i = 0; i < distances.length; i++) {
            for (int j = 0; j < distances[i].length; j++) {
                if (rooms[i][j] == 0) {
                    distances[i][j] = 0;
                }
                else {
                    distances[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        List<List<Integer>> startPoints = new ArrayList<>();
        for (int i = 0; i < rooms.length; i++) {
            for (int j = 0; j < rooms[i].length; j++) {
                if (rooms[i][j] == 0) {
                    List<Integer> startPoint = new ArrayList<>();
                    startPoint.add(i);
                    startPoint.add(j);
                    startPoints.add(startPoint);
                }
            }
        }
        int[][] visited = new int[rooms.length][rooms[0].length];
        bfs(rooms, startPoints, distances, visited);
        for (int i = 0; i < distances.length; i++) {
            for (int j = 0; j < distances[i].length; j++) {
                if (rooms[i][j] == 2147483647) {
                    rooms[i][j] = distances[i][j];
                }
            }
        }

    }

    private static void bfs(int[][] graph, List<List<Integer>> startPoints, int[][] distance, int[][] visited) {
        Queue<Integer> queue = new LinkedList<>();
        for (List<Integer> startPoint : startPoints) {
            queue.add(startPoint.get(0));
            queue.add(startPoint.get(1));
        }
        while (!queue.isEmpty()) {
            int thisX = queue.remove();
            int thisY = queue.remove();
            for (int i = 0; i < 4; i++) {
                int nextX = thisX + dR[i];
                int nextY = thisY + dC[i];
                boolean inBound = nextX >= 0 && nextX < graph.length && nextY >= 0 && nextY < graph[0].length;
                if (inBound) {
                    if (graph[nextX][nextY] == -1) {
                        visited[nextX][nextY] = 1;
                        continue;
                    }
                    if (visited[nextX][nextY] == 0) {
                        queue.add(nextX);
                        queue.add(nextY);
                        if (distance[nextX][nextY] > distance[thisX][thisY] + 1) {
                            distance[nextX][nextY] = distance[thisX][thisY] + 1;
                        }
                        visited[nextX][nextY] = 1;
                    }
                }
            }
        }
    }


    @Test
    void firstTest() {
        int[][] rooms = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},
                {2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
        int[][] expected = {{3,-1,0,1},{2,2,1,-1},{1,-1,2,-1},{0,-1,3,4}};
        wallsAndGates(rooms);
        Assertions.assertArrayEquals(rooms, expected);
    }
}
