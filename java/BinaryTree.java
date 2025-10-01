import java.util.*;

/**
 * BinaryTree class: Implements generic Binary Tree operations, including
 * standard traversals and utility methods for computing different tree views.
 */
public class BinaryTree {

    // --- 1. Standard Tree Node Definition ---
    public static class Node {
        int data;
        Node left;
        Node right;

        public Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    // Root of the tree
    public Node root;

    public BinaryTree() {
        this.root = null;
    }

    // --- 2. Traversal Methods ---

    public void inorder(Node node) {
        if (node != null) {
            inorder(node.left);
            System.out.print(node.data + " ");
            inorder(node.right);
        }
    }

    public void preorder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preorder(node.left);
            preorder(node.right);
        }
    }

    public void postorder(Node node) {
        if (node != null) {
            postorder(node.left);
            postorder(node.right);
            System.out.print(node.data + " ");
        }
    }

    // --- 3. View Methods (Utility) ---

    // Top View: Nodes visible when looking from the top (first node encountered at each Horizontal Distance)
    public List<Integer> topView() {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        // Map stores <Horizontal Distance, Node Data>
        Map<Integer, Integer> map = new TreeMap<>();
        // Queue stores <Node, Horizontal Distance>
        Queue<Pair<Node, Integer>> queue = new LinkedList<>();

        queue.add(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<Node, Integer> current = queue.poll();
            Node node = current.key;
            int hd = current.value;

            // Only update if this HD is encountered for the first time (this is the 'top' node)
            if (!map.containsKey(hd)) {
                map.put(hd, node.data);
            }

            if (node.left != null) {
                queue.add(new Pair<>(node.left, hd - 1));
            }
            if (node.right != null) {
                queue.add(new Pair<>(node.right, hd + 1));
            }
        }
        
        // Add all values from the sorted map (TreeMap ensures HD is sorted) to the result list
        result.addAll(map.values());
        return result;
    }

    // Bottom View: Nodes visible when looking from the bottom (last node encountered at each Horizontal Distance)
    public List<Integer> bottomView() {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        // Map stores <Horizontal Distance, Node Data>
        Map<Integer, Integer> map = new TreeMap<>();
        // Queue stores <Node, Horizontal Distance>
        Queue<Pair<Node, Integer>> queue = new LinkedList<>();

        queue.add(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<Node, Integer> current = queue.poll();
            Node node = current.key;
            int hd = current.value;

            // Always update the map. The last node processed for a given HD in BFS 
            // will be the lowest/closest to the bottom at that HD.
            map.put(hd, node.data);

            if (node.left != null) {
                queue.add(new Pair<>(node.left, hd - 1));
            }
            if (node.right != null) {
                queue.add(new Pair<>(node.right, hd + 1));
            }
        }

        result.addAll(map.values());
        return result;
    }
    
    // Left View: The first node of every level
    public List<Integer> leftView() {
        List<Integer> result = new ArrayList<>();
        leftView(root, 1, new int[]{0}, result);
        return result;
    }

    // Recursive helper for Left View
    private void leftView(Node node, int level, int[] maxLevel, List<Integer> result) {
        if (node == null) return;

        // If this is the first node at the current level, add it to the view
        if (maxLevel[0] < level) {
            result.add(node.data);
            maxLevel[0] = level;
        }

        // Recurse left first to ensure the leftmost node is processed first
        leftView(node.left, level + 1, maxLevel, result);
        leftView(node.right, level + 1, maxLevel, result);
    }

    // Right View: The last node of every level
    public List<Integer> rightView() {
        List<Integer> result = new ArrayList<>();
        rightView(root, 1, new int[]{0}, result);
        return result;
    }
    
    // Recursive helper for Right View
    private void rightView(Node node, int level, int[] maxLevel, List<Integer> result) {
        if (node == null) return;

        // If this is the first node at the current level, add it to the view
        if (maxLevel[0] < level) {
            result.add(node.data);
            maxLevel[0] = level;
        }

        // Recurse right first to ensure the rightmost node is processed first
        rightView(node.right, level + 1, maxLevel, result);
        rightView(node.left, level + 1, maxLevel, result);
    }

    // Helper class for combining Node and Horizontal Distance in the Queue (for Top/Bottom View)
    private static class Pair<K, V> {
        K key;
        V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
}
