package com.minhle.practiceleetcode;

import java.util.*;

public class MergeKSortedList
{
    static class ListNode
    {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (ListNode node : lists)
        {
            ListNode curr = node;
            while (curr != null)
            {
                heap.add(curr.val);
                curr = curr.next;
            }
        }
        ListNode dummy_head = new ListNode(-1);
        ListNode curr = dummy_head;
        while (!heap.isEmpty())
        {
            curr.next = new ListNode(heap.remove());
            curr = curr.next;
        }
        return dummy_head.next;
    }
}
