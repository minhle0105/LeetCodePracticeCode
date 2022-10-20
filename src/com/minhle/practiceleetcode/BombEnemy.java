package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class BombEnemy {
    public int maxKilledEnemies(char[][] grid) {
        List<int[]> emptyBlocks = new ArrayList<>();
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[r].length; c++) {
                if (grid[r][c] == '0') {
                    emptyBlocks.add(new int[]{r, c});
                }
            }
        }
        int res = 0;
        for (int[] block : emptyBlocks) {
            res = Math.max(res, destroy(grid, block));
        }
        return res;
    }

    private int destroy(char[][] grid, int[] bomb) {
        int res = 0;
        int r = bomb[0];
        int c = bomb[1];
        int currR = r + 1;
        while (currR < grid.length) {
            if (grid[currR][c] == 'W') {
                break;
            }
            else if (grid[currR][c] == 'E') {
                res++;
            }
            currR++;
        }
        currR = r - 1;
        while (currR >= 0) {
            if (grid[currR][c] == 'W') {
                break;
            }
            else if (grid[currR][c] == 'E') {
                res++;
            }
            currR--;
        }
        int currC = c + 1;
        while (currC < grid[0].length) {
            if (grid[r][currC] == 'W') {
                break;
            }
            else if (grid[r][currC] == 'E') {
                res++;
            }
            currC++;
        }
        currC = c - 1;
        while (currC >= 0) {
            if (grid[r][currC] == 'W') {
                break;
            }
            else if (grid[r][currC] == 'E') {
                res++;
            }
            currC--;
        }
        return res;
    }
}
