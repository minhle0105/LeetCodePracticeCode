import java.util.*;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
    public Node connect(Node root) {
        if (root == null) 
        {
            return null;
        }
        Queue<Node> queue = new LinkedList<>();
        Map<Node, Integer> levels = new LinkedHashMap<>();
        Map<Integer, List<Node>> nodesEachLevel = new TreeMap<>();
        Set<Node> visited = new HashSet<>();

        levels.put(root, 1);
        queue.add(root);
        visited.add(root);

        while (!queue.isEmpty()) 
        {
            Node curr = queue.remove();
            int currLevel = levels.get(curr);

            if (curr.left != null && !visited.contains(curr.left)) 
            {
                visited.add(curr.left);
                queue.add(curr.left);
                levels.put(curr.left, currLevel + 1);
                if (!nodesEachLevel.containsKey(currLevel + 1))
                {
                    nodesEachLevel.put(currLevel + 1, new ArrayList<>());
                }
                nodesEachLevel.get(currLevel + 1).add(curr.left);
            }

            if (curr.right != null && !visited.contains(curr.right)) 
            {
                visited.add(curr.right);
                queue.add(curr.right);
                levels.put(curr.right, currLevel + 1);
                if (!nodesEachLevel.containsKey(currLevel + 1))
                {
                    nodesEachLevel.put(currLevel + 1, new ArrayList<>());
                }
                nodesEachLevel.get(currLevel + 1).add(curr.right);
            }
        }

        for (List<Node> nodeList : nodesEachLevel.values()) 
        {
            for (int i = 0; i < nodeList.size() - 1; i++) 
            {
                nodeList.get(i).next = nodeList.get(i + 1);
            }
            nodeList.get(nodeList.size() - 1).next = null;
        }
        return root;
    }
}
