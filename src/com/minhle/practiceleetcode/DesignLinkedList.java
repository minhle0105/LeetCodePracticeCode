package com.minhle.practiceleetcode;

public class DesignLinkedList {
    static class MyLinkedList {

        Node head;
        int size;

        public MyLinkedList() {
            head = new Node(0);
            this.size = 0;
        }

        public int get(int index) {
            if (index < 0 | index >= size) return -1;
            int count = 0;
            Node curr = head;
            while (count < index + 1) {
                curr = curr.next;
                count++;
            }
            return curr.val;
        }

        public void addAtHead(int val) {
            addAtIndex(0, val);
        }

        public void addAtTail(int val) {
            addAtIndex(size, val);
        }

        public void addAtIndex(int index, int val) {
            if (index > size) return;

            Node curr = head;
            int count = 0;
            Node newNode = new Node(val);
            while (count < index) {
                curr = curr.next;
                count++;
            }
            newNode.setNextNode(curr.next);
            curr.setNextNode(newNode);
            size++;
        }

        public void printList() {
            Node curr = head;
            StringBuilder output = new StringBuilder();
            while (curr != null) {
                output.append(curr.val).append("->");
                curr = curr.next;
            }
            System.out.print(output.substring(0, output.length() - 2));
            System.out.println();
        }

        public void deleteAtIndex(int index) {
            if (index < 0 || index >= size) return;
            Node curr = head;
            int count = 0;
            while (count < index) {
                curr = curr.next;
                count++;
            }
            curr.next = curr.next.next;
            size--;
        }
    }

    static class Node {
        int val;
        Node next;

        public Node() {
            this.next = null;
        }

        public Node (int val) {
            this.val = val;
            this.next = null;
        }

        public void setNextNode(Node nextNode) {
            this.next = nextNode;
        }
    }
}

