/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
        if (head == null)
        {
            return head;
        }
        Stack<Node> stack = new Stack<>();
        Set<Node> visited = new HashSet<>();
        List<Integer> dfs_results = new ArrayList<>();
        stack.push(head);
        visited.add(head);
        while (!stack.isEmpty())
        {
            Node curr = stack.pop();
            if (curr == null)
            {
                break;
            }
            dfs_results.add(curr.val);
            if (curr.next != null)
            {
                if (!visited.contains(curr.next))
                {
                    stack.push(curr.next);
                    visited.add(curr.next);
                }
            }

            if (curr.child != null)
            {
                if (!visited.contains(curr.child))
                {
                    stack.push(curr.child);
                    visited.add(curr.child);
                }
            }

        }
        return convert(dfs_results);
    }

    private Node convert(List<Integer> vals)
    {
        Node dummy_head = new Node();
        Node curr = dummy_head;
        for (Integer val : vals)
        {
            int curr_node = curr.val;
            Node next = new Node();
            next.val = val;
            curr.next = next;
            next.prev = curr;
            curr.child = null;
            next.child = null;
            curr = curr.next;
        }
        curr = dummy_head.next;
        int curr_val = curr.val;
        curr.prev = null;
        return curr;
    }
}
