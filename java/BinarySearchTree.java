/**
 * Implements a Binary Search Tree (BST) with insertion, deletion, and traversal operations.
 * It inherits properties from the BinaryTree class.
 */
public class BinarySearchTree extends BinaryTree {

    /**
     * Inserts a new key into the BST.
     * @param key The data to insert.
     */
    public void insert(int key) {
        root = insertRec(root, key);
    }

    /**
     * A recursive utility function to insert a new key in the BST.
     * @param root The current root of the subtree.
     * @param key The data to insert.
     * @return The node pointer (after insertion).
     */
    private Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.data) {
            root.left = insertRec(root.left, key);
        } else if (key > root.data) {
            root.right = insertRec(root.right, key);
        }
        return root;
    }

    /**
     * Deletes a key from the BST.
     * @param key The data to delete.
     */
    public void delete(int key) {
        root = deleteRec(root, key);
    }

    /**
     * A recursive utility function to delete a key from the BST.
     * @param root The current root of the subtree.
     * @param key The data to delete.
     * @return The root of the modified subtree.
     */
    private Node deleteRec(Node root, int key) {
        if (root == null) {
            return root;
        }

        if (key < root.data) {
            root.left = deleteRec(root.left, key);
        } else if (key > root.data) {
            root.right = deleteRec(root.right, key);
        } else {
            // Node with only one child or no child
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            root.data = minValue(root.right);

            // Delete the inorder successor
            root.right = deleteRec(root.right, root.data);
        }

        return root;
    }

    /**
     * Finds the minimum value in a given subtree.
     * @param root The root of the subtree.
     * @return The minimum value.
     */
    private int minValue(Node root) {
        int minv = root.data;
        while (root.left != null) {
            minv = root.left.data;
            root = root.left;
        }
        return minv;
    }
}
