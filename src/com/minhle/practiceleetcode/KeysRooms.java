package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class KeysRooms {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Stack<Integer> stack = new Stack<>();
        stack.add(0);
        List<Integer> visited = new ArrayList<>();
        for (int i = 0; i < rooms.size(); i++) {
            visited.add(0);
        }
        while (!stack.isEmpty()) {
            int currentRoom = stack.pop();
            List<Integer> keysInThisRoom = rooms.get(currentRoom);
            for (Integer key : keysInThisRoom) {
                if (visited.get(key) == 0) {
                    stack.push(key);
                    visited.set(key, 1);
                }
            }
        }
        for (Integer i : visited) {
            if (i == 0) {
                return false;
            }
        }
        return true;
    }
}
