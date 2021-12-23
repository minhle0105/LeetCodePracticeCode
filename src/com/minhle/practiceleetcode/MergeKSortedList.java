package com.minhle.practiceleetcode;

import java.util.*;

public class MergeKSortedList {
    public ListNode mergeKLists(ListNode[] lists) {
        List<Integer> nodeToStr = new ArrayList<>();
        for (ListNode node : lists) {
            ListNode currNode = node;
            while (currNode != null) {
                nodeToStr.add(currNode.val);
                currNode = currNode.next;
            }
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>(nodeToStr);
        ListNode result = new ListNode();
        ListNode curr = result;
        while (!heap.isEmpty()) {
            curr.next = new ListNode(heap.remove());
            curr = curr.next;
        }
        return result.next;
    }
}
