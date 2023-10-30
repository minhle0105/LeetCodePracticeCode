package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode();
        ListNode curr = result;
        ListNode c1 = l1;
        ListNode c2 = l2;
        int carry = 0;
        while (c1 != null || c2 != null) {
            int v1 = c1 == null ? 0 : c1.val;
            int v2 = c2 == null ? 0 : c2.val;
            int val = v1 + v2 + carry;
            carry = val >= 10 ? 1 : 0;
            val %= 10;
            curr.next = new ListNode(val);
            curr = curr.next;
            if (c1.next == null && c2.next == null) {
                if (carry > 0) {
                    curr.next = new ListNode(1);
                }
                break;
            }
            c1 = c1.next == null ? new ListNode(0) : c1.next;
            c2 = c2.next == null ? new ListNode(0) : c2.next;
        }
        return result.next;
    }

    @Test
    void firstTest() {
        ListNode l1 = new ListNode(2,new ListNode(4, new ListNode(3)));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
        ListNode expected = new ListNode(7, new ListNode(0, new ListNode(8)));
        ListNode actual = addTwoNumbers(l1, l2);
        ListNode c1 = expected;
        ListNode c2 = actual;
        boolean isTrue = true;
        while (c1 != null && c2 != null) {
            if (c1.val != c2.val) {
                isTrue = false;
                break;
            }
            c1 = c1.next;
            c2 = c2.next;
        }
        Assertions.assertTrue(isTrue);
    }

    @Test
    void secondTest() {
        ListNode l1 = new ListNode(8);
        ListNode l2 = new ListNode(5);
        ListNode expected = new ListNode(3, new ListNode(1));
        ListNode actual = addTwoNumbers(l1, l2);
        ListNode c1 = expected;
        ListNode c2 = actual;
        boolean isTrue = true;
        while (c1 != null && c2 != null) {
            if (c1.val != c2.val) {
                isTrue = false;
                break;
            }
            c1 = c1.next;
            c2 = c2.next;
        }
        Assertions.assertTrue(isTrue);
    }

    @Test
    void lastTest() {
        ListNode l1 = new ListNode(8, new ListNode(8));
        ListNode l2 = new ListNode(5, new ListNode(5));
        ListNode expected = new ListNode(3, new ListNode(4, new ListNode(1)));
        ListNode actual = addTwoNumbers(l1, l2);
        ListNode c1 = expected;
        ListNode c2 = actual;
        boolean isTrue = true;
        while (c1 != null && c2 != null) {
            if (c1.val != c2.val) {
                isTrue = false;
                break;
            }
            c1 = c1.next;
            c2 = c2.next;
        }
        Assertions.assertTrue(isTrue);
    }

    @Test
    void failTest() {
        ListNode l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
        ListNode l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
        ListNode expected = new ListNode(8, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(1))))))));
        ListNode actual = addTwoNumbers(l1, l2);
        ListNode c1 = expected;
        ListNode c2 = actual;
        boolean isTrue = true;
        while (c1 != null && c2 != null) {
            if (c1.val != c2.val) {
                isTrue = false;
                break;
            }
            c1 = c1.next;
            c2 = c2.next;
        }
        Assertions.assertTrue(isTrue);
    }
}
