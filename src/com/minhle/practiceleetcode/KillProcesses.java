package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class KillProcesses {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (Integer id : ppid) {
            map.put(id, new ArrayList<>());
        }
        for (int i = 0; i < pid.size(); i++) {
            map.get(ppid.get(i)).add(pid.get(i));
        }
        List<Integer> killedProcesses = new ArrayList<>();
        killedProcesses.add(kill);
        addToList(map, killedProcesses, kill);
        return killedProcesses;
    }

    private void addToList(Map<Integer, List<Integer>> map, List<Integer> list, int id) {
        if (!map.containsKey(id)) {
            return;
        }
        List<Integer> children = map.get(id);
        for (Integer child : children) {
            list.add(child);
            addToList(map, list, child);
        }
    }
}
