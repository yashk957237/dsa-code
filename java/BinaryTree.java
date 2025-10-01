import java.util.*;

/**
 * Represents a single node in a binary tree.
 */
class Node {
    int data;
    Node left;
    Node right;

    /**
     * Constructor to create a new node.
     * @param data The data to be stored in the node.
     */
    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

/**
 * Implements a Binary Tree and includes methods for traversal and different views.
 */
public class BinaryTree {
    Node root;

    public BinaryTree() {
        root = null;
    }

    /**
     * Performs an in-order traversal of the binary tree.
     * @param node The current node in the traversal.
     */
    public void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.data + " ");
            inOrder(node.right);
        }
    }

    /**
     * Performs a pre-order traversal of the binary tree.
     * @param node The current node in the traversal.
     */
    public void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    /**
     * Performs a post-order traversal of the binary tree.
     * @param node The current node in the traversal.
     */
    public void postOrder(Node node) {
        if (node != null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.print(node.data + " ");
        }
    }

    /**
     * Computes and prints the top view of the binary tree.
     * The top view consists of the nodes that are visible from the top.
     */
    public void topView() {
        if (root == null) {
            return;
        }

        class QueueObj {
            Node node;
            int hd; // Horizontal Distance

            QueueObj(Node node, int hd) {
                this.node = node;
                this.hd = hd;
            }
        }

        Queue<QueueObj> q = new LinkedList<>();
        Map<Integer, Node> topViewMap = new TreeMap<>();

        q.add(new QueueObj(root, 0));

        while (!q.isEmpty()) {
            QueueObj tmpNode = q.poll();
            if (!topViewMap.containsKey(tmpNode.hd)) {
                topViewMap.put(tmpNode.hd, tmpNode.node);
            }

            if (tmpNode.node.left != null) {
                q.add(new QueueObj(tmpNode.node.left, tmpNode.hd - 1));
            }
            if (tmpNode.node.right != null) {
                q.add(new QueueObj(tmpNode.node.right, tmpNode.hd + 1));
            }
        }
        System.out.println("Top View:");
        for (Map.Entry<Integer, Node> entry : topViewMap.entrySet()) {
            System.out.print(entry.getValue().data + " ");
        }
        System.out.println();
    }

    /**
     * Computes and prints the bottom view of the binary tree.
     * The bottom view consists of the nodes that are visible from the bottom.
     */
    public void bottomView() {
        if (root == null) {
            return;
        }

        class QueueObj {
            Node node;
            int hd; // Horizontal Distance

            QueueObj(Node node, int hd) {
                this.node = node;
                this.hd = hd;
            }
        }

        Queue<QueueObj> q = new LinkedList<>();
        Map<Integer, Node> bottomViewMap = new TreeMap<>();

        q.add(new QueueObj(root, 0));

        while (!q.isEmpty()) {
            QueueObj tmpNode = q.poll();
            bottomViewMap.put(tmpNode.hd, tmpNode.node);

            if (tmpNode.node.left != null) {
                q.add(new QueueObj(tmpNode.node.left, tmpNode.hd - 1));
            }
            if (tmpNode.node.right != null) {
                q.add(new QueueObj(tmpNode.node.right, tmpNode.hd + 1));
            }
        }
        System.out.println("Bottom View:");
        for (Map.Entry<Integer, Node> entry : bottomViewMap.entrySet()) {
            System.out.print(entry.getValue().data + " ");
        }
        System.out.println();
    }

    /**
     * Computes and prints the left view of the binary tree.
     * The left view consists of the first node at each level.
     */
    public void leftView() {
        if (root == null) {
            return;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        System.out.println("Left View:");
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 1; i <= n; i++) {
                Node temp = queue.poll();
                if (i == 1) {
                    System.out.print(temp.data + " ");
                }
                if (temp.left != null) {
                    queue.add(temp.left);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                }
            }
        }
        System.out.println();
    }

    /**
     * Computes and prints the right view of the binary tree.
     * The right view consists of the last node at each level.
     */
    public void rightView() {
        if (root == null) {
            return;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        System.out.println("Right View:");
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 1; i <= n; i++) {
                Node temp = queue.poll();
                if (i == n) {
                    System.out.print(temp.data + " ");
                }
                if (temp.left != null) {
                    queue.add(temp.left);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                }
            }
        }
        System.out.println();
    }
}
