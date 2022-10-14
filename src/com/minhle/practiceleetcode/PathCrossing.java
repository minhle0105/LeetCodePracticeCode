package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class PathCrossing {
    public boolean isPathCrossing(String path) {
        Map<Character, int[]> map = new HashMap<>();
        Set<String> visited = new HashSet<>();
        int[] curr = {0, 0};
        map.put('N', new int[]{0, 1});
        map.put('E', new int[]{1, 0});
        map.put('S', new int[]{0, -1});
        map.put('W', new int[]{-1, 0});
        visited.add("0,0");
        for (char c : path.toCharArray()) {
            int[] move = map.get(c);
            curr[0] += move[0];
            curr[1] += move[1];
            if (visited.contains(curr[0] + "," + curr[1])) {
                return true;
            }
            else {
                visited.add(curr[0] + "," + curr[1]);
            }
        }
        return false;
    }
}
