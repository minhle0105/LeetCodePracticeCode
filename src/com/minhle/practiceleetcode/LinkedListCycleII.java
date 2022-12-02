package com.minhle.practiceleetcode;

import java.util.HashSet;
import java.util.Set;

public class LinkedListCycleII {
    ListNode cycleStart;
    public ListNode detectCycle(ListNode head) {
        findCycleStart(head);
        return cycleStart;
    }

    private void findCycleStart(ListNode head) {
        Set<ListNode> set = new HashSet<>();
        ListNode curr = head;
        while (curr != null) {
            if (set.contains(curr)) {
                cycleStart = curr;
                return;
            }
            set.add(curr);
            curr = curr.next;
        }
    }
}
