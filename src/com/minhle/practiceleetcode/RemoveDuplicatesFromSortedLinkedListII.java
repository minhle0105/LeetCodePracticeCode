package com.minhle.practiceleetcode;

import java.util.LinkedHashMap;
import java.util.Map;

public class RemoveDuplicatesFromSortedLinkedListII {
    public ListNode deleteDuplicates(ListNode head) {
        Map<Integer, Integer> map = new LinkedHashMap<>();
        ListNode curr = head;
        while (curr != null) {
            if (map.containsKey(curr.val)) {
                map.put(curr.val, map.get(curr.val) + 1);
            }
            else {
                map.put(curr.val, 1);
            }
            curr = curr.next;
        }
        ListNode newHead = new ListNode();
        curr = newHead;
        for (Integer key : map.keySet()) {
            if (map.get(key) == 1) {
                curr.next = new ListNode(key);
                curr = curr.next;
            }
        }
        return newHead.next;
    }
}
