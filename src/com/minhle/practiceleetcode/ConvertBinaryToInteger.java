package com.minhle.practiceleetcode;


import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class ConvertBinaryToInteger {

    private static int getLength(ListNode head) {
        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            length++;
            curr = curr.next;
        }
        return length;
    }

    public int getDecimalValue(ListNode head) {
        int result = 0;
        int length = getLength(head);
        int power = length - 1;
        ListNode curr = head;
        int count = 0;
        while (count < length) {
            if (curr.val == 1) {
                result += 1 * Math.pow(2, power);
                power--;
            }
            else if (curr.val == 0) {
                result += 0 * Math.pow(2, power);
                power--;
            }
            curr = curr.next;
            count++;
        }
        return result;
    }

    @Test
    void testGetLength() {
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        int expected = 4;
        int actual = getLength(head);
        Assertions.assertEquals(expected, actual);
    }

    @Test
    void testGetDecimal() {
        ListNode head = new ListNode(1, new ListNode(0, new ListNode(1)));
        int expected = 5;
        int actual = getDecimalValue(head);
        Assertions.assertEquals(expected, actual);
    }
}
