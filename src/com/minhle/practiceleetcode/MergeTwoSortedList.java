package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

public class MergeTwoSortedList {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode tempHead = new ListNode();
        ListNode curr = tempHead;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                curr.next = l1;
                l1 = l1.next;
            } else {
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }
        if (l1 != null) {
            curr.next = l1;
        }
        if (l2 != null) {
            curr.next = l2;
        }
        return tempHead.next;
    }

    @Test
    void firstTest() {
        // 1 1 2 3 4 4
        ListNode expected = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(4))))));
        ListNode l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode actual = mergeTwoLists(l1, l2);
        ArrayList<Integer> expectedArr = new ArrayList<>();
        ListNode curr = expected;
        while (curr.next != null) {
            expectedArr.add(curr.val);
            curr = curr.next;
        }
        ArrayList<Integer> actualArr = new ArrayList<>();
        curr = actual;
        while(curr.next != null) {
            actualArr.add(curr.val);
            curr = curr.next;
        }
        Assertions.assertEquals(expectedArr, actualArr);
    }
}
