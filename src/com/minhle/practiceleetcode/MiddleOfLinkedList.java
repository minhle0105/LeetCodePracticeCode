package com.minhle.practiceleetcode;

public class MiddleOfLinkedList {
    public ListNode middleNode(ListNode head) {
        ListNode slowPointer = head;
        ListNode fastPointer = head;
        while (fastPointer.next != null) {
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next.next;
            if (fastPointer == null) {
                return slowPointer;
            }
        }
        return slowPointer;
    }
}
