package com.minhle.practiceleetcode;

import java.util.PriorityQueue;

public class SortList {
    public ListNode sortList(ListNode head) {
        if (head == null) {
            return null;
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        ListNode curr = head;
        while (curr != null) {
            heap.add(curr.val);
            curr = curr.next;
        }
        ListNode result = new ListNode();
        ListNode n = new ListNode(heap.remove());
        result.next = n;
        while (!heap.isEmpty()) {
            n.next = new ListNode(heap.remove());
            n = n.next;
        }
        return result.next;
    }
}
