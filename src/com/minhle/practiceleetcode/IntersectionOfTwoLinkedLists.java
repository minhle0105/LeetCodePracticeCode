package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.HashSet;

public class IntersectionOfTwoLinkedLists {

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == headB) {
            return headA;
        }
        HashSet<ListNode> hashSet = new HashSet<>();
        ListNode curr = headB;
        while (curr != null) {
            hashSet.add(curr);
            curr = curr.next;
        }
        curr = headA;
        while (curr != null) {
            if (hashSet.contains(curr)) {
                return curr;
            }
            curr = curr.next;
        }
        return null;
    }

    @Test
    void firstTest() {
        ListNode intersection = new ListNode(8, new ListNode(4, new ListNode(5)));
        ListNode l1 = new ListNode(4, new ListNode(1, intersection));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(1, intersection)));
        ListNode actual = getIntersectionNode(l1, l2);
        Assertions.assertTrue(intersection.compareTo(actual));
    }

    @Test
    void secondTest() {
        ListNode intersection = new ListNode(2, new ListNode(4));
        ListNode l1 = new ListNode(1, new ListNode(9, new ListNode(1, intersection)));
        ListNode l2 = new ListNode(3, intersection);
        ListNode actual = getIntersectionNode(l1, l2);
        Assertions.assertTrue(intersection.compareTo(actual));
    }

    @Test
    void nullTest() {
        ListNode l1 = new ListNode(2, new ListNode(6, new ListNode(4)));
        ListNode l2 = new ListNode(1, new ListNode(5));
        ListNode actual = getIntersectionNode(l1, l2);
        Assertions.assertNull(actual);
    }

    @Test
    void failedTest1() {
        ListNode intersection = new ListNode(3);
        ListNode l1 = intersection;
        ListNode l2 = new ListNode(2, intersection);
        ListNode actual = getIntersectionNode(l1, l2);
        Assertions.assertTrue(intersection.compareTo(actual));
    }

    @Test
    void failedTest() {
        ListNode intersection = new ListNode(1);
        ListNode l1 = intersection;
        ListNode l2 = intersection;
        ListNode actual = getIntersectionNode(l1, l2);
        Assertions.assertTrue(intersection.compareTo(actual));
    }
}
